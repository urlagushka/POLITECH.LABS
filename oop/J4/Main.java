import Dictionary.*;
import TFileReader.*;

import java.io.File;

public class Main {
    public static void main(String [] args) {
        try {
            File dictionary = new File("dictionary.txt");
            File input = new File("input.txt");

            Dictionary dict = DictionaryWork.complete(dictionary);
            System.out.print(DictionaryWork.translate(dict, input));
        } catch (FileReadException | InvalidFileFormatException e) {
            System.out.println(e.getMessage());
        }
    }
}
