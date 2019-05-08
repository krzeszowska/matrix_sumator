#ifndef NEIGHBOURMATRIX_H
#define NEIGHBOURMATRIX_H

#include <iostream>
#include <iomanip>
#include <vector>

class NeighbourMatrix
{

    int **data; //! tablica kwadratowa przechowujaca polaczenia
    int verts; //! info jak duza jest tablica

    /* wylaczenie mozliwosci kopiowania obiektu*/
    NeighbourMatrix(const NeighbourMatrix&);
    NeighbourMatrix& operator=(const NeighbourMatrix&);


public:

    /**
     * @brief NeighbourMatrix
     * @param verts - ilosc wierzcholkow jak ma miec graf
     */
    NeighbourMatrix(int verts);

    ~NeighbourMatrix();

    /**
     * @brief addEdge funkcja tworzy krawedz pomiedzy wyznazonymi werzcholkami
     * @param vert1
     * @param vert2
     * @param factor - wartosc (waga) polaczenia
     * @return false - krawedz nie istniala i zostala utworzona
     */
    bool addEdge(int vert1, int vert2, int factor = 1);

    int size() const;

    /**
     * @brief edge zwraca wartosc w komorce data[vert1][vert2]
     * @param vert1
     * @return
     */
    int edge(int vert1, int vert2) const;
    int edge(int vert1, int vert2);

    /**
     * @brief neighbours funckja zwraca wektor sasiadow podanego wierzcholka
     * @param vert
     * @return
     *
     *
     * Uzycie:
        cout<<"neighbours("<<vert<<"): "<<graph.neighbours(vert)<<endl;
     */
    std::vector<int> neighbours(int vert) const;


    /**
     * @brief edges funkcja zwraca wszystkie krawedzie grafu
     * @return wektor zawierajacy 2*verts komorek.
     * w komorach [i, i+1] znajduja sie numery wierzcholkow tworzacych krawedz
     */
    std::vector<int> edges() const;
};

std::ostream& operator << (std::ostream& str, const NeighbourMatrix& matrix);

#endif // NEIGHBOURMATRIX_H
