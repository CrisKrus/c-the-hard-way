FROM ubuntu

RUN apt update -y && apt install -y build-essential

COPY . /app

WORKDIR /app

RUN make ch01-using-makefile/ex1
RUN make ch03-formated-printing/ex3
RUN make ch12-sizes-and-arrays/ex12
