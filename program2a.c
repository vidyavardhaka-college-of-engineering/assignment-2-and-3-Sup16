#include <stdio.h>
int calculateAssignments(int n, int preferences[n][n]) {
    int assignments = 1;
    for (int i = 0; i < n; i++) {
        int likes = 0;
        for (int j = 0; j < n; j++) {
            if (preferences[i][j] == 1) {
                likes++;
            }
        }
        assignments *= likes;
    }
    return assignments;
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    int preferences[n][n];
    for (int i = 0; i < n; i++) {
        printf("Enter preferences for student %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &preferences[i][j]);
        }
    }

    int assignments = calculateAssignments(n, preferences);
    printf("Number of different assignments: %d\n", assignments);

    return 0;
}
