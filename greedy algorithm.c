#include<stdio.h> #include<stdlib.h> #include <limits.h>
void printAssignment(int assignment[], int numJobs)
 {     
    printf("Optimal Assignment:\n");
for (int i = 0; i < numJobs; i++) 
{
printf("Job %d assigned to Worker %d\n", i + 1, assignment[i] + 1);
}
}

void solveJobScheduling(int costs[][3], int numJobs, int numWorkers)
 {
int currentAssignment[3];
 int bestAssignment[3]; 
int jobPermutation[3];
for (int i = 0; i < numJobs; i++) 
         { jobPermutation[i] = i;
 
int bestCost = INT_MAX; do {
int currentCost = 0;
for (int i = 0; i < numJobs; i++) {
int workerIndex = jobPermutation[i]; currentAssignment[i] = workerIndex;
currentCost += costs[i][workerIndex];
}
if (currentCost < bestCost) { bestCost = currentCost;
for (int i = 0; i < numJobs; i++) {
bestAssignment[i] = currentAssignment[i];
}
}
} while (next_permutation(jobPermutation, numJobs));
printAssignment(bestAssignment, numJobs);
}
 
          int next_permutation(int array[], int size) { int i =size2;
while (i >= 0 && array[i] > array[i + 1]) 
{
i--;
}
if (i < 0) {
return 0;
}
int j = size - 1;
while (array[j] < array[i]) 
{
j--;
}
swap(&array[i], &array[j]);
reverse(array + i + 1, size - i - 1); 
return 1;
}
 
void swap(int* a, int* b) { int temp = *a;
*a = *b;
*b = temp;
}
     void reverse(int array[], int size) { int start = 0;
int end = size - 1; while(start< end) {
swap(&array[start], &array[end]); start++;
end--;
}
}
 
int main() {
int numJobs;
int numWorkers;
printf("Enter the number of jobs: "); scanf("%d", &numJobs);
printf("Enter the number of workers: "); scanf("%d", &numWorkers);
int costs[numJobs][numWorkers];
printf("Enter the costs matrix:\n");
for (int i = 0; i < numJobs; i++) {
for (int j = 0; j < numWorkers; j++) {
scanf("%d", &costs[i][j]);
}
}

solveJobScheduling(costs, numJobs, numWorkers);
return 0;
}
