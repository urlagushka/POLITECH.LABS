package Dictionary;

import TFileReader.*;

import java.io.File;

public class DictionaryWork {
    public static Dictionary complete(File file) throws FileReadException, InvalidFileFormatException {
        Dictionary temp = new Dictionary();
        TFileReader reader = new TFileReader(file);

        while (!reader.empty()) {
            temp.insert(reader.read());
        }

        reader.close();
        return temp;
    }

    public static String translate(Dictionary src, String word) {
        return word + " - " + src.get(word);
    }

    public static String translate(Dictionary src, File file) throws InvalidFileFormatException, FileReadException {
        StringBuilder temp = new StringBuilder();
        TFileReader reader = new TFileReader(file);

        while (!reader.empty()) {
            temp.append(translate(src, reader.read())).append("\n");
        }

        reader.close();
        return temp.toString();
    }
}
