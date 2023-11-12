package StreamAPI;

import org.jetbrains.annotations.NotNull;

import java.util.List;

public class SortAlphabet {
    public static List<String> process(@NotNull List<String> list, char c) {
        return list.stream().filter((i) -> i.charAt(0) == c).sorted(SortAlphabet::comparator).toList();
    }

    private static int comparator(String lhs, String rhs) {
        return CharSequence.compare(lhs, rhs);
    }
}
