.PHONY: test

freeze-deps:
	pipenv run pip freeze > requirements.txt

setup:
	python -m pip install --upgrade pip
	pip install pipenv

install:
	pipenv install

test:
	pytest --config-file ../pytest.ini

coverage:
	coverage run --include=src/* -m pytest
	coverage html
