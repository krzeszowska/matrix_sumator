#include <vector>
#include <iostream>
#include "include/merge_sort.h"
#include "include/quicksort.h"
#include "include/heap_sort.h"
#include <sys/time.h>

using namespace std;

void generuj_inty(int ilosc, int min, int max){
    int r = max - min;
    int wart;
    for(int i=0; i<ilosc; ++i){
        wart = rand() % r + min;
        cout << wart << endl;
        cerr<< "generowanie "<<i;
    }
}

void generuj_floaty(int ilosc, float min, float max, int precyzja){
    int r = (max - min) * precyzja;
    float wart;
    for(int i=0; i<ilosc; ++i){
        wart = (float)(rand() % r)/precyzja + min;
        cout << wart << endl;
        cerr<< "generowanie "<<i;
    }
}

unsigned long czas_procesu(){
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return 1000000 * tv.tv_sec + tv.tv_usec;
}

template<typename Typ>
void tester(){
    Typ zmienna;
    unsigned long start;
    vector<Typ> buff, tab;
    while(cin >> zmienna){
        tab.push_back(zmienna);
    }
    cout << "wczytano: " << tab.size() << endl;

    buff=tab;
    start = czas_procesu();
    posortujQS(buff);
    cout << "QS: "<<(czas_procesu() - start)/1000.f << "ms" << endl;

        for (size_t i = 1; i < buff.size(); i++){
        if(buff[i-1] > buff[i]) {
            cerr << "zle posortowano" << i << endl;
            return;
        }
    }

    buff=tab;
    start = czas_procesu();
    posortujMS(buff);
    cout << "MS: " << (czas_procesu() - start)/1000.f << "ms" << endl;


    for (size_t i = 1; i < buff.size(); i++){
        if(buff[i-1] > buff[i]) {
            cerr << "zle posortowano" << i << endl;
            return;
        }
    }

    buff=tab;
    start = czas_procesu();
    posortujHS(buff);
    cout << "HS: " << (czas_procesu() - start)/1000.f << "ms" << endl;


    for (size_t i = 1; i < buff.size(); i++){
        if(buff[i-1] > buff[i]) {
            cerr << "zle posortowano" << i << endl;
           // return;
        }
    }

}

int main() {

// Podczas testowania programu strumien wejsciowy zostal przekierowany na odpowiedni dla danego testu plik z katalogu testy

    tester<int>();
  //  tester<float>();
   // generuj_floaty(900000, 10.987, 1000.002, 1000);
   // generuj_inty(400, 0, 10000);

 /*   vector<int> ciag;
    for (size_t i = 0; i < 100; i++)
        ciag.push_back(rand() % 1000);

    posortujHS(ciag);

    for (size_t i = 0; i < ciag.size(); i++)
        cout << ciag[i] << endl;
*/

    return 0;
}
