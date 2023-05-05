#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void storeSorted(struct Node* root, int arr[], int* i) {
    if (root != NULL) {
        storeSorted(root->left, arr, i);
        arr[(*i)++] = root->data;
        storeSorted(root->right, arr, i);
    }
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->data)
        node->left = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    return node;
}

void treeSort(int arr[], int n) {
    struct Node* root = NULL;
    root = insert(root, arr[0]);

    for (int i = 1; i < n; i++)
        insert(root, arr[i]);

    int i = 0;
    storeSorted(root, arr, &i);
}

int main() {
    int arr[] = { 5, 4, 7, 2, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    treeSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
