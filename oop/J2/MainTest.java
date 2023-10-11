import Cat.ProcessCat;
import Cat.Cat;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.assertDoesNotThrow;

class MainTest extends ProcessCat {
    @Test
    public void testPublic() {
        Cat cat = new Cat();
        assertDoesNotThrow(() -> ProcessCat.disturbPublic(cat), "public failed");
    }

    @Test
    public void testProtected() {
        Cat cat = new Cat();
        assertDoesNotThrow(() -> ProcessCat.disturbProtected(cat), "protected failed");
    }

    @Test
    public void testPrivate() {
        Cat cat = new Cat();
        assertDoesNotThrow(() -> ProcessCat.disturbPrivate(cat), "private failed");
    }
}