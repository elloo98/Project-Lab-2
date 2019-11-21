#include <iostream>
#include <lab2lib.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	//Main declarations
	int input_int = 0;
	bool loop = true;

	//Task 1 declarations
	int count_1 = 0;
	int input_1[10];
	bool sorted;

	//Task 2 declarations
	char input_2[50];
	bool answer;

	//Task 3 declarations
	int input_3[50][50];
	int size_x = 0;
	int size_y = 0;
	int count = 0;
	int count_2 = 0;
	
	//Task 4 declarations
	int a = 0;
	int b = 0;
	int c = 0;
	bool up = true;

	//Task 5 declarations
	int input_5[50];
	int size = 0;
	int count_5 = 0;

	//Task 6 declaration
	int cheap_workaround;

	printf("+--------+\n|  MENU  |\n+--------+\n\n");
	printf("1:Sort checker\n2:Palindrome checker\n3:Matrix sumarizer\n4:Sorter\n5:Vector shrinker\n6:Vector database sub-menu\n7:Quit\n\n");
	while (loop==true) {
		cin >> input_int;
		switch (input_int) {


			case 1:
				count_1 = 0;
				printf("Please enter ten natural numbers for the array:\n");
				while (count_1 < 10) {
					cin >> input_1[count_1];
					count_1++;
				}
				sorted = is_sorted(input_1);
				printf(sorted ? "True" : "False");
				printf("\n");
				system("pause");
				printf("+--------+\n|  MENU  |\n+--------+\n\n");
				printf("1:Sort checker\n2:Palindrome checker\n3:Matrix sumarizer\n4:Sorter\n5:Vector shrinker\n6:Vector database sub-menu\n7:Quit\n\n");
				break;


			case 2:
				
				printf("Please input a word\n");
				cin >> input_2;
				answer = is_palindrome(input_2);
				printf(answer ? "True" : "False");
				printf("\n");
				system("pause");
				printf("+--------+\n|  MENU  |\n+--------+\n\n");
				printf("1:Sort checker\n2:Palindrome checker\n3:Matrix sumarizer\n4:Sorter\n5:Vector shrinker\n6:Vector database sub-menu\n7:Quit\n\n");
				break;


			case 3:
				size_x = 0;
				size_y = 0;
				count = 0;
				count_2 = 0;

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
						input_3[count][count_2] = 0;
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
					input_3[size_x][count] = 10;
					count++;
				}
				count = 0;
				while (count < size_x) {
					input_3[count][size_y] = 10;
					count++;
				}

				//Filling the matrix with random int values between 0 and 9 in the designated space. This is a token effort to limit processing time.
				count = count_2 = 0;
				while (input_3[0][count_2] != 10) {
					while (input_3[count][count_2] != 10) {
						input_3[count][count_2] = rand() % 10;
						count++;
					}
					count = 0;
					count_2++;
				}
				printf("\n");

				//Calling array_rows_cols and then exiting the program
				array_rows_cols(input_3);
				system("pause");
				printf("+--------+\n|  MENU  |\n+--------+\n\n");
				printf("1:Sort checker\n2:Palindrome checker\n3:Matrix sumarizer\n4:Sorter\n5:Vector shrinker\n6:Vector database sub-menu\n7:Quit\n\n");
				break;


			case 4:
				a = 1;
				b = 0;
				c = 0;
				up = true;
				//Gets inputs from user and quits if a==0
				printf("Please type three values to be sorted (or 0 to quit)\n");
				while (a!=0) {
					cin >> a;
					if (a == 0) {
						break;
					}
					cin >> b;
					cin >> c;
					printf("Okay, now input wether you want them in acending(1) or decending(0) order\n");
					cin >> up;

					//Calling the function and printing the results
					swap_sort(a, b, c, &up);
					printf("The values sort out to look like:\n\n%i %i %i\n\nNow enter three new values, remember that 0 as the first value is quit\n", a, b, c);
				}
				system("pause");
				printf("+--------+\n|  MENU  |\n+--------+\n\n");
				printf("1:Sort checker\n2:Palindrome checker\n3:Matrix sumarizer\n4:Sorter\n5:Vector shrinker\n6:Vector database sub-menu\n7:Quit\n\n");
				break;


			case 5:
				size = 0;
				count_5 = 0;
				//Clearing array
				while (count_5 < 50) {
					input_5[count_5] = 0;
					count_5++;
				}

				//Setting up array and limiting user if they request an array that the program can't provide
				printf("How big do you want your array?\n");
				cin >> size;
				while (size > 50 || size < 1) {
					printf("Please enter a different number, the program can't handle arrays of this size\n");
					cin >> size;
				}
				printf("Okay, now input %i number(s) for your array\n", size);
				count_5 = 0;

				//Getting values from user and correcting if a value is too big. If they are any bigger than 2^31-1 the program will find itself in the while loop forever, probably 
				//due to the unreliable nature of cin, making this more or less redundant, there are very few values above the set value that won't also soft-lock the program 
				//but it is here to stop people from using the NULL value at least.
				while (count_5 < size) {
					cin >> input_5[count_5];
					while (input_5[count_5] >= 2147483647) {
						printf("Please enter a smaller number for this space, the program can't handle that big numbers\n");
						cin >> input_5[count_5];
					}
					count_5++;
				}
				//I realize my mistake from the previous task here, you can't assign a character to an int. Seeing as I need a definite end-point for my array (a stand-in null for the program to look for) I 
				//use a number so large and "unusual" that you are unlikley to chance upon it in regular use, and it is also the largest possible number that you can store in an int so there is no larger 
				//number than it that can be used but not it
				input_5[size] = 2147483647;

				//Printing original array
				count_5 = 0;
				printf("Original array:\n");
				while (count_5 < size) {
					printf("%i ", input_5[count_5]);
					count_5++;
				}
				printf("\n");

				//Calling shrink_array and printing new array
				shrink_array(input_5);
				count_5 = 0;
				printf("Shrunk array:\n");
				while (count_5 < size) {
					printf("%i ", input_5[count_5]);
					count_5++;
				}
				printf("\n");
				system("pause");
				printf("+--------+\n|  MENU  |\n+--------+\n\n");
				printf("1:Sort checker\n2:Palindrome checker\n3:Matrix sumarizer\n4:Sorter\n5:Vector shrinker\n6:Vector database sub-menu\n7:Quit\n\n");
				break;


			case 6:
				//I realized when I programmed this that the menu command returns an int and rather than rewriting things cheap_workaround is simply that, a cheap workaround for it.
				cheap_workaround = menu();
				printf("+--------+\n|  MENU  |\n+--------+\n\n");
				printf("1:Sort checker\n2:Palindrome checker\n3:Matrix sumarizer\n4:Sorter\n5:Vector shrinker\n6:Vector database sub-menu\n7:Quit\n\n");
				break;


			case 7:
				loop = false;
				break;


			default:
				printf("%i isn't a menu option\n", input_int);
				break;

		}
	}
	system("pause");
	return 0;
}