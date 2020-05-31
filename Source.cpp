#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int ndarja(int v[], int i, int j) {

    int a = v[i]; // a eshte aksi
    int m = i; // S1 dhe S2 jane fillimisht te zbrazeta
    for (int k = i + 1; k <= j; k++) { // shikojme regjionin e panjohur
        if (v[k] < a) { // rasti 2
            m++;
            swap(v[k], v[m]); // Nderrojme vendet duke perdorur funksionin e STL swap
        } // verejme se nuk duhet te bejme asgje ne rastin 1: v[k] >= a
    }
    swap(v[i], v[m]); // hapi final, nderrojme vendet e aksit dhe a[m]
    return m; // kthejme indeksin e aksit
}

void quickSort(int v[], int low, int high) {

    if (low < high) {
        int m = ndarja(v, low, high); // O(N)
        // v[low..high] ~> v[low..m–1], aksi, v[m+1..high]
        quickSort(v, low, m - 1); // sortojme nenvargun e majte me rekurzion
        // v[m] = aksi eshte tashme ne vendin e duhur pas funksionit ndarja
        quickSort(v, m + 1, high); // sortojme nenvargun e djathte
    }
}

int ndarjaRandom(int v[], int i, int j) {

    srand(time(NULL)); 
    int RandIndex = rand() % (j - i + 1); // Gjenerohet indeksi i rastesishem
    swap(v[i], v[RandIndex]); // Vendosim elementin me indeks te rastesishem ne fillim

    int a = v[i]; // a eshte aksi
    int m = i; // S1 dhe S2 jane fillimisht te zbrazeta
    for (int k = i + 1; k <= j; k++) { // shikojme regjionin e panjohur
        if (v[k] < a) { // rasti 2
            m++;
            swap(v[k], v[m]); // Nderrojme vendet duke perdorur funksionin e STL swap
        } // verejme se nuk duhet te bejme asgje ne rastin 1: v[k] >= a
    }
    swap(v[i], v[m]); // hapi final, nderrojme vendet e aksit dhe a[m]
    return m; // kthejme indeksin e aksit
}

void randomQuickSort(int v[], int low, int high) {

    if (low < high) {
        int m = ndarjaRandom(v, low, high); // O(N)
        // v[low..high] ~> v[low..m–1], aksi, v[m+1..high]
        quickSort(v, low, m - 1); // sortojme nenvargun e majte me rekurzion
        // v[m] = aksi eshte tashme ne vendin e duhur pas funksionit ndarja
        quickSort(v, m + 1, high); // sortojme nenvargun e djathte
    }
}

int main() {

    const int n = 99999;
    int* v;
    v = new int[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        v[i] = rand() % 100;
    }

    /*cout << "Vargu i gjeneruar rastesisht dhe i pasortuar: ";
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;*/

    int option;
    while (true) {
    fillimi:

        cout << "Zgjedhni nje funksion te sortimit: 1 - Quick Sort, 2 - Random Quick Sort\n:";
        cin >> option;

        if (option == 1)
            quickSort(v, 0, n - 1);
        else if (option == 2)
            randomQuickSort(v, 0, n - 1);
        else {
            cout << "Gabim!\n";
            goto fillimi;
        }

        cout << "Vargu i sortuar: ";
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }

	return 0;
}
