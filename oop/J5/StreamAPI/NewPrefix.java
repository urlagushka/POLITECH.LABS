package StreamAPI;

import org.jetbrains.annotations.NotNull;

import java.util.List;

public class NewPrefix {
    public static List<String> process(@NotNull List<String> list) {
        return list.stream().map(NewPrefix::operator).toList();
    }

    private static String operator(String src) {
        return "_new_" + src.toUpperCase();
    }
}
