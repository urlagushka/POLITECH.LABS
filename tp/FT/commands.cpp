#include "commands.hpp"

#include <stdexcept>
#include <fstream>

#include "data-types.hpp"
#include "huffman-code.hpp"

namespace
{
  using namespace turkin;

  std::ostream & get_phrase_func(PType & lhs, PType & rhs, std::ostream & out)
  {
    out << "encoding for phrase: ";
    out << lhs.get_phrase() << " | ";
    out << encode(lhs.get_phrase(), rhs.get_encoding_map());
    return out;
  }

  std::ostream & info_phrase_func(PType & lhs, PType & rhs, std::ostream & out)
  {
    out << lhs.get_phrase() << " ";
    out << encode(lhs.get_phrase(), rhs.get_encoding_map()) << "\n";
    out << rhs.get_encoding_map() << "\n";
    out << "a_w: " << lhs.get_encoding().size() << "\n";
    out << "b_w: " << encode(lhs.get_phrase(), rhs.get_encoding_map()).size();
    return out;
  }

  std::ostream & info_state_func(PType & lhs, PType & rhs, std::ostream & out)
  {
    encoding_t lhs_lhs_encoding = encode(lhs.get_phrase(), lhs.get_encoding_map());
    encoding_t lhs_rhs_encoding = encode(lhs.get_phrase(), rhs.get_encoding_map());
    encoding_t rhs_rhs_encoding = encode(rhs.get_phrase(), rhs.get_encoding_map());
    encoding_t rhs_lhs_encoding = encode(rhs.get_phrase(), lhs.get_encoding_map());
    out << lhs.get_phrase() << "\n";
    out << lhs_lhs_encoding << "\n";
    out << lhs_rhs_encoding << "\n";
    out << "difference: " << lhs_lhs_encoding.size() - lhs_rhs_encoding.size() << "\n";
    out << rhs.get_phrase() << "\n";
    out << rhs_rhs_encoding << "\n";
    out << rhs_lhs_encoding << "\n";
    out << "difference: " << rhs_rhs_encoding.size() - rhs_lhs_encoding.size();
    return out;
  }

  void help_new(std::ostream & out)
  {
    out << "NEW-PHRASE <phrase> - добавляет новую фразу\n";
    out << "NEW-ENCODING <phrase> - добавляет кодировку для фразы\n";
    out << "NEW-MERGE <lhs> <rhs> - соединяет две существуетвующие фразы в одну через пробел";
  }

  void help_get(std::ostream & out)
  {
    out << "GET-PHRASE <lhs> <rhs> - выводит фразу lhs";
    out << "и ее закодированный вид, используя кодировку rhs\n";
    out << "GET-ENCODING <phrase> - выводит коды символов для фразы\n";
    out << "GET-FULL <rhs> <rhs> - выполняет GET PHRASE и GET ENCODING для rhs по фразе lhs";
  }

  void help_del(std::ostream & out)
  {
    out << "DEL-PHRASE <phrase> - удаляет фразу\n";
    out << "DEL-ENCODING <phrase> - удаляет кодировку фразы";
  }

  void help_re(std::ostream & out)
  {
    out << "RE-ENCODING <lhs> <rhs> - выводит закодированную фразу lhs, используя кодировку rhs";
  }

  void help_info(std::ostream & out)
  {
    out << "INFO-PHRASE <lhs> <rhs> - выводит фразу lhs, кодировку rhs,";
    out << "частоту символов lhs, коды символов rhs, вес до кодировки и после\n";
    out << "INFO-STATE <lhs> <rhs> - выводит фразы lhs rhs, их кодировки";
    out << "(lhs - lhs, lhs - rhs, rhs - rhs, rhs - lhs) и разницу в весе\n";
    out << "INFO-ALGORITHM - выводит информацию об алгоритме сжатия";
  }

  void help_save(std::ostream & out)
  {
    out << "SAVE-PHRASE <lhs> <rhs> <file> - сохраняет вывод INFO PHRASE для фразы в файл\n";
    out << "SAVE-FULL <file> - сохраняет вывод INFO PHRASE";
    out << "для всех фраз в файл, используя кодировки lhs - lhs";
  }

  std::map< std::string, void (*)(std::ostream &) > get_help_dict()
  {
    std::map< std::string, void (*)(std::ostream &) > result;
    result.insert({"NEW", help_new});
    result.insert({"GET", help_get});
    result.insert({"DEL", help_del});
    result.insert({"RE", help_re});
    result.insert({"INFO", help_info});
    result.insert({"SAVE", help_save});
    return result;
  }
}

std::ostream & turkin::new_phrase(pdt & p_dict, edt &, std::istream & in, std::ostream & out)
{
  phrase_t phrase = "";
  in >> phrase;
  PType p_new(phrase);
  p_dict.insert({phrase, p_new});
  return out << "added phrase: " << phrase;
}

std::ostream & turkin::new_encoding(pdt & p_dict, edt & e_dict, std::istream & in, std::ostream & out)
{
  phrase_t phrase = "";
  in >> phrase;
  PType & ptype = p_dict.at(phrase);
  HType e_new(phrase);
  ptype.set_encoding(encode(ptype.get_phrase(), e_new.get_encoding_map()));
  ptype.set_encoding_map(e_new.get_encoding_map());
  e_dict.insert({phrase, e_new});
  return out << "added encoding for phrase: " << ptype.get_phrase() << " | " << ptype.get_encoding();
}

std::ostream & turkin::new_merge(pdt & p_dict, edt &, std::istream & in, std::ostream & out)
{
  phrase_t phrase_a = "";
  phrase_t phrase_b = "";
  in >> phrase_a >> phrase_b;
  p_dict.at(phrase_a);
  p_dict.at(phrase_b);
  phrase_t phrase = phrase_a + " " + phrase_b;
  PType p_new(phrase);
  p_dict.insert({phrase, p_new});
  return out << "added phrase: " << phrase;
}

std::ostream & turkin::get_phrase(pdt & p_dict, edt &, std::istream & in, std::ostream & out)
{
  phrase_t phrase_a = "";
  phrase_t phrase_b = "";
  in >> phrase_a >> phrase_b;
  PType & lhs = p_dict.at(phrase_a);
  PType & rhs = p_dict.at(phrase_b);
  return get_phrase_func(lhs, rhs, out);
}

std::ostream & turkin::get_encoding(pdt &, edt & e_dict, std::istream & in, std::ostream & out)
{
  phrase_t phrase = "";
  in >> phrase;
  return out << e_dict.at(phrase).get_encoding_map();
}

std::ostream & turkin::get_full(pdt & p_dict, edt & e_dict, std::istream & in, std::ostream & out)
{
  phrase_t phrase_a = "";
  phrase_t phrase_b = "";
  in >> phrase_a >> phrase_b;
  PType & lhs = p_dict.at(phrase_a);
  PType & rhs = p_dict.at(phrase_b);
  return get_phrase_func(lhs, rhs, out) << e_dict.at(phrase_b).get_encoding_map();
}

std::ostream & turkin::del_phrase(pdt & p_dict, edt &, std::istream & in, std::ostream & out)
{
  std::string phrase = "";
  in >> phrase;
  p_dict.erase(phrase);
  return out << "deleted: " << phrase;
}

std::ostream & turkin::del_encoding(pdt & p_dict, edt & e_dict, std::istream & in, std::ostream & out)
{
  std::string phrase = "";
  in >> phrase;
  e_dict.erase(phrase);
  p_dict.at(phrase).set_encoding(encoding_t());
  p_dict.at(phrase).set_encoding_map(encoding_map_t());
  return out << "deleted: " << phrase;
}

std::ostream & turkin::re_encoding(pdt & p_dict, edt &, std::istream & in, std::ostream & out)
{
  phrase_t phrase_a = "";
  phrase_t phrase_b = "";
  in >> phrase_a >> phrase_b;
  PType & ptype_a = p_dict.at(phrase_a);
  PType & ptype_b = p_dict.at(phrase_b);
  return out << encode(ptype_a.get_phrase(), ptype_b.get_encoding_map());
}

std::ostream & turkin::info_phrase(pdt & p_dict, edt &, std::istream & in, std::ostream & out)
{
  phrase_t phrase_a = "";
  phrase_t phrase_b = "";
  in >> phrase_a >> phrase_b;
  PType & lhs = p_dict.at(phrase_a);
  PType & rhs = p_dict.at(phrase_b);
  return info_phrase_func(lhs, rhs, out);
}

std::ostream & turkin::info_state(pdt & p_dict, edt &, std::istream & in, std::ostream & out)
{
  phrase_t phrase_a = "";
  phrase_t phrase_b = "";
  in >> phrase_a >> phrase_b;
  PType & lhs = p_dict.at(phrase_a);
  PType & rhs = p_dict.at(phrase_b);
  return info_state_func(lhs, rhs, out);
}

std::ostream & turkin::info_algorithm(pdt &, edt &, std::istream &, std::ostream & out)
{
  return out << "https://en.wikipedia.org/wiki/Huffman_coding";
}

std::ostream & turkin::save_phrase(pdt & p_dict, edt &, std::istream & in, std::ostream & out)
{
  phrase_t phrase_a = "";
  phrase_t phrase_b = "";
  std::string path = "";
  in >> phrase_a >> phrase_b >> path;
  std::fstream file(path);
  if (!file.is_open())
  {
    throw std::runtime_error("bad file name");
  }
  PType & lhs = p_dict.at(phrase_a);
  PType & rhs = p_dict.at(phrase_b);
  info_phrase_func(lhs, rhs, file);
  return out;
}

std::ostream & turkin::save_full(pdt & p_dict, edt &, std::istream & in, std::ostream & out)
{
  phrase_t phrase_a = "";
  phrase_t phrase_b = "";
  std::string path = "";
  in >> phrase_a >> phrase_b >> path;
  std::fstream file(path);
  if (!file.is_open())
  {
    throw std::runtime_error("bad file name");
  }
  for (std::pair< const phrase_t, PType > & p: p_dict)
  {
    info_phrase_func(p.second, p.second, file) << "\n\n";
  }
  return out;
}

std::ostream & turkin::help(pdt &, edt &, std::istream & in, std::ostream & out)
{
  std::string type = "";
  in >> type;
  std::map< std::string, void (*)(std::ostream &) > dict = get_help_dict();
  dict.at(type)(out);
  return out;
}
