all: p001 p002 p003 p004 p005 p006 p007 p008 p009 p010 p011 p012 p013 p014 p016 p017 p018 p019 p067 p020 p021

p001: euler1.c
	clang euler1.c -lm -o p001

p002: euler2.c
	clang euler2.c -lm -o p002

p003: euler3.c
	clang euler3.c -lm -o p003

p004: euler4.c
	clang euler4.c -lm -o p004

p005: euler5.c
	clang euler5.c -lm -o p005
	
p006: euler6.c
	clang euler6.c -lm -o p006

p007: euler7.c
	clang euler7.c -lm -o p007

p008: euler8.c
	clang euler8.c -lm -o p008

p009: euler9.c
	clang euler9.c -lm -o p009

p010: euler10.c
	clang euler10.c -lm -o p010

p011: euler11.c
	clang euler11.c -lm -o p011

p012: euler12.c
	clang euler12.c -lm -o p012

p013: euler13.c
	clang euler13.c -lm -o p013

p014: euler14.c
	clang euler14.c -lm -o p014

p016: euler16.c
	clang euler16.c big_int.c -lm -o p016

p017: euler17.c
	clang euler17.c -lm -o p017
	
p018: euler18.c
	clang euler18.c -lm -o p018
	
p019: euler19.c
	clang euler19.c -lm -o p019
	
p020: euler20.c
	clang -g euler20.c big_int.c -lm -o p020

p021: euler21.c
	clang -g euler21.c -lm -o p021

p067: euler67.c
	clang euler67.c -lm -o p067
