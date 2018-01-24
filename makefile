mrb.o: benchmark.c
	gcc  -g -O3 -o  mrb benchmark.c

clean:
	rm mrb