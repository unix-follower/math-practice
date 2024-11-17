package org.example.math.linalg

import org.example.math.linalg.example.Example_1_4
import org.example.math.linalg.example.Example_1_7

object Main {
    def main(args: Array[String]): Unit = {
        val isExecuteAll = () => args(0).toBoolean
        if (args.length > 0 && isExecuteAll()) {
            Example_1_4.executeWithCommonsMathLUDecomposition()
            Example_1_7.executeWithCommonsMathLUDecomposition()
        } else {
            Example_1_7.executeWithCommonsMathLUDecomposition()
        }
    }
}
