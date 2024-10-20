package org.example.math.linearsystem.example3

import org.apache.commons.math3.linear.{Array2DRowRealMatrix, ArrayRealVector, LUDecomposition}
import org.example.math.linearsystem.ArrayConstants
import org.slf4j.LoggerFactory

private val logger = LoggerFactory.getLogger("Linear system")

def example3(): Unit = {
    val data: Array[Array[Double]] = Array(
        Array(1.0, 1.0, 0.0),
        Array(2.0, -1.0, 3.0),
        Array(1.0, -2.0, -1.0)
    )
    val matrix = new Array2DRowRealMatrix(data)

    val vectorData: Array[Double] = Array(0.0, 3.0, 3.0)
    val vector = new ArrayRealVector(vectorData)

    val solver = new LUDecomposition(matrix).getSolver
    val resultVector = solver.solve(vector)

    val x = resultVector.getEntry(ArrayConstants.FIRST_COLUMN)
    val y = resultVector.getEntry(ArrayConstants.SECOND_COLUMN)
    val z = resultVector.getEntry(ArrayConstants.THIRD_COLUMN)
    logger.info("x={}\ny={}\nz={}", x, y, z)

    assert(Math.round(x) == 1, s"Actual value $x")
    assert(Math.round(y) == -1, s"Actual value $y")
    assert(Math.round(z) == 0, s"Actual value $z")
}
