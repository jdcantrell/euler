all: p1 p2 p3 p4 p5

p1: euler1.c
	gcc euler1.c -lm -o p1

p2: euler2.c
	gcc euler2.c -lm -o p2

p3: euler3.c
	gcc euler3.c -lm -o p3

p4: euler4.c
	gcc euler4.c -lm -o p4

p5: euler5.c
	gcc euler5.c -lm -o p5
	
p6: euler6.c
	gcc euler6.c -lm -o p6
