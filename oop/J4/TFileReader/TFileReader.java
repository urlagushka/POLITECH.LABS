package TFileReader;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.util.Scanner;

public class TFileReader {
    public TFileReader(File file) throws FileReadException, InvalidFileFormatException {
        try {
            if (!file.getName().endsWith(".txt")) {
                throw new InvalidFileFormatException("file extension doesn't support");
            }
            FileReader fileReader = new FileReader(file);
            this.scanner = new Scanner(fileReader);
        } catch (FileNotFoundException e) {
            throw new FileReadException(e.getMessage());
        } catch (Exception e) {
            throw new InvalidFileFormatException(e.getMessage());
        }
    }

    public String read() {
        return this.scanner.nextLine();
    }

    public boolean empty() {
        return !this.scanner.hasNextLine();
    }

    public void close() {
        this.scanner.close();
    }

    private final Scanner scanner;
}
