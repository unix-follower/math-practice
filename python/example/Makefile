.PHONY: test

init:
	pip install -r requirements.txt

test-all: test performance-test

test:
	python3 -m unittest -v --locals

performance-test:
	python3 -m unittest discover -v --locals -p "perf_test_*.py"

coverage:
	coverage run --source=src -m unittest -v --locals
	coverage report -m
	coverage html

docker-build:
	docker build --tag example:latest .
