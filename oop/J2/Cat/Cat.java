package Cat;

public class Cat {
    @IntCall(1)
    public void publicMeow() {
        System.out.println("for everyone | public meow");
    }

    @IntCall(2)
    public void publicSleep() {
        System.out.println("for everyone | public sleep");
    }

    @IntCall(3)
    public void publicEat() {
        System.out.println("for everyone | public eat");
    }

    @IntCall(1)
    protected void protectedMeow() {
        System.out.println("for kittens | protected meow");
    }

    @IntCall(2)
    protected void protectedSleep() {
        System.out.println("for kittens | protected sleep");
    }

    @IntCall(3)
    protected void protectedEat() {
        System.out.println("for kittens | protected eat");
    }

    @IntCall(1)
    private void privateMeow() {
        System.out.println("myself | private meow");
    }

    @IntCall(2)
    private void privateSleep() {
        System.out.println("myself | private sleep");
    }

    @IntCall(3)
    private void privateEat() {
        System.out.println("myself | private eat");
    }
}
