FROM ubuntu

RUN apt update -y && apt install -y build-essential

COPY . /app

WORKDIR /app
