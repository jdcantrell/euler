#include <stdio.h>
#include <string.h>

#define DIGITS 1000

#define TRUE 1
#define FALSE 0

#define SIZE 15


typedef struct path_list_struct {
    int sum;
    int num;
	struct path_list_struct *next;
} path_list;

path_list init_path(int num) {
	path_list p;
	p.sum = num;
	p.num = num;
	p.next = NULL;
	return p;
}
void update_paths(path_list paths[], int row[], path_list new[]) {
	int i;
	for (i = 0; i < SIZE; i++) {
		if (row[i] == -1) {
			break;
		}
		new[i] = init_path(row[i]);
		if (paths[i].sum > paths[i  + 1].sum) {
			printf("Sum: %d Linking %d to %d\n", new[i].sum, new[i].num,paths[i].num);
			new[i].next = &paths[i];
			new[i].sum += paths[i].sum;
		}
		else {
			new[i].next = &paths[i + 1];
			new[i].sum += paths[i + 1].sum;
			printf("Sum: %d Linking %d to %d\n", new[i].sum, new[i].num,paths[i + 1].num);
		}
	}
	printf("Next!\n\n");
}



int main() {
    int triangle[SIZE][SIZE] = { 
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
    };
	/*int triangle[SIZE][SIZE] = {
		{3, -1, -1, -1},
		{7, 4, -1, -1},
		{2, 4, 6, -1},
		{8, 5, 9, 3}
	};*/

	int i;
	path_list paths[SIZE][SIZE];
	for (i = 0; i < SIZE; i++) {
		paths[0][i] = init_path(triangle[SIZE - 1][i]);
	}

	for (i = 0; i <= SIZE - 2; i++) {
		update_paths(paths[i], triangle[SIZE - 2 - i], paths[i + 1]);
		printf("Row: %d\n", i);
	}

	printf("Sum: %d\n", paths[SIZE - 1][0].sum);
	path_list p = paths[SIZE - 1][0];
	for (i = 0; i < SIZE; i++) {
		printf("Num: %d\n", p.num);
		if (p.next == NULL) {
			printf("Null found, leaving\n");
			break;
		}
		p = *p.next;
	}
}
		

