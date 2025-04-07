#include "matrix.h"


int **createMatrix() {

    // seed random numbers
    srand(time(NULL));

    // Allocate and populate matrix with random numbers.
    printf("Generating numbers from 0 to %d...", MAX_RAND);
    int **matrix = (int **) malloc(sizeof(int*) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        matrix[i] = (int*) malloc(sizeof(int) * COLUMNS);
        for (int j = 0; j < COLUMNS; j++) {
            matrix[i][j] = rand() % MAX_RAND;
        }
    }
    printf("Done.\n");

    return matrix;
}

void printMatrix(int **matrix) {

    for (int i = 0; i < ROWS; i++) {
        printf("%2d | ", i);
        for (int j = 0; j < COLUMNS; j++) {
            printf("%7d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// ex.5
int valueExists(int **matrix, int value) {

    int pid[ROWS];
    
    for(int i=0;i<ROWS;i++){
        if((pid[i]=fork())==0){
            for(int j=0;j<COLUMNS;j++){
                if matrix[i][j]==value{
                    _exit(1);
                }
            }
            _exit(0);
        }
    }

    for(int i=0;i<ROWS;i++){
        int status;
        wait(&status);
        if(WIFEXITED(status) && WEXITSTATUS(status)==1){
            return 1;
        }
            
    }
    
    return 0;
}

void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}
// ex.6
void linesWithValue(int **matrix, int value) {

    int pid[ROWS];
    int values[ROWS];
    
    for(int i=0;i<ROWS;i++){
        if((pid[i]=fork())==0){
            for(int j=0;j<COLUMNS;j++){
                if matrix[i][j]==value{
                    _exit(i);
                }
            }
            _exit(0);
        }
    }

    for(int i=0;i<ROWS;i++){
        int total=0;
        int status;
        wait(&status);
        if(WIFEXITED(status) && WEXITSTATUS(status)!=0){
            values[i]=WEXITSTATUS(status);
            total++;
        }
        
    }
    bubbleSort(values,total);
    for (int i=0;i<total;i++){
        printf("%d\n"values[i]);
    }
}