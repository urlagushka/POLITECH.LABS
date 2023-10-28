package Cat;

public class Cat {
    @IntCall(1)
    public void publicMeow(int amount) {
        System.out.printf("for everyone | public meow %d times\n", amount);
    }

    @IntCall(2)
    public void publicSleep(int amount) {
        System.out.printf("for everyone | public sleep %d hours\n", amount);
    }

    @IntCall(3)
    public void publicEat(int amount) {
        System.out.printf("for everyone | public eat %d kilos\n", amount);
    }

    @IntCall(1)
    protected void protectedMeow(int amount) {
        System.out.printf("for kittens | protected meow %d times\n", amount);
    }

    @IntCall(2)
    protected void protectedSleep(int amount) {
        System.out.printf("for kittens | protected sleep %d hours\n", amount);
    }

    @IntCall(3)
    protected void protectedEat(int amount) {
        System.out.printf("for kittens | protected eat %d kilos\n", amount);
    }

    @IntCall(1)
    private void privateMeow(int amount) {
        System.out.printf("myself | private meow %d times\n", amount);
    }

    @IntCall(2)
    private void privateSleep(int amount) {
        System.out.printf("myself | private sleep %d hours\n", amount);
    }

    @IntCall(3)
    private void privateEat(int amount) {
        System.out.printf("myself | private eat %d kilos\n", amount);
    }
}
