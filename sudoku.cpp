#include<iostream>
#include <list>

using namespace std;

//En representaciones matematicas y computacionales se utilizan tipicamente enteros no negativos como colores.
//Existen 4 posibles colores (1,2,3,4) para este problema
//En cada vertice del grafo se tendra un vector de los colores que NO pueden ser, siendo asi el color restante el color que tendra ese vertice, y tambien su valor!
//El vector tendra tamanho de 4 y si el problema tiene solucion solo utilizara 3 de estos lugares, si no tiene usara los 4 y se sabra asi que el sudoku no tiene solucion
//Entonces el vector

colores
int colores[4]={1,2,3,4};

class Sudoku
{
  struct node
  {
    int data;
    bool color[4]={false,false,false,false};
  };

  list<node> tablero;

  node* root;

};


int main()
{

  list<int> lista;
  lista.assign(0,5);
  cout<<lista.size();

    return 0;
    //para WINDOWS
    //system("PAUSE");
}
