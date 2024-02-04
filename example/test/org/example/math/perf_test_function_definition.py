import cProfile
import timeit
import unittest

# noinspection PyUnresolvedReferences
import org.example.math.function_definition as f_def
from org.example.math.config.logging_config import logger


class FunctionDefinitionPerformanceTest(unittest.TestCase):
    @staticmethod
    def test_execute_profiler():
        cProfile.runctx("f_def.example1(0)", globals(), locals())

    def test_benchmark(self):
        result = timeit.timeit("f_def.example1(0)", globals=globals())
        logger.info("benchmark result: {}".format(result))
        self.assertTrue(result < 1)


if __name__ == '__main__':
    unittest.main()
