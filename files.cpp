#include <iostream>
#include< string>
#include <fstream>
#include <cstdlib>
using namespace std;

//functions for part 1	
double* read_arr(string filename, int *size) {
	double num;
	int count = 0;
	ifstream infile(filename);//define the object (for reading) 
	if (!infile) { // checking first
		cout << "Can't open file!\n";
		exit(1);
	}
	while (infile >> num) {//as long as the file have more numbers, i'll count them all
		count++;	
	}
	infile.close();//closing the object and the loop
	*size = count;
	double* arr = new double[*size];//generating dinamic array with the size of the count
	ifstream infile1(filename);//define new object 
		for (int i = 0; i < count; i++)///and copying it to the dinmaic array
		{
			infile1>>arr[i];
		}
		infile1.close();//closing the object
		return arr;	
}
void printarray(double* arr, int size) {//printing the array
	for (int i = 0; i < size; i++)//very simple function. one for loop.
	{
		cout << arr[i] << ", ";
		
	}
	cout << endl;
}

//functions for part 2
double max_distance(string filename) {
	double num, max=0, min=0;

	ifstream reading(filename);///define object for reading
	if (!reading) {
		cout << "CAN'T OPEN FILE!\n";//checking first
		exit(1);
	}
	while (reading >> num) {//if the number is greater than the max...
		if (num > max) {
			max = num;
		}
		if (num < min) {//if the number is lower than the min...
			min = num;
		}
	}
	reading.close();//closing the ocject
	return max - min;//returning 
}

//functions for part 3
string longword(string filename) {
	
	ifstream reading(filename);//creating object for reading
	if (!reading) {
		cout << "Can't open file!\n";//checking
		exit(1);
	}
	int max = 0, temp;//max number for length
	string tempword, longword;
	while (reading>> tempword) {
		temp = tempword.length();//if the temp is greater than the max...
		if (temp > max) {
			max = temp;
			longword = tempword;
		}
	}
	
	reading.close();//closing
	return longword;//returning
}

int main() {
	char choice;// regular switch menu
	do
	{
		cout << "\nMENU:\n";
		cout << "Press:\n";
		cout << "0. Exit.\n";
		cout << "1. Read and print array of numbers from file.\n";
		cout << "2. Display a maximum distance of numbers from file.\n";
		cout << "3. Display the longest word in  file. \n";
		cout << "Enter Your Choice:\n";
		cin >> choice;
		switch (choice)
		{
			case '0':
			{
			cout << "Thanks and goodbye!!\n";
			return 0;
			}
			case '1':
			{
			string filename;
			cout << "Please enter the file name. don't forget '.txt' in the end.\n";
			cin >> filename;
			int size;
			double* array = read_arr(filename, &size);//calling the function "sending it"
			printarray(array, size);
			delete[] array;//important to delete the dynamic memmory in the end so you can use it and free the space
				break;
			}
			case '2':
			{
				string filename;
			cout << "Please enter the file name. don't forget '.txt' in the end.\n";
			cin >> filename;
			cout << "\nThe max distance is: " << max_distance(filename) << endl;
				break;
			}
			case '3':
			{
			string word;//the long word
			string filename;
			cout << "Please enter the file name. don't forget '.txt' in the end.\n";
			cin >> filename;
			word = longword(filename);
			cout << "The longest word is: " << word;
				break;
			}
		}
	} while (choice != 0);
	return 0;
}

	
