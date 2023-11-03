#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here



// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
  // Open the CSV file for reading
  FILE * file = fopen("FitnessData_2023.csv", "r");
  if (file == NULL) {
    printf("FitnessData_2023.csv could not be opened\n");
    return 1;
  }

  FITNESS_DATA data[1000];
  // set the intial value for numRecords
  int numRecords = 0;
  char line[1000];

  // Read and process each line in the CSV file
  while (fgets(line, sizeof(line), file) != NULL) {
    // create variables of the correct sizes 
    char date[11];
    char time[6];
    char steps[11];

    // Use the tokeniseRecord function to split the line into date, time, and steps
    tokeniseRecord(line, ",", date, time, steps);

    // Store the data in the FITNESS_DATA structure
    strcpy(data[numRecords].date, date);
    strcpy(data[numRecords].time, time);
    data[numRecords].steps = atoi(steps);
    // increase the numRecords value by 1 for each iteration of the for loop, the final value of numRecords will be the total number of records as each line will have been read
    numRecords++;
  }

  // The numRecords variable now contains 
  printf("There are: %d records in the file \n", numRecords);

  // iterate through the rows using a for loop to print out the first 3 rows (i<3 (change number to print more or less rows))
  for (int i = 0; i < 3 && i < numRecords; i++) {
    printf("%s/%s/%d\n", data[i].date, data[i].time, data[i].steps);
  }

  //close the file 
  fclose(file);
  return 0;
}
