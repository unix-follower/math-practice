package org.example.math

def example1(number: Double): Double = {
    val f = (x: Double) => 3 * Math.pow(x, 2) + 2 * x - 5
    return f(number)
}
