#include <iostream>

const int MAXDIM = 10;

//------DO NOT CHANGE ANYTHING ABOVE THIS LINE-------

using namespace std;

void read_matrix(int m[MAXDIM][MAXDIM], int& d){

  cin >> d;

  for (int i=0; i<d; ++i){
    for (int j=0; j<d; ++j){
      cin >> m[i][j];
    }
  }

}

void display_inner_cw_rotated(int m[MAXDIM][MAXDIM], int d){

  for (int i=1; i<d-1; ++i){
    for (int j=d-2; j>0; --j){
      cout << m[j][i] << " ";
    }
    cout << endl;
  }

}

//------DO NOT CHANGE ANYTHING BELOW THIS LINE-------

int main()
{
  int matrix[MAXDIM][MAXDIM]{};
  int dim = 0;

  read_matrix(matrix, dim);
  display_inner_cw_rotated(matrix, dim);

  return 0;
}
