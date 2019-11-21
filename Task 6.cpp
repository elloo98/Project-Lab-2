#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<char> entries(1,'\0');
	bool loop = true;
	char input_char[50];
	int input_int = 0;
	int size = 0;
	int count = 0;
	int count_2 = 0;
	int count_3 = 0;
	int count_4 = 0;
	printf("+--------+\n|  MENU  |\n+--------+\n\n");
	printf("1:Clear Database\n2:Insert Entry\n3:Search Entry\n4:Delete Entry\n5:Print Database\n6:Show Menu Again\n7:Quit\n\n");
	while (1) {

		scanf_s("%s", input_char, _countof(input_char));
		input_int = input_char[0] - 48;

		//Clear database
		if (input_int == 1) {
			printf("Are you shure you want to delete all entries in the database?(y/n)\n");
			cin >> input_char[0];
			if (input_char[0] == 'y') {
				printf("Entries deleted\n");
				entries.clear();
				entries.push_back('\0');
			}
			else {
				printf("Deletion aborted\n");
			}
		}

		//Insert entry
		else if (input_int == 2) {
			while (loop == true) {
				printf("Please write an entry to be added or write Q or q to go back to menu selection\n");
				scanf_s("%s", input_char,_countof(input_char));

				//Looking for Q and q and break the loop (I am unfamiliar with the break command, I prefer using bools for loops
				if ((input_char[0] == 'Q' || input_char[0] == 'q') && input_char[1] == '\0')
					loop = false;

				//Alocating memory and storeing values
				else {
					count = count_2 = count_3 = size = 0;

					//Checking size of input variable and allocate memory
					while (input_char[size] != '\0') {
						size++;
					}
					count_2 = entries.size();
					entries.resize(size+count_2+1);

					count_3 = count_2 + size;
					count = 0;

					//Entering entry
					while (count_2 < count_3) {
						entries[count_2] = input_char[count];
						count++;
						count_2++;
					}
					entries[count_2] = '\0';
				}
			}
			printf("You have stopped inputing entries, please select a new option\n");
			loop = true;
		}

		//Search entry
		else if (input_int == 3) {
			count = count_2 = count_3 = count_4 = size = 0;

			//Get search term
			printf("Please enter one or several characters to search the Database for\n");
			scanf_s("%s", input_char, _countof(input_char));
			while (input_char[size] != '\0')
				size++;

			//Search loop
			while (count < entries.size()) {
				while (entries[count + count_2] == input_char[count_2]) {
					//if-statement true when all chars of input equate to somewhere in entries
					if(count_2 == size-1){
						count_2 = count_3 = count;
						//Finds start of entry
						while (entries[count_2] != '\0') 
							count_2--;
						//Finds end of entries
						while (entries[count_3] != '\0')
							count_3++;
						count_2++;
						while (count_2 < count_3) {
							printf("%c", entries[count_2]);
							count_2++;
						}
						count_2 = 0;
						printf("\n");
					}
					count_2++;
				}
				count++;
				count_2 = count_3 = 0;
			}
		}

		//Delete entry
		else if (input_int == 4) {
			count = count_2 = count_3 = count_4 = size = 0;
			printf("Please enter the name of an entry to delete\nThis will delete all entries with this exact name\n");

			//Get search term for deletion
			scanf_s("%s", input_char, _countof(input_char));
			while (input_char[size] != '\0')
				size++;
			while (count < entries.size()) {
				//Finds first character
				if (entries[count] == input_char[0]) {
					count--;
					if (entries[count] == '\0') {
						count_2 = count + 1;
						//Checks the rest of the characters
						while (count_3 < size && entries[count_2] == input_char[count_3]) {
							count_2++;
							count_3++;
							//Checks that the lenghts match up 
							if (entries[count_2] == '\0'&&count_3==size) {
								count_2 = count+1;
								count_3 = count + size + 1;
								//entries.push_back('\0');
								//Moves characters forwards
								while (entries.size() > count_3) {
									entries[count_2] = entries[count_3];
									count_2++;
									count_3++;
								}
								//Removes unnececary memory
								count_2 = size;
								while (count_2 > 0) {
									entries.pop_back();
									count_2--;
								}
								count_4++;
							}
						}
					}
					count++;
				}
				count++;
				count_2 = count_3 = 0;
			}
			printf("%i entrie(s) deleted\n", count_4);
		}

		//Print database
		else if (input_int == 5) {
			count = count_2 = count_3 = 0;
			count++;
			while (count < entries.size()) {
				if (entries[count] == '\0') {
					printf("\n");
				}
				else {
					printf("%c", entries[count]);
				}
				count++;
			}
		}

		//Print menu
		else if (input_int == 6) {
			printf("+--------+\n|  MENU  |\n+--------+\n\n");
			printf("1:Clear Database\n2:Insert Entry\n3:Search Entry\n4:Delete Entry\n5:Print Database\n6:Show Menu Again\n7:Quit\n\n");
		}

		//Quit
		else if (input_int == 7) {
			printf("The program will now quit\n");
			system("pause");
			return 0;
		}

		//Incorrect entry
		else {
			printf("The character you have entered isn't an option, please enter an allowed number\n(remember that 6 shows the options)\n");
		}
	}
}
