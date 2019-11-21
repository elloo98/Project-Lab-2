#include <iostream>
using namespace std;

/*
void shrink_array(int *input) {
	int count = 0;
	int count_2 = 0;
	int size = 0;
	int temp[50];

	while (count < 50) {
		temp[count] = 0;
		count++;
	}
	count = 0;
	while (input[size] != 2147483647)
		size++;
	input[size] = 0;
	while (count_2 < size) {
		temp[count] = input[count_2] + input[count_2 + 1];
		count++;
		count_2 = count_2 + 2;
	}
	count = 0;
	while (count < size) {
		input[count] = temp[count];
		count++;
	}
}

int main() {
	int input[50];
	int size = 0;
	int count = 0;

	//Clearing array
	while (count < 50) {
		input[count] = 0;
		count++;
	}

	//Setting up array and limiting user if they request an array that the program can't provide
	printf("How big do you want your array?\n");
	cin >> size;
	while (size > 50 || size < 1) {
		printf("Please enter a different number, the program can't handle arrays of this size\n");
		cin >> size;
	}
	printf("Okay, now input %i number(s) for your array\n", size);
	count = 0;

	//Getting values from user and correcting if a value is too big. If they are any bigger than 2^31-1 the program will find itself in the while loop forever, probably 
	//due to the unreliable nature of cin, making this more or less redundant, there are very few values above the set value that won't also soft-lock the program 
	//but it is here to stop people from using the NULL value at least.
	while (count < size) {
		cin >> input[count];
		while (input[count] >= 2147483647) {
			printf("Please enter a smaller number for this space, the program can't handle that big numbers\n");
			cin >> input[count];
		}
		count++;
	}
	//I realize my mistake from the previous task here, you can't assign a character to an int. Seeing as I need a definite end-point for my array (a stand-in null for the program to look for) I 
	//use a number so large and "unusual" that you are unlikley to chance upon it in regular use, and it is also the largest possible number that you can store in an int so there is no larger 
	//number than it that can be used but not it
	input[size] = 2147483647;
	
	//Printing original array
	count = 0;
	printf("Original array:\n");
	while (count < size) {
		printf("%i ", input[count]);
		count++;
	}
	printf("\n");

	//Calling shrink_array and printing new array
	shrink_array(input);
	count = 0;
	printf("Shrunk array:\n");
	while (count < size) {
		printf("%i ", input[count]);
		count++;
	}
	printf("\n");
	system("pause");
	return 0;
}
*/