package StreamAPI;

import org.jetbrains.annotations.NotNull;

import java.util.List;

public class EvenSum {
    public static int process(@NotNull List<Integer> list) {
        return list.stream().reduce(0, EvenSum::operator);
    }

    private static int operator(int dest, int src) {
        return (src % 2 == 0) ? dest + src : dest;
    }
}
