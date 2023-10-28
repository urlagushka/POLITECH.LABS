import Cat.Cat;
import Cat.ProcessCat;

public class Main {
    public static void main(String[] args) {
        Cat cat = new Cat();
        try {
            ProcessCat.disturbPublic(cat, 1);
            ProcessCat.disturbProtected(cat, 2);
            ProcessCat.disturbPrivate(cat, 3);
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
