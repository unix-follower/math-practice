FROM python:3.9.9

WORKDIR /app
COPY requirements.txt .
COPY src/ .
RUN python -m pip install --upgrade pip
RUN pip install -r requirements.txt

CMD [ "python3", "./main.py"]
