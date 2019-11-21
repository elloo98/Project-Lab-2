#include <iostream>
using namespace std;

/*
void swap_sort(int &a, int &b, int &c, bool *up) {
	int temp = 0;
	int count = 0;

	//Sorting the values. I would have preffered for the way that you are to handle the data to be up to programmer, an int matrix would be way easier to sort in comparison to three unique
	//values as well as not have to nest if statements inside a while loop, instead of just nesting while loops. These two issues lead to a very specific function as compared to something that
	//is more general in its aplication
	if (*up == true) {
		while(count<2){
			if(a>b){
				temp = b;
				b = a;
				a = temp;
			}
			if (b > c) {
				temp = c;
				c = b;
				b = temp;
			}
			count++;
		}
	}

	//Sorting the values in decending order, above is acending
	else {
		while (count < 2) {
			if (a < b) {
				temp = b;
				b = a;
				a = temp;
			}
			if (b < c) {
				temp = c;
				c = b;
				b = temp;
			}
			count++;
		}
	}
}

int main() {
	int a = 0;
	int b = 0;
	int c = 0;
	bool up = true;

	//Gets inputs from user and quits if a==0
	printf("Please type three values to be sorted (or 0 to quit)\n");
	while (1) {
		cin >> a;
		if (a == 0)
			return 0;
		cin >> b;
		cin >> c;
		printf("Okay, now input wether you want them in acending(1) or decending(0) order\n");
		cin >> up;

		//Calling the function and printing the results
		swap_sort(a, b, c, &up);
		printf("The values sort out to look like:\n\n%i %i %i\n\nNow enter three new values, remember that 0 as the first value is quit\n", a, b, c);
	}
}

*/