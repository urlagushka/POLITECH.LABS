package Segregate;

import Animals.*;

import java.util.Deque;

public class Segregate {
    public static void process(Deque<? extends Chordal> chordals,
                               Deque<? super CommonHedgehog> hedgehogs,
                               Deque<? super Manul> manuls,
                               Deque<? super Lynx> lynxes) throws RuntimeException {
        for (Chordal chordal: chordals) {
            if (chordal.getClass() == CommonHedgehog.class) {
                hedgehogs.add((CommonHedgehog) chordal);
            } else if (chordal.getClass() == Manul.class) {
                manuls.add((Manul) chordal);
            } else if (chordal.getClass() == Lynx.class) {
                lynxes.add((Lynx) chordal);
            } else {
                throw new RuntimeException("unknown class");
            }
        }
    }
}
