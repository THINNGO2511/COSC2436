#include "ArgumentManager.h"
#include "Queue.h"
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector< vector <char> > moveUp(vector< vector <char> > &matrix, size_t row, size_t col)
{
    Stack s;
    int counter = 0;
    char temp;

    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            // if (matrix[i][j] != 'O' && matrix[i][j] != 'X')
            if (matrix[i][j]=='B')
            {
                if (!s.isEmpty() && s.peek() == 'B')
                {
                    temp = s.pop();
                    s.push('X');
                }
                else
                    s.push(matrix[i][j]);
            }
            else if (matrix[i][j] == 'X')
            {
                while (s.getSize() < counter)
                    s.push('O');
                s.push('X');
            }
            counter++;
        }

        while (s.getSize() < counter){
            s.push('O');
        }

        for (int i = row - 1; i >= 0; i--){
            matrix[i][j] = s.pop();
        }

        counter = 0;
    }
    return matrix;
}

vector< vector <char> > moveDown(vector< vector <char> > &matrix, size_t row, size_t col)
{
    Stack s;
    int counter = 0;
    char temp;

    for (int j = 0; j < col; j++)
    {
        // for (int i = 0; i < row; i++)
        for (int i = row - 1; i >= 0; i--)
        {
            if (matrix[i][j]=='B')
            {
                if (!s.isEmpty() && s.peek() == 'B')
                {
                    temp = s.pop();
                    s.push('X');
                }
                else
                    s.push(matrix[i][j]);
            }
            else if (matrix[i][j] == 'X')
            {
                while (s.getSize() < counter)
                    s.push('O');
                s.push('X');
            }
            counter++;
        }

        while (s.getSize() < counter){
            s.push('O');
        }

        for(int i=0; i<row; i ++){
          matrix[i][j] = s.pop();
        }
        counter = 0;
    }
    return matrix;
}

vector< vector <char> > moveLeft(vector< vector <char> > &matrix, size_t row, size_t col)
{
    Stack s;
    int counter = 0;
    char temp;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j]=='B')
            {
                if (!s.isEmpty() && s.peek() == 'B')
                {
                    temp = s.pop();
                    s.push('X');
                }
                else
                    s.push(matrix[i][j]);
            }
            else if (matrix[i][j] == 'X')
            {
                while (s.getSize() < counter)
                    s.push('O');
                s.push('X');
            }
            counter++;
        }

        while (s.getSize() < counter){
            s.push('O');
        }

        for(int j = col - 1; j >= 0; j--){
          matrix[i][j] = s.pop();
        }
        counter = 0;
    }
    return matrix;
}

vector< vector <char> > moveRight(vector< vector <char> > &matrix, size_t row, size_t col)
{
    Stack s;
    int counter = 0;
    char temp;

    for (int i = 0; i < row; i++)
    {
        // for (int j = 0; j < col; j++)
         for (int j = col - 1; j >= 0; j--) 
        {
            if (matrix[i][j]=='B')
            {
                if (!s.isEmpty() && s.peek() == 'B')
                {
                    temp = s.pop();
                    s.push('X');
                }
                else
                    s.push(matrix[i][j]);
            }
            else if (matrix[i][j] == 'X')
            {
                while (s.getSize() < counter)
                    s.push('O');
                s.push('X');
            }
            counter++;
        }

        while (s.getSize() < counter){
            s.push('O');
        }

        for(int j = 0; j < col; j++){
          matrix[i][j] = s.pop();
        }
        counter = 0;
    }
    return matrix;
}

bool isSolved(vector< vector <char> > &matrix, size_t row, size_t col){
    for(int i = 0; i< row; i++){
        for(int j = 0; j < col; j++){
            if(matrix[i][j]=='B'){
                return false;
            }
        }
    }
    return true;
}

vector< vector <char> > copyMatrix(vector< vector <char> > &matrix){
    return matrix;
}

bool pathFinder(vector< vector <char> > matrix,  Queue q, Pair p, string result, size_t row, size_t col, ofstream &out){// watchout for &matrix, might wanna return that instead
    // creating 4 cases and enqueue them into q

    if(isSolved(matrix, row, col)){
        out<<q.peek().moves<<endl;
        return true;
    }else{
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                cout << matrix[i][j];
            }
            cout<<endl;
        }
        q.dequeue();
    }

    //pushing moveUp
    vector< vector <char> > matrix1 = copyMatrix(matrix);
    p.matrix = moveUp(matrix1, row, col);
    p.moves = result+"1";
    q.enqueue(p);

    //pushing moveUp
    vector< vector <char> > matrix2 = copyMatrix(matrix);
    p.matrix = moveRight(matrix2, row, col);
    p.moves = result+"2";
    q.enqueue(p);

    //pushing moveUp
    vector< vector <char> > matrix3 = copyMatrix(matrix);
    p.matrix = moveDown(matrix3, row, col);
    p.moves = result+"3";
    q.enqueue(p);

    //pushing moveUp
    vector< vector <char> > matrix4 = copyMatrix(matrix);
    p.matrix = moveLeft(matrix4, row, col);
    p.moves = result+"4";
    q.enqueue(p);

    // for(int i = 0; i < matrix.size(); i++){
    //     for(int j = 0; j < matrix[i].size(); j++){
    //         cout << matrix[i][j];
    //     }
    //     cout<<endl;
    // }


    // if(isSolved(matrix, row, col)){
    //     out<<q.peek().moves<<endl;
    //     return true;
    // }else{
    //     q.dequeue();
    //     for(int i = 0; i < matrix.size(); i++){
    //         for(int j = 0; j < matrix[i].size(); j++){
    //             cout << matrix[i][j];
    //         }
    //         cout<<endl;
    //     }
    // }

    pathFinder(q.peek().matrix, q, p, q.peek().moves, row, col, out);
    //case analysis: must enqueue all 4 case then pop, what we are doin rn is bsically DFS, that's why it doesn't work
}

void addPath(Queue &q, Pair p, int move, size_t row, size_t col) {
  Pair temp;
  temp.matrix = p.matrix;
  temp.moves = p.moves;

  switch (move) {
  case 1:
    moveUp(temp.matrix, row, col);
    if (temp.matrix != p.matrix) {
      temp.moves += "1";
      q.enqueue(temp);
    }
    break;

  case 2:
    moveRight(temp.matrix, row, col);
    if (temp.matrix != p.matrix) {
      temp.moves += "2";
      q.enqueue(temp);
    }
    break;

  case 3:
    moveDown(temp.matrix, row, col);
    if (temp.matrix != p.matrix) {
      temp.moves += "3";
      q.enqueue(temp);
    }
    break;

  case 4:
    moveLeft(temp.matrix, row, col);
    if (temp.matrix != p.matrix) {
      temp.moves += "4";
      q.enqueue(temp);
    }
    break;
  }
}



int main(int argc, char *argv[]) {
  ArgumentManager am(argc, argv);
  ifstream input(am.get("input"));
  ofstream output(am.get("output"));

//   ifstream input("input5.txt");
//   ofstream output("output1.txt");

  size_t row;//size_t is technically 64-bit integer (normal integer can hold 32 bits)
  size_t col;
  input >> row; // input row
  input >> col; // input column

  vector< vector <char> > matrix; // input matrix

  // reading the matrix from the input
  for (int i = 0; i < row; i++) {
    vector<char> temp;
    for (int j = 0; j < col; j++) {
      char c;
      input >> c;
      temp.push_back(c);
    }
    matrix.push_back(temp);
  }

  Pair p;
  p.matrix = matrix;// setting queue matrix to original matrix
  p.moves;// setting moves to default empty

  Queue q;
  q.enqueue(p);

  string result="";

//   if(pathFinder(matrix, q, p, result, row, col, output)){
//     cout<<"ok";
//   }

  while (!q.isEmpty()) {
    p = q.dequeue();
    if (isSolved(p.matrix, row, col)) {
      if (p.moves == "")
      {
        //cout << 0;
        output << 0;
        }
      else {
        //cout << temp.moves;
        output << p.moves;
      } 
      break; 
    } else {
      addPath(q, p, 1, row, col);
      addPath(q, p, 2, row, col);
      addPath(q, p, 3, row, col);
      addPath(q, p, 4, row, col);
    }
  }

//   for(int i = 0; i < matrix.size(); i++){
//     for(int j = 0; j < matrix[i].size(); j++){
//       cout << matrix[i][j];
//     }
//     cout<<endl;
//   }

  return 0;
}
