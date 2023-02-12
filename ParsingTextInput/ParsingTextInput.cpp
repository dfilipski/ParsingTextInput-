#include <iostream>
#include <cstdio>
#include <vector>

constexpr size_t ROWS = 5;
constexpr size_t COLUMNS = 10;

void read_data_c_style(double arr[][COLUMNS], size_t rows);
void get_nth_row(double read_array[][COLUMNS], double write_array[], int num_rows, int target_row);
void get_nth_col(double read_array[][COLUMNS], double write_array[], int num_rows, int target_col);

int main()
{
	// Array indexing starts at 0. 
	// Assume j is the following array { 1, 2, 3, 4 }
	// 1 is the 0th element
	// 2 is the 1st element
	// 3 is the 2nd element
	// 4 is the 3rd element

	// Create a 2d array with 5 rows and 10 columnsand initialize the to all
	// zeros. You should replace 5 and 10 with how many rows and columns of
	// numbers you have
	double data[ROWS][COLUMNS] = {};
	read_data_c_style(data, ROWS);

	double row_3[COLUMNS] = {};
	get_nth_row(data, row_3, ROWS, 3);

	// print that row
	printf("row 3: ");
	for (size_t i = 0; i < COLUMNS; i++)
	{
		printf("%.2lf ", row_3[i]);
	}
	printf("\n");

	double col_2[ROWS] = {};
	get_nth_col(data, col_2, ROWS, 2);
	// print that column
	printf("col 2: ");
	for (size_t i = 0; i < ROWS; i++)
	{
		printf("%.2lf ", col_2[i]);
	}
	printf("\n");

	return 0;
}

// size_t is a type for numbers used for the sizes of things in memory, like how many
// rows and columns are in a 2d array
void read_data_c_style(double arr[][COLUMNS], size_t rows)
{
	constexpr char path[] = "C:/Users/Dan/source/hacks/ParsingTextInput/ParsingTextInput/input.txt";
	// If you open a file, you must close it
	FILE* phFile = fopen(path, "r");
	// fopen can return NULL, meaning the file was unable to be opened
	// You should handle the error. In this case I print a message saying the 
	// file could not be opened and exit the program
	if (phFile == NULL) {
		fprintf(stderr, "Failed to open input.txt for reading\n");
		exit(1);
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < COLUMNS; j++)
		{
			fscanf(phFile, "%lf", &arr[i][j]);
		}
	}

	// If you open a file, you must close it

	fclose(phFile);
}

void get_nth_row(double read_array[][COLUMNS], double write_array[], int num_rows, int target_row)
{
	// Assume write_array has at least COLUMNS columns
	for (size_t i = 0; i < COLUMNS; i++)
	{
		write_array[i] = read_array[target_row][i];
	}
}

void get_nth_col(double read_array[][COLUMNS], double write_array[], int num_rows, int target_col)
{
	// Assume write_array has at least num_rows rows
	for (size_t i = 0; i < num_rows; i++)
	{
		write_array[i] = read_array[i][target_col];
	}
}