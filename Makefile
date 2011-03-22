all: p1 p2 p3 p4 p5 p6 p7 p8 p9 p10 p11 p12 p13 p14 p16 p17 p18 p19 p67 p20

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

p14: euler14.c
	gcc euler14.c -lm -o p14

p16: euler16.c
	gcc euler16.c big_int.c -lm -o p16

p17: euler17.c
	gcc euler17.c -lm -o p17
	
p18: euler18.c
	gcc euler18.c -lm -o p18
	
p19: euler19.c
	gcc euler19.c -lm -o p19
	
p20: euler20.c
	gcc -g euler20.c big_int.c -lm -o p20

p67: euler67.c
	gcc euler67.c -lm -o p67
