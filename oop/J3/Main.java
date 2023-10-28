import Animals.*;
import DequeOut.DequeOutClass;
import Segregate.Segregate;

import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
    public static void main(String[] args) {
        Deque<Chordal> source = new ArrayDeque<>();
        Deque<CommonHedgehog> hedgehogs = new ArrayDeque<>();
        Deque<Manul> manuls = new ArrayDeque<>();
        Deque<Lynx> lynxes = new ArrayDeque<>();

        source.add(new Manul());
        source.add(new CommonHedgehog());
        source.add(new Lynx());
        source.add(new Lynx());

        Segregate.process(source, hedgehogs, manuls, lynxes);

        DequeOutClass.process("source", source);
        DequeOutClass.process("hedgehogs", hedgehogs);
        DequeOutClass.process("manuls", manuls);
        DequeOutClass.process("lynxes", lynxes);
    }
}
