package org.example.math;

import org.apache.commons.math3.util.Precision;
import org.junit.jupiter.api.Test;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import static org.junit.jupiter.api.Assertions.assertEquals;

class DerivativeTest {
    private static final Logger logger = LoggerFactory.getLogger(DerivativeTest.class);

    @Test
    void test_xSquare() {
//        f(2) = 2²
        final var result = Derivative.xSquare(2);
        logger.info("{}", result);
        final var f_result = result.getLeft();
        final var f1_result = result.getRight();
        assertEquals(4, f_result);
        assertEquals(4, Precision.round(f1_result, 1));
    }

    @Test
    void test_ax_in_power_n() {
//        y = 5 * 2^7
        var result = Derivative.axInPowerN(5, 7, 2);
        logger.info("{}", result);
        var f_result = result.getLeft();
        var f1_result = result.getRight();
        assertEquals(640, f_result);
        assertEquals(2240, Precision.round(f1_result, 1));

//        y = 3 * 5²
        result = Derivative.axInPowerN(3, 2, 5);
        logger.info("{}", result);
        f_result = result.getLeft();
        f1_result = result.getRight();
        assertEquals(75, Precision.round(f_result, 1));
        assertEquals(30, Precision.round(f1_result, 1));

//             4
//        y = --- = 4 * 6⁻²
//            6²
        result = Derivative.axInPowerN(4, -2, 6);
        logger.info("{}", result);
        f_result = result.getLeft();
        f1_result = result.getRight();
        assertEquals(0.111, Precision.round(f_result, 3));
        assertEquals(-0.037, Precision.round(f1_result, 3));

//        y = 3√5 = 3 * 5^½ = 3 * 5^0.5
        result = Derivative.axInPowerN(3, .5, 5);
        logger.info("{}", result);
        f_result = result.getLeft();
        f1_result = result.getRight();
        assertEquals(6.708, Precision.round(f_result, 3));
        assertEquals(0.671, Precision.round(f1_result, 3));
    }

    @Test
    void test_sinusoid() {
//        y = sin(2)
        var result = Derivative.sinusoid(2);
        logger.info("{}", result);
        var f_result = result.getLeft();
        var f1_result = result.getRight();
        assertEquals(0.909, Precision.round(f_result, 3));
        assertEquals(-0.416, Precision.round(f1_result, 3));
    }
}
