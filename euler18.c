#include <stdio.h>

#define DIGITS 1000

#define TRUE 1
#define FALSE 0

#define SIZE 4

typedef struct path_list_struct {
    int sum;
	int index;
	int active;
	int c;
    unsigned int number[DIGITS];
} path_list;

void update_paths(path_list paths[],int row[]) {
	int i;
	for (i = 0; i < SIZE; i++) {
		if (paths[i].active) {
			if (paths[i].index == 0 || row[paths[i].index] > row[paths[i].index - 1]) {
			 	paths[i].sum += row[paths[i].index];
				paths[i].number[paths[i].c] = row[paths[i].index];
				paths[i].c++;
				paths[i].number[paths[i].c] = -1;

			}
			else {
			 	paths[i].sum += row[paths[i].index - 1];
				paths[i].index = paths[i].index - 1;
				paths[i].number[paths[i].c] = row[paths[i].index];
				paths[i].c++;
				paths[i].number[paths[i].c] = -1;
			}
		}
	}
}

path_list init_paths(int num, int idx) {
	path_list p;
	p.sum = num;
	p.index = idx;
	p.number[0] = num;
	p.number[1] = -1;
	p.active = TRUE;
	p.c = 1;
	return p;
}


int main() {
    /*int triangle[SIZE][SIZE] = { 
		{75, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		{95, 64, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		{17, 47, 82, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		{18, 35, 87, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		{20,  4, 82, 47, 65, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		{19,  1, 23, 75,  3, 34, -1, -1, -1, -1, -1, -1, -1, -1, -1},
		{88,  2, 77, 73,  7, 63, 67, -1, -1, -1, -1, -1, -1, -1, -1},
		{99, 65,  4, 28,  6, 16, 70, 92, -1, -1, -1, -1, -1, -1, -1},
		{41, 41, 26, 56, 83, 40, 80, 70, 33, -1, -1, -1, -1, -1, -1},
		{41, 48, 72, 33, 47, 32, 37, 16, 94, 29, -1, -1, -1, -1, -1},
		{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, -1, -1, -1, -1},
		{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, -1, -1, -1},
		{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, -1, -1},
		{63, 66,  4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, -1},
		{ 4, 62, 98, 27, 23,  9, 70, 98, 73, 93, 38, 53, 60,  4, 23}
    };*/
	int triangle[SIZE][SIZE] = {
		{3, -1, -1, -1},
		{7, 4, -1, -1},
		{2, 4, 6, -1},
		{8, 5, 9, 3}
	};

	int i;
	path_list paths[SIZE];
	for (i = 0; i < SIZE; i++) {
		paths[i] = init_paths(triangle[SIZE - 1][i], i);
	}

	for (i = SIZE - 2; i >= 0; i--) {
		update_paths(paths, triangle[i]);
	}

	int j;
	for (i = 0; i < SIZE; i++) {
		printf("Path: ");
		printf("Sum: %d ", paths[i].sum);
		for (j = 0; j < SIZE; j++) {
			if (paths[i].number[j] == -1) {
				break;
			}
			printf("-%d", paths[i].number[j]);
		}
		printf("\n");
	}
}
		

