package StreamAPI;

import org.jetbrains.annotations.NotNull;

import java.util.List;

public class GetAverage {
    public static double process(@NotNull List<Integer> list) {
        return list.stream().mapToInt(a -> a).average().orElse(0);
    }
}
