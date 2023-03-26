package org.example.math;

import java.util.function.Function;

public class FunctionDefinition {
    public static double fDefinition(double number) {
        final Function<Double, Double> f = (Double x) -> 3 * Math.pow(x, 2) + 2 * x - 5;
        return f.apply(number);
    }
}
