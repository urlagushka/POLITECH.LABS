import Cat.Cat;
import Cat.ProcessCat;

public class Main {
    public static void main(String[] args) {
        Cat cat = new Cat();
        try {
            ProcessCat.disturbPublic(cat);
            ProcessCat.disturbProtected(cat);
            ProcessCat.disturbPrivate(cat);
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}
