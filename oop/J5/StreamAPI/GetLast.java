package StreamAPI;

import org.jetbrains.annotations.NotNull;

import java.util.List;

public class GetLast {
    public static int process(@NotNull List<Integer> list) {
        return list.stream().reduce(GetLast::last).orElseThrow();
    }

    private static int last(int lhs, int rhs) {
        return rhs;
    }
}
