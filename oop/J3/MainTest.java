import Animals.*;
import DequeOut.DequeOutClass;
import Segregate.Segregate;

import java.util.ArrayDeque;
import java.util.Deque;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

class MainTest extends Segregate {
    @Test
    public void commonTest() {
        Deque<Chordal> source = new ArrayDeque<>();
        Deque<CommonHedgehog> hedgehogs = new ArrayDeque<>();
        Deque<Manul> manuls = new ArrayDeque<>();
        Deque<Lynx> lynxes = new ArrayDeque<>();

        source.add(new Manul());
        source.add(new CommonHedgehog());
        source.add(new Lynx());
        source.add(new Lynx());

        assertDoesNotThrow(() -> Segregate.process(source, hedgehogs, manuls, lynxes));

        DequeOutClass.process("source", source);
        DequeOutClass.process("hedgehogs", hedgehogs);
        DequeOutClass.process("manuls", manuls);
        DequeOutClass.process("lynxes", lynxes);
    }

    @Test
    public void hedgehogsTest() {
        Deque<Chordal> source = new ArrayDeque<>();
        Deque<CommonHedgehog> hedgehogs = new ArrayDeque<>();
        Deque<Manul> manuls = new ArrayDeque<>();
        Deque<Lynx> lynxes = new ArrayDeque<>();

        source.add(new CommonHedgehog());
        source.add(new CommonHedgehog());
        source.add(new CommonHedgehog());
        source.add(new CommonHedgehog());

        assertDoesNotThrow(() -> Segregate.process(source, hedgehogs, manuls, lynxes));

        DequeOutClass.process("source", source);
        DequeOutClass.process("hedgehogs", hedgehogs);
        DequeOutClass.process("manuls", manuls);
        DequeOutClass.process("lynxes", lynxes);
    }

    @Test
    public void manulsTest() {
        Deque<Chordal> source = new ArrayDeque<>();
        Deque<CommonHedgehog> hedgehogs = new ArrayDeque<>();
        Deque<Manul> manuls = new ArrayDeque<>();
        Deque<Lynx> lynxes = new ArrayDeque<>();

        source.add(new Manul());
        source.add(new Manul());
        source.add(new Manul());
        source.add(new Manul());

        assertDoesNotThrow(() -> Segregate.process(source, hedgehogs, manuls, lynxes));

        DequeOutClass.process("source", source);
        DequeOutClass.process("hedgehogs", hedgehogs);
        DequeOutClass.process("manuls", manuls);
        DequeOutClass.process("lynxes", lynxes);
    }

    @Test
    public void lynxesTest() {
        Deque<Chordal> source = new ArrayDeque<>();
        Deque<CommonHedgehog> hedgehogs = new ArrayDeque<>();
        Deque<Manul> manuls = new ArrayDeque<>();
        Deque<Lynx> lynxes = new ArrayDeque<>();

        source.add(new Lynx());
        source.add(new Lynx());
        source.add(new Lynx());
        source.add(new Lynx());

        assertDoesNotThrow(() -> Segregate.process(source, hedgehogs, manuls, lynxes));

        DequeOutClass.process("source", source);
        DequeOutClass.process("hedgehogs", hedgehogs);
        DequeOutClass.process("manuls", manuls);
        DequeOutClass.process("lynxes", lynxes);
    }
}
