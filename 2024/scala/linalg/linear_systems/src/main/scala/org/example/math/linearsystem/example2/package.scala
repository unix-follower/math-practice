package org.example.math.linearsystem.example2

import org.apache.commons.math3.linear.{Array2DRowRealMatrix, ArrayRealVector, LUDecomposition}
import org.example.math.linearsystem.ArrayConstants
import org.slf4j.LoggerFactory

private val logger = LoggerFactory.getLogger("Linear system")

def example2(): Unit = {
    val data: Array[Array[Double]] = Array(
        Array(3.0, 0.0, 0.0),
        Array(1.0, 5.0, -2.0),
        Array(1.0 / 3.0, 2.0, 0.0)
    )
    val matrix = new Array2DRowRealMatrix(data)

    val vectorData: Array[Double] = Array(9.0, 2.0, 3.0)
    val vector = new ArrayRealVector(vectorData)

    val solver = new LUDecomposition(matrix).getSolver
    val resultVector = solver.solve(vector)

    val x1 = resultVector.getEntry(ArrayConstants.FIRST_COLUMN)
    val x2 = resultVector.getEntry(ArrayConstants.SECOND_COLUMN)
    val x3 = resultVector.getEntry(ArrayConstants.THIRD_COLUMN)
    logger.info("x1={}\nx2={}\nx3={}", x1, x2, x3)

    assert(Math.round(x1) == 3, s"Actual value $x1")
    assert(Math.round(x2) == 1, s"Actual value $x2")
    assert(Math.round(x3) == 3, s"Actual value $x3")
}
