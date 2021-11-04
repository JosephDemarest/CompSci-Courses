#include <iostream>
#include <fstream>

/* the algorithm and what-not was basically on the Lab document for this one

• function readin, reads values from a data file into the array
• function printarray, prints the array to a file.
• function addto adds the prompted value to each element of the array
• function reverse, copies the elements of the array into a second array in
reverse order.

*/

using namespace std;

ifstream infile;
ofstream outfile;

const int sizee = 10; // I had to change it to "sizee", because "size" was already defined in c++ so it was throwing me errors

void readin(int[], int);
void addto(int[], int, int);
void reverse(int[], int[], int);
void printarray(int[], int);

int
main()
{
	int array1[sizee], array2[sizee];
	int num;
	//open data streams
	infile.open("data.txt");
	if (infile.fail())
	{
		cerr << "Input file failed to open.";
		abort();
	}
	outfile.open("output.txt");
	if (outfile.fail())
	{
		cerr << "Output file failed to open.";
		abort();
	}


	readin(array1, sizee);

	printarray(array1, sizee);
	//get user input for addto function
	cout << "What would you like to add to the array? ";

	cin >> num;

	addto(array1, sizee, num);

	printarray(array1, sizee);

	reverse(array1, array2, sizee);

	printarray(array2, sizee);
	
	return 0;

}
void readin(int a[], int num_elem) //reads values from a data file into the array
{
	int i = 0;
	while ( i < num_elem )
	{
		infile >> a[i];
		i++;
	}
	//finish function
}
void addto(int a[], int num_ele, int n) // adds user input to every element of the array
{
	int i = 0;
	while (i < num_ele)
	{
		a[i] = n;
		i++;
	}
	//finish function
}
void reverse(int a[], int a2[], int num_ele) // reverses the array
{
	int i = 0, count = 9;
	for (i = 0; i < num_ele; i++) 
	{
		a2[count] = a[i];
		count--;
	}
	//finish function
}
void printarray(int a[], int num_ele) //prints the array to a file.
{
	if (outfile.is_open())
	{
		for (int i = 0; i < num_ele; i++) 
		{
			outfile << a[i] << " ";
		}
		outfile << "\n";
	}

	//finish function
}
