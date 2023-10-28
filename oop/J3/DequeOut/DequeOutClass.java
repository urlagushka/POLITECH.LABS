package DequeOut;

import Animals.Chordal;
import java.util.Deque;

public class DequeOutClass {
    public static void process(String name, Deque<? extends Chordal> src) {
        System.out.println(name.toUpperCase());
        if (src.isEmpty()) {
            System.out.print("empty\n\n");
            return;
        }
        for (Chordal chordal: src) {
            System.out.printf("\t%s\n", chordal.getClass().getCanonicalName());
        }
        System.out.println();
    }
}
