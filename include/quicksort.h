#ifndef QUICKSORT_H
#define QUICKSORT_H
#include <iostream>
#include <vector>

using namespace std;

template<typename Typ>
void posortujQS(vector<Typ> &tab);

template<typename Typ>
void zamienQS(vector<Typ> &tab, int index1, int index2);

template<typename Typ>
void sortujQS(vector<Typ> &tab, int lewy, int prawy);


template<typename Typ>
void zamienQS(vector<Typ> &tab, int index1, int index2){
    Typ buff = tab[index1];
    tab[index1] = tab[index2];
    tab[index2] = buff;
}

template<typename Typ>
void sortujQS(vector<Typ> &tab, int lewy, int prawy){
    if (lewy >= prawy) return;
    else {
        Typ pivot = tab[prawy];
        int granica = lewy - 1;
        int i = lewy;

        while (i < prawy){
            if (tab[i] < pivot) {
                ++granica;
                if (granica != i) zamienQS(tab, granica, i);
            }
            ++i;
        }
       ++granica;
       if (granica != prawy) zamienQS(tab, granica, i);

        sortujQS(tab, lewy, granica - 1);
        sortujQS(tab, granica + 1, prawy);
    }
}

template<typename Typ>
void posortujQS(vector<Typ> &tab){
    if (tab.size() <= 1) return;
    else{
        int dlugosc = tab.size();
        sortujQS(tab, 0, dlugosc-1);
    }
}

#endif // QUICKSORT_H
