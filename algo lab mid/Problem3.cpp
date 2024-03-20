#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& books) {
    int n = books.size();
    for (int i = 1; i < n; ++i) {
        int key = books[i];
        int j = i - 1;

        while (j >= 0 && books[j] > key) {
            books[j + 1] = books[j];
            --j;
        }
        books[j + 1] = key;
    }
}

int main() {
    std::vector<int> shelf = {5, 3, 8, 1, 2, 7, 4, 6};
    insertionSort(shelf);

    std::cout << "Sorted shelf: ";
    for (int book : shelf) {
        std::cout << book << " ";
    }
    std::cout << std::endl;

    return 0;
}
