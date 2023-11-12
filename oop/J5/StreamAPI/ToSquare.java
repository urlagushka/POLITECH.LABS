package StreamAPI;

import org.jetbrains.annotations.NotNull;

import java.util.List;

public class ToSquare {
    public static List<Integer> process(@NotNull List<Integer> list) {
        return list.stream().distinct().map(ToSquare::operator).toList();
    }

    private static int operator(int src) {
        return src * src;
    }
}
