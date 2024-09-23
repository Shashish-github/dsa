#include <stdio.h>

void towerOfHanoi(int n, char main_rod, char dest_rod, char aux_rod) {
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, main_rod, aux_rod, dest_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, main_rod, dest_rod);
    towerOfHanoi(n - 1, aux_rod, dest_rod, main_rod);
}

int main() {
    int N;
    printf("Enter the number of disks: ");
    scanf("%d", &N);
    towerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}

