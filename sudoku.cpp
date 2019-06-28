#include<iostream>
#include <list>

using namespace std;

struct node
{
  int data=0;
  bool color[4]={false,false,false,false};
};

//En representaciones matematicas y computacionales se utilizan tipicamente enteros no negativos como colores.
//Existen 4 posibles colores (1,2,3,4) para este problema
//En cada vertice del grafo se tendra un vector de los colores que NO pueden ser, siendo asi el color restante el color que tendra ese vertice, y tambien su valor!
//El vector tendra tamanho de 4 y si el problema tiene solucion solo utilizara 3 de estos lugares, si no tiene usara los 4 y se sabra asi que el sudoku no tiene solucion
//Entonces el vector

// colores
// int colores[4]={1,2,3,4};
//
class Sudoku
{
  //Constructor?
  list<node> tablero;

  public:
  //funciones


};

int main()
{
  Sudoku sudoku;
  //aca voy hacer por ejemplo
  //sudoku.carga_tablero()


  // for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
  // std::cout << *it << ' ';
  //cout << "size: " << tablero.size() << '\n';
  return 0;
  //para WINDOWS
  //system("PAUSE");
}

