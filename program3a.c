#include <stdio.h>

int h1(int key) {
    int x = (key + 7) * (key + 7);
    x = x / 16;
    x = x + key;
    x = x % 11;
    return x;
}

int main() {
    int table[11];
    int keys[] = {43, 23, 1, 0, 15, 31, 4, 7, 11, 3};
    int num_keys = sizeof(keys) / sizeof(keys[0]);

    // Initialize the hash table
    for (int i = 0; i < 11; i++) {
        table[i] = -1;
    }

    // Insert keys into the hash table
    for (int i = 0; i < num_keys; i++) {
        int key = keys[i];
        int home_slot = h1(key);
        printf("Key Value: %d, Home Slot: %d, Probe Sequence: ", key, home_slot);
        int probe_slot = home_slot;
        int count = 0;

        // Linear probing
        while (table[probe_slot] != -1) {
            printf("%d, ", probe_slot);
            probe_slot = (probe_slot + 1) % 11;
            count++;
        }

        // Insert the key
        table[probe_slot] = key;
        printf("%d\n", probe_slot);
    }

    // Print the final hash table
    printf("\nFinal Hash Table:\n");
    printf("Slot\tContents\n");
    for (int i = 0; i < 11; i++) {
        printf("%d\t%d\n", i, table[i]);
    }

    return 0;
}
