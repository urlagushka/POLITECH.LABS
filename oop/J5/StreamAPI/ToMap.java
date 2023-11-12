package StreamAPI;

import org.jetbrains.annotations.NotNull;

import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class ToMap {
    public static Map<Character, String> process(@NotNull List<String> list) {
        return list.stream().collect(Collectors.toMap(ToMap::key, ToMap::value));
    }

    private static char key(String src) {
        return src.charAt(0);
    }

    private static String value(String src) {
        return src.substring(1);
    }
}
