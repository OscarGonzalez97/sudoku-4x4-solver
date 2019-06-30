#include<iostream>
#include<list>
#include<string>
#include <fstream>
#define MAX 16
using namespace std;

//En representaciones matematicas y computacionales se utilizan tipicamente enteros no negativos como colores.
//Existen 4 posibles colores (1,2,3,4) para este problema
//En cada vertice del grafo se tendra un vector de los colores que NO pueden ser, siendo asi el color restante el color que tendra ese vertice, y tambien su valor!
//El vector tendra tamanho de 4 y si el problema tiene solucion solo utilizara 3 de estos lugares, si no tiene usara los 4 y se sabra asi que el sudoku no tiene solucion
class Sudoku
{
  struct node
  {
    int data;
    bool color[4];
    list <int> adyacentes;
  };

  //matriz de nodos (cada uno va tener una lista de adyacentes en la misma)
  node tablero [MAX];

  void inicializa()
  {
    int i,j;
    list<int>::iterator it;

    i=0;
    while ( i < MAX )
    {
      it = tablero[i].adyacentes.begin();
      //por columna hare
      if(!(i%4))
      {
        //fila
        for(j=1;j<4;j++)
        {
          tablero[i].adyacentes.insert(it,tablero[i+j].data);
          ++it;
        }
        //columna
        for(j=0;j<13;j=j+4)
        {
          if(i!=j)
          {
            tablero[i].adyacentes.insert(it,tablero[j].data);
            ++it;
          }
        }
      }
      else if( i==1 || i==5 || i==9 || i==13 )
      {
        //fila
        tablero[i].adyacentes.insert(it,tablero[i-1].data);
        ++it;
        for(j=1;j<3;j++)
        {
          tablero[i].adyacentes.insert(it,tablero[i+j].data);
          ++it;
        }
        //columna
        for(j=1;j<14;j=j+4)
        {
          if(i!=j)
          {
            tablero[i].adyacentes.insert(it,tablero[j].data);
            ++it;
          }
        }
      }
      else if( i==2 || i==6 || i==10 || i==14 )
      {
        //fila
        tablero[i].adyacentes.insert(it,tablero[i+1].data);
        it++;
        for(j=1;j<3;j++)
        {
          tablero[i].adyacentes.insert(it,tablero[i-j].data);
          ++it;
        }
        //columna
        for(j=2;j<15;j=j+4)
        {
          if(i!=j)
          {
            tablero[i].adyacentes.insert(it,tablero[j].data);
            ++it;
          }
        }
      }
      else
      {
        //fila
        for(j=1;j<4;j++)
        {
          tablero[i].adyacentes.insert(it,tablero[i-j].data);
          ++it;
        }
        //columna
        for(j=3;j<MAX;j=j+4)
        {
          if(i!=j)
          {
            tablero[i].adyacentes.insert(it,tablero[j].data);
            ++it;
          }
        }
      }

      // region();
      if ( !(i%2) )
      {
        //es par
        if( (i>=0 && i<=3) || (i>=8 && i<=11) )
        {
          tablero[i].adyacentes.insert(it,tablero[i+5].data);
          ++it;
        }
        else
        {
          tablero[i].adyacentes.insert(it,tablero[i-3].data);
          ++it;
        }
      }
      else
      {
        //es impar
        if( (i>=0 && i<=3) || (i>=8 && i<=11) )
        {
          tablero[i].adyacentes.insert(it,tablero[i+3].data);
          ++it;
        }
        else
        {
          tablero[i].adyacentes.insert(it,tablero[i-5].data);
          ++it;
        }
      }

      for(j=0;j<4;j++)
      {
        tablero[i].color[j]=false;
      }
      i++;
    }
  }

  bool carga_tablero (string aAbrir)
  {
    int i=0;
    ifstream archivo(aAbrir);     // open file
    char c;

    while (archivo.get(c)) // loop getting single characters
    {
      if(c != '\n' && c != '*' && c != ' ')
      {
        tablero[i].data= c-48;
        i++;
      }
      else if ( c != '\n' && c != ' ' )
      {
        tablero[i].data=0;
        i++;
      }
    }
    archivo.close();                // close file

  }

  void imprimir()
  {
    int i=0;
    int ban=0;
    list<int>::iterator it;
    while ( i < MAX ) {
      if(tablero[i].data==0)
        cout<<'*'<<' ';
      else
        cout<<tablero[i].data<<' ';
      ban++;
      if( ban == 4 )
      {
        cout<<endl;
        ban=0;
      }
      i++;
    }
    // i=0;
    // ban=0;
    // while ( i < MAX ) {
    //   cout<<"adyacentes de "<<i<<": ";
    //   for (it=tablero[i].adyacentes.begin(); it!=tablero[i].adyacentes.end(); ++it)
    //     cout << ' ' << *it;
    //   cout<<endl;
    //   i++;
    // }
  }

  void actualiza()
  {
    int i,j;
    list<int>::iterator it;

    i=0;
    while ( i < MAX )
    {
      it = tablero[i].adyacentes.begin();
      //por columna hare
      if(!(i%4))
      {
        //fila
        for(j=1;j<4;j++)
        {
          tablero[i].adyacentes.insert(it,tablero[i+j].data);
          ++it;
        }
        //columna
        for(j=0;j<13;j=j+4)
        {
          if(i!=j)
          {
            tablero[i].adyacentes.insert(it,tablero[j].data);
            ++it;
          }
        }
      }
      else if( i==1 || i==5 || i==9 || i==13 )
      {
        //fila
        tablero[i].adyacentes.insert(it,tablero[i-1].data);
        ++it;
        for(j=1;j<3;j++)
        {
          tablero[i].adyacentes.insert(it,tablero[i+j].data);
          ++it;
        }
        //columna
        for(j=1;j<14;j=j+4)
        {
          if(i!=j)
          {
            tablero[i].adyacentes.insert(it,tablero[j].data);
            ++it;
          }
        }
      }
      else if( i==2 || i==6 || i==10 || i==14 )
      {
        //fila
        tablero[i].adyacentes.insert(it,tablero[i+1].data);
        it++;
        for(j=1;j<3;j++)
        {
          tablero[i].adyacentes.insert(it,tablero[i-j].data);
          ++it;
        }
        //columna
        for(j=2;j<15;j=j+4)
        {
          if(i!=j)
          {
            tablero[i].adyacentes.insert(it,tablero[j].data);
            ++it;
          }
        }
      }
      else
      {
        //fila
        for(j=1;j<4;j++)
        {
          tablero[i].adyacentes.insert(it,tablero[i-j].data);
          ++it;
        }
        //columna
        for(j=3;j<MAX;j=j+4)
        {
          if(i!=j)
          {
            tablero[i].adyacentes.insert(it,tablero[j].data);
            ++it;
          }
        }
      }

      // region();
      if ( !(i%2) )
      {
        //es par
        if( (i>=0 && i<=3) || (i>=8 && i<=11) )
        {
          tablero[i].adyacentes.insert(it,tablero[i+5].data);
          ++it;
        }
        else
        {
          tablero[i].adyacentes.insert(it,tablero[i-3].data);
          ++it;
        }
      }
      else
      {
        //es impar
        if( (i>=0 && i<=3) || (i>=8 && i<=11) )
        {
          tablero[i].adyacentes.insert(it,tablero[i+3].data);
          ++it;
        }
        else
        {
          tablero[i].adyacentes.insert(it,tablero[i-5].data);
          ++it;
        }
      }
      i++;
    }
  }

  void colorear()
  {
    int i=0;
    int j,k;
    list<int>::iterator it;
    int contador_color=0;
    while(!solucion())
    {
      if(!(tablero[i].data)) //si ya fue pintado(cargado previamente) no lo hara de nuevo
      {

        for (it=tablero[i].adyacentes.begin(); it!=tablero[i].adyacentes.end(); ++it)
        {
          if( ((*it)) != 0)
            tablero[i].color[(*it)-1]=true;
        }

        for(j=0;j<4;j++)
        {
          if(tablero[i].color[j] == true)
            contador_color++;
        }
        if ( contador_color == 3 )
        {
          for(j=0;j<4;j++)
          {
            if(tablero[i].color[j] == false)
              tablero[i].data=j+1;
          }
        }
      }
      contador_color=0;
      if(i == MAX-1)
        i=-1;
      actualiza();
      i++;
    }

    cout<<"La solucion es la siguiente:"<<endl;
  }


// Si devuelve 0 todavia no hay solucion si devuelve y si devuelve se resolvio
  int solucion ()
  {
    int i, j;

    for(i=0; i<MAX ;i++)
    {
      if(tablero[i].data == 0) //todavia no hay solucion
        return 0;
    }

    return 1;

  }

  public:

    //funciones
    void inicia()
    {
      inicializa();
    }

    void carga(string aAbrir)
    {
      carga_tablero(aAbrir);
      cout<<"El tablero fue cargado"<<endl;
    }

    void imprime()
    {
      imprimir();
    }

    void colorea()
    {
      colorear();
    }



};

int main()
{
  Sudoku sudoku;
  //Cargamos tablero segun el archivo que recibe esta funcion
  sudoku.carga("sudoku2.txt");
  sudoku.inicia();
  sudoku.imprime();
  sudoku.colorea();
  sudoku.imprime();
  return 0;
  //para WINDOWS
  system("PAUSE");
}
