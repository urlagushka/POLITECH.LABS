package Cat;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;

public class ProcessCat {
    public static void disturbPublic(Cat cat, int amount) throws InvocationTargetException, IllegalAccessException {
        Method[] methods = cat.getClass().getDeclaredMethods();
        for (Method method: methods) {
            if (Modifier.isPublic(method.getModifiers())) {
                IntCall rep = method.getAnnotation(IntCall.class);
                for (int i = 0; i < rep.value(); i++) {
                    method.invoke(cat, amount);
                }
            }
        }
    }

    public static void disturbProtected(Cat cat, int amount) throws InvocationTargetException, IllegalAccessException {
        Method[] methods = cat.getClass().getDeclaredMethods();
        for (Method method: methods) {
            if (Modifier.isProtected(method.getModifiers())) {
                IntCall rep = method.getAnnotation(IntCall.class);
                for (int i = 0; i < rep.value(); i++) {
                    method.setAccessible(true);
                    method.invoke(cat, amount);
                }
            }
        }
    }

    public static void disturbPrivate(Cat cat, int amount) throws InvocationTargetException, IllegalAccessException {
        Method[] methods = cat.getClass().getDeclaredMethods();
        for (Method method: methods) {
            if (Modifier.isPrivate(method.getModifiers())) {
                IntCall rep = method.getAnnotation(IntCall.class);
                for (int i = 0; i < rep.value(); i++) {
                    method.setAccessible(true);
                    method.invoke(cat, amount);
                }
            }
        }
    }
}
