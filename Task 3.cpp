#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
void array_rows_cols(int input[50][50]) {
	int size_x = 0;
	int size_y = 0;
	int count_x = 0;
	int count_y = 0;
	int sums_x[50];
	int sums_y[50];
	int sum_tot = 0;
	
	//Finding out matrix size
	while (input[size_x][0] != 10)
		size_x++;
	while (input[0][size_y] != 10)
		size_y++;

	//Zeroing sums
	while (count_x < 50) {
		sums_x[count_x] = 0;
		count_x++;
	}
	while (count_y < 50) {
		sums_y[count_y] = 0;
		count_y++;
	}
	
	//Summing rows
	count_x = count_y = 0;
	while (count_y < size_x) {
		while (count_x < size_x) {
			sums_x[count_y] = sums_x[count_y] + input[count_x][count_y];
			count_x++;
		}
		count_x = 0;
		count_y++;
	}

	//Summing columns
	count_x = count_y = 0;
	while (count_x < size_x) {
		while (count_y < size_y) {
			sums_y[count_x] = sums_y[count_x] + input[count_x][count_y];
			count_y++;
		}
		count_y = 0;
		count_x++;
	}

	//summing sums
	count_x = count_y = 0;
	while (count_x < size_y) {
		sum_tot = sum_tot + sums_x[count_x];
		count_x++;
	}
	while (count_y < size_x) {
		sum_tot = sum_tot + sums_y[count_y];
		count_y++;
	}
	
	//Printing results. The results at the bottom will most often not align 100% in the console due to the random nature of the problem. It could be solved but due to time-constraint it
	//wasn't and was instead made to work correctly for the most commonly seen values, I.E. when the user inputs values between 3 and 10 for the size, and the output values are in the range of 10-99
	count_x = count_y = 0;
	while (input[0][count_y] != 10) {
		while (input[count_x][count_y] != 10) {
			printf("%i  ", input[count_x][count_y]);
			count_x++;
		}
		printf("| %i\n", sums_x[count_y]);
		count_x = 0;
		count_y++;
	}
	
	count_x = count_y = 0;
	while (count_x < (size_x * 3)) {
		printf("-");
		count_x++;
	}
	printf("+--\n");
	count_x = 0;
	while (count_x < size_x) {
		printf("%i ", sums_y[count_x]);
		count_x++;
	}
	printf("| %i\n",sum_tot);
	
}

int main() {
	int input[50] [50];
	int size_x = 0;
	int size_y = 0;
	int count = 0;
	int count_2=0;

	//Getting matrix size from user and checking that the value is useable by the program, while the program can handle a 50 by 50 matrix, it is best to use values that are smaller than roughly 30 in
	//width because the user readability in the console is quite bad with high values due to one matrix row taking up several lines, quite unlike how they are supposed to be written mathematically.
	printf("Please enter two natural values smaller than 50\nThe first will be how many columns and the second how many rows\n");
	cin >> size_x;
	cin >> size_y;
	while (size_x >= 50 || size_y >= 50 || size_x <= 0 || size_y <= 0) {
		printf("One or both of your values are too big and/or not natural numbers\nPlease write two new ones\n");
		cin >> size_x;
		cin >> size_y;
	}

	//Randomizing rand seed
	srand(time(0));

	//Clearing the matrix
	count = 0;
	while (count_2 < 50) {
		while (count < 50) {
			input[count][count_2] = 0;
			count++;
		}
		count = 0;
		count_2++;
	}

	//Designating size of matrix. \0 was confused  with 0 in array_rows_cols, probably because you lose info when passing an int matrix into other functions, so the value 10 was used as a stand-in NULL.
	//10 will never appear in the matrix when the program is working correctly so it can safely be used. It limits the possibility for re-using the code to single-digit numbers but the value could be 
	//changed to suit the needs of the program, just rewrite the program to use a global constant, let's say x, and have rand() % x and the impromptu NULL be x, then the program will work for 0<x<size(int)
	count = 0;
	while (count < size_y) {
		input[size_x][count] = 10;
		count++;
	}
	count = 0;
	while (count < size_x) {
		input[count][size_y] = 10;
		count++;
	}

	//Filling the matrix with random int values between 0 and 9 in the designated space. This is a token effort to limit processing time.
	count = count_2 = 0;
	while (input[0][count_2] != 10) {
		while (input[count][count_2] != 10) {
			input[count][count_2] = rand() % 10;
			count++;
		}
		count = 0;
		count_2++;
	}
	printf("\n");

	//Calling array_rows_cols and then exiting the program
	array_rows_cols(input);
	system("pause");
	return 0;
}
*/