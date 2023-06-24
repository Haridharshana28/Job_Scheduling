void printAssignment(int assignment[], int numJobs) {
printf("Optimal Assignment:\n");
for (int i = 0; i < numJobs; i++) {
printf("Job %d assigned to Worker %d\n", i + 1, assignment[i] + 1);
}
}	

void solveJobScheduling(int costs[][3], int numJobs, int numWorkers) { int assignment[3] = {0};
int workerCapacities[3] = {0};

for (int job = 0; job < numJobs; job++) {
int minCost = -1;
int minCostWorker = -1;

for (int worker = 0; worker < numWorkers; worker++) {
if (workerCapacities[worker] == 0) { assignment[job] = worker; workerCapacities[worker] = 1; break;}
 
else {
 

if (minCost == -1 || costs[job][worker] < minCost) { minCost = costs[job][worker];
minCostWorker = worker;
 
}
}
}

if (assignment[job] == -1) {
assignment[job] = minCostWorker; workerCapacities[minCostWorker] = 1;
}
}

printAssignment(assignment, numJobs);
}
 
int main() {
int numJobs;
int numWorkers;
printf("Enter the number of jobs: ");
scanf("%d", &numJobs);
printf("Enter the number of workers: "); scanf("%d", &numWorkers);
int costs[numJobs][numWorkers];
printf("Enter the costs matrix:\n"); for (int i = 0; i < numJobs; i++) {
for (int j = 0; j < numWorkers; j++) {
scanf("%d", &costs[i][j]);
}
}
solveJobScheduling(costs, numJobs, numWorkers);

return 0;
}
