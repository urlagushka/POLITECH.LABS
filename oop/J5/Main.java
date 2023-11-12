import StreamAPI.*;

import java.util.Arrays;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        List<Integer> integers = Arrays.asList(1, 2, 3, 4, 5, -1, -2, -3, -4, -5, 6, 6, 6);
        List<String> strings = Arrays.asList("one", "tho", "cat", "dog", "api", "src");

        System.out.println(EvenSum.process(integers));
        System.out.println(GetAverage.process(integers));
        System.out.println(GetLast.process(integers));
        System.out.println(NewPrefix.process(strings));
        System.out.println(SortAlphabet.process(strings, 't'));
        System.out.println(ToMap.process(strings));
        System.out.println(ToSquare.process(integers));
    }
}
