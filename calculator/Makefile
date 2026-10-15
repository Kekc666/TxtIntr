.PHONY: all test clean

all:
	chmod +x calculator.sh

test: all
	./calculator.sh -o summa 45 13 -2
	./calculator.sh --operation subtract 45 13 -2

clean:
	rm -f calculator *.o *.out
