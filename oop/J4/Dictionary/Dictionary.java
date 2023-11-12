package Dictionary;

import java.util.HashMap;

public class Dictionary {
    public Dictionary() {
        this.dictionary = new HashMap<>();
    }

    public void insert(String word, String translation) {
        this.dictionary.put(word.toLowerCase(), translation);
    }

    public void insert(String pair) {
        String[] temp = pair.split("\\|");
        insert(temp[0], temp[1]);
    }

    public String get(String word) {
        return this.dictionary.getOrDefault(word.toLowerCase(), "not found");
    }

    private final HashMap< String, String > dictionary;
}
