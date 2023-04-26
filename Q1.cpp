#include <iostream>

using namespace std;

int* intersection(int* list1, int size1, int* list2, int size2, int& resultSize) {
    int intersectionSize = 0;

    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (list1[i] == list2[j]) {
                intersectionSize++;
                break;
            }
        }
    }

    int* intersectionList = new int[intersectionSize];
    int index = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (list1[i] == list2[j]) {
                intersectionList[index] = list1[i];
                index++;
                break;
            }
        }
    }

    resultSize = intersectionSize;
    return intersectionList;
}

int main() {
    int list1[] = {1, 2, 3, 4, 5};
    int size1 = 5;
    int list2[] = {2, 3, 5, 6, 7};
    int size2 = 5;

    int resultSize = 0;
    int* intersectlist = intersection(list1, size1, list2, size2, resultSize);
    for (int i = 0; i < resultSize; i++) {
        cout << intersectlist[i] << " ";
    }
    cout << endl;

    delete[] intersectlist;

    return 0;
}
