#ifndef MERGE_SORT_H
#define MERGE_SORT_H
#include <iostream>
#include <vector>

using namespace std;

template<typename Typ>
void sortujM(vector<Typ> &lewyCiag, vector<Typ> &prawyCiag, vector<Typ> &tab);

template<typename Typ>
void posortujMS(vector<Typ> &tab);

template<typename Typ>
void sortujMS(vector<Typ> &lewyCiag, vector<Typ> &prawyCiag, vector<Typ> &tab){
    int lewa = lewyCiag.size();
    int prawa = prawyCiag.size();
    int i = 0, l = 0, p = 0;

    while ( l < lewa && p < prawa){
        if (lewyCiag[l] < prawyCiag[p]){
            tab[i] = lewyCiag[l];
            ++l;
        }
        else{
            tab[i] = prawyCiag[p];
            ++p;
        }
        ++i;
    }

    while (l < lewa) {
        tab[i] = lewyCiag[l];
        ++l; ++i;
    }

    while (p < prawa) {
        tab[i] = prawyCiag[p];
        ++p; ++i;
    }
}

template<typename Typ>
void posortujMS(vector<Typ> &tab){
    if (tab.size() <= 1) return;
    else {
        vector<Typ> lewyCiag;
        vector<Typ> prawyCiag;
        int srodek = 0;
        if (tab.size() % 2 == 0) srodek = tab.size()/2;
        else srodek = tab.size()/2 + 1;

        for (int i = 0; i < srodek; ++i){
            lewyCiag.push_back(tab[i]);
        }
        for (int i = 0; i < tab.size() - srodek; ++i){
            prawyCiag.push_back(tab[srodek + i]);
        }
        posortujMS(lewyCiag);
        posortujMS(prawyCiag);
        sortujMS(lewyCiag, prawyCiag, tab);
    }
}

#endif // MERGE_SORT_H
