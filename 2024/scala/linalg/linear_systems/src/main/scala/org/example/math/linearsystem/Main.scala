package org.example.math.linearsystem

import org.example.math.linearsystem.example2._
import org.example.math.linearsystem.example3._

object Main {
    def main(args: Array[String]): Unit = {
        val isExecuteAll = () => args(0).toBoolean
        if (args.length > 0 && isExecuteAll()) {
            example2()
            example3()
        } else {
            example3()
        }
    }
}
