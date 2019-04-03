#ifndef HEAP_SORT_H
#define HEAP_SORT_H
#include <iostream>
#include <vector>

using namespace std;

template<typename Typ>
void zamienHS(vector<Typ> &tab, int index1, int index2);

template<typename Typ>
void posortujHS(vector<Typ> &tab);

template<typename Typ>
void sortujHS(vector<Typ> &tab, int lewy, int prawy);


template<typename Typ>
void zamienHS(vector<Typ> &tab, int index1, int index2){
    Typ buff = tab[index1];
    tab[index1] = tab[index2];
    tab[index2] = buff;
}

template<typename Typ>
void sortujHS(vector<Typ> &tab, int ilosc_elem, int index_rodzica){
    int max = index_rodzica;
    int lewe_dziecko = index_rodzica * 2 + 1;
    int prawe_dziecko = index_rodzica * 2 + 2;

    if( lewe_dziecko < ilosc_elem && tab[lewe_dziecko] > tab[max]){
        max = lewe_dziecko;
    }

    if( prawe_dziecko < ilosc_elem && tab[prawe_dziecko] > tab[max]){
        max = prawe_dziecko;
    }

    if (max != index_rodzica){
        zamienHS(tab, max, index_rodzica);
        sortujHS(tab, ilosc_elem, max);
    }
}

template<typename Typ>
void posortujHS(vector<Typ> &tab){
    int rozm = tab.size();
    int rodzic = rozm/2 - 1;

    for (int i=rodzic; i>=0; --i){
        sortujHS(tab, rozm, i);
    }

    for (int i = rozm - 1; i > 0; --i){
        zamienHS(tab, 0, i);
        --rozm;
        sortujHS(tab, rozm, 0);
    }
}

#endif // HEAP_SORT_H
