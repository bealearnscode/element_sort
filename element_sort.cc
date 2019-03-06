/*

Write a program that prompts the user to enter the number of elements and the numbers themselves to be placed in an integer array that holds a maximum of 50 elements. The program should then prompt the user for an integer which will be searched for in the array using a binary search.

*/

// Beatrix House

#include <iostream>
using namespace std;

// prototypes
void display(double[], double);
int binary_search(double[], double, int);
void bubble_sort(double[], double);
double find_average(double[], double);

const int SIZE = 50;

int main()
{
    double elements[SIZE];
    double number_of_integers;
    int searching;
    int found;
    
    cout << "Please input the number of integers used " << endl;
    cin >> number_of_integers;
    
    while (number_of_integers > SIZE)
    {
        cout << "Please input an array size less than "
             << SIZE << "." << endl;
             
        cout << "Please input the number of integers used " << endl;
        cin >> number_of_integers;
    }
    
    for(int i = 0; i < number_of_integers; i++)
    {
        cout << "Please input integer number " 
             << i + 1 << endl;
        cin >> elements[i];
    }
    
    cout << "What integer are you searching for?" << endl;
    cin >> searching;
    
    cout << "This array has " << number_of_integers << " integers."
         << endl;
         
    cout << "The array entered by the user is as follows: " << endl;
    display(elements, number_of_integers);
    
    found = binary_search(elements, number_of_integers, searching);
    if (found == -1)
    {
        cout << "The value " << searching << " is not on the list" << endl;
    }
    
    else
    {
        cout << "The value " << searching << " is in the " << found + 1 << " position in the list." << endl;
    }
    
    cout << "The mean of all the elements in the array is" << endl;
    cout << find_average(elements, number_of_integers) << endl;
    
    return 0;
    
}

void display(double arr[], double elements)
{
    for (int i = 0; i < elements; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int binary_search (double arr[], double num_int, int value)
{
    for (int i = 0; i <= num_int; i++)
    {
        if(arr[i] == value)
        {
            return i;
        }
    }
    return -1;
}

void bubble_sort(double arr[], double elements)
{
	bool swap;
	int temp;
	int bottom = elements - 1;
	
	do
	{
		swap = false;
		for (int i = 0; i < bottom; i++)
		{
			if (arr[i] > arr[i + 1])
			{	             
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				swap = true; 
			}
		}
		bottom--; 
	} while (swap != false);
}

double find_average(double arr[], double value)
{
	double average = 0;

	for (int i = 0; i < value; i++)
	{
		average += arr[i];
	}
	
	double the_mean = average / value;

	return the_mean;
}
