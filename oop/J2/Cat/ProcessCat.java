package Cat;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.lang.reflect.Modifier;

public class ProcessCat {
    public static void disturbPublic(Cat cat) throws InvocationTargetException, IllegalAccessException {
        Method[] methods = cat.getClass().getDeclaredMethods();
        for (Method method: methods) {
            if (Modifier.isPublic(method.getModifiers())) {
                IntCall amount = method.getAnnotation(IntCall.class);
                for (int i = 0; i < amount.value(); i++) {
                    method.invoke(cat);
                }
            }
        }
    }

    public static void disturbProtected(Cat cat) throws InvocationTargetException, IllegalAccessException {
        Method[] methods = cat.getClass().getDeclaredMethods();
        for (Method method: methods) {
            if (Modifier.isProtected(method.getModifiers())) {
                IntCall amount = method.getAnnotation(IntCall.class);
                for (int i = 0; i < amount.value(); i++) {
                    method.setAccessible(true);
                    method.invoke(cat);
                }
            }
        }
    }

    public static void disturbPrivate(Cat cat) throws InvocationTargetException, IllegalAccessException {
        Method[] methods = cat.getClass().getDeclaredMethods();
        for (Method method: methods) {
            if (Modifier.isPrivate(method.getModifiers())) {
                IntCall amount = method.getAnnotation(IntCall.class);
                for (int i = 0; i < amount.value(); i++) {
                    method.setAccessible(true);
                    method.invoke(cat);
                }
            }
        }
    }
}
