all: p1 p2 p3 p4 p5 p6 p7 p8 p9 p10 p11 p12 p13

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

p7: euler7.c
	gcc euler7.c -lm -o p7

p8: euler8.c
	gcc euler8.c -lm -o p8

p9: euler9.c
	gcc euler9.c -lm -o p9

p10: euler10.c
	gcc euler10.c -lm -o p10

p11: euler11.c
	gcc euler11.c -lm -o p11

p12: euler12.c
	gcc euler12.c -lm -o p12

p13: euler13.c
	gcc euler13.c -lm -o p13
