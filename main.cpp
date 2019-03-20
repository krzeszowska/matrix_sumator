#include <iostream>
#include <list>
#include <stack>
#include <queue>

using namespace std;

template <typename Typ>
std::ostream& operator << (std::ostream& str, list<Typ>& obj){
    for (int n : obj) {
        str << n << '\n';
    }
    return str;
}

void testListy(){
    list<int> lista;
    lista.push_front(1);
    lista.push_front(2);
    lista.push_back(29);
    list<int>::iterator i = lista.begin();
    lista.insert(++++i,22);
    lista.insert(----i,10);
    lista.push_back(12);
    lista.push_back(11);
    lista.pop_front();
    lista.pop_back();
    lista.erase(i);
   // cout << lista;
}

void testStosu(){
    stack<int> stos;
    stos.push(1);
    stos.push(2);
    stos.push(3);
    stos.pop();
    stos.pop();
}

void testKolejki(){
    queue<int> kolejka;
    kolejka.push(1);
    kolejka.push(2);
    kolejka.push(3);
    kolejka.pop();
    kolejka.pop();
}



int main()
{
    testStosu();
    testListy();
    testKolejki();
    return 0;
}





















