package org.example.math;

import java.util.function.DoubleFunction;

public class Chord {
    public static double slopeAngle(double x1, double x2) {
        final DoubleFunction<Double> f = (double x) -> Math.pow(x, 2);

        final var x2_square = f.apply(x2);
        final var x1_square = f.apply(x1);

        final var denominator_subtraction_result = x2 - x1;
        return (x2_square - x1_square) / denominator_subtraction_result;
    }
}
