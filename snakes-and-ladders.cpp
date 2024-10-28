#include <iostream>
#include <deque>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> myBoard = {
                                  {-1,-1,-1,-1,-1,-1},
                                  {-1,-1,-1,-1,-1,-1},
                                  {-1,-1,-1,-1,-1,-1},
                                  {-1,35,-1,-1,13,-1},
                                  {-1,-1,-1,-1,-1,-1},
                                  {-1,15,-1,-1,-1,-1}
                                  };
    Solution(){
        cout << "Output: " << snakesAndLadders(myBoard);
    }


        vector<vector<bool>> visited(n, vector<bool>(n, false));


        //add initial values to queue and visited array
        myQueue->push_back(1);

        int* pos = nullptr;              //array to keep track of each position currently being processed
        bool done = false;
        int frontOfQueue;
        int minAttempts = 0;
        int posVal;
        int myQueueSize;
        //doneLabel:
        while( myQueue->size() && !done ){
            myQueueSize = myQueue->size();
            while( myQueueSize-- > 0 && !done ){
                frontOfQueue = myQueue->front();
                myQueue->pop_front();

                for( int diceVal = 1; diceVal <= 6; diceVal++ ){
                    pos = getCoordinates(frontOfQueue+diceVal,n);     //get current position (allocates dynamic memory)
                    posVal = getValueAt(pos,n,board);                 //get value at that position
                    
                    if( diceVal+frontOfQueue > n*n ) continue;
                    if( visited[pos[0]][pos[1]] ) continue;                   //break out of inner loop if position has been visited
                    if( posVal == n*n ){                              //break out of loops if final destination is reached
                        done = true;  
                        break; 
                    }

                    visited[pos[0]][pos[1]] = true;                    //else add position to visited array
                    myQueue->push_back(posVal);                       //add position value to queue
                    //delete pos;                                       //delete dynamically allocated memory
                }
            }
            ++minAttempts;
        }

        delete myQueue;
        return minAttempts;
    }


    //getCoordinates
    //recieves:
    //      an int representing how far off from the origin we are looking at
    //      an int representing the number of rows and also columns (size of board n*n)
    //returns: an array representing the coordinates of the board( bottom left corner is 0,0 )
    int* getCoordinates(int v, int n){
        int row = n - ( v - 1) / n - 1;        //set row
        int col = (v - 1) % n;
        int arr[2];

        if( row%2 == n%2 ) return new int[2]{row, n-1-col};
        else return new int[2]{row,col};

        return arr;
    }

    //getValueAt
    //recieves: an array representing the position to be looking at
    //          an int representing the row/column dimension
    //returns: the value at that position
    int getValueAt(int* posArr, int n,const vector<vector<int>>& board){
        int val;
        int row = posArr[0];
        int col = posArr[1];
        //check if the value on the board vector is -1
        if( board[ posArr[0] ][ posArr[1] ] == -1){
            //if so, calculate what value should be represented at that position
            if( posArr[0] % 2 == 0){ //even row case
                val = n*n-(posArr[0]*n) - posArr[1];     //n*n - (row*n) - col
            } else {                //odd row case
                val = (n*n-(posArr[0]*n)) - (n - (posArr[1] + 1)); //n*n - (n - (n+1))
            }

        } else {
            //otherwise, the return the value of that position on the board (a snake or ladder move)
            val = board[ posArr[0] ][ posArr[1] ];
        }

        return val;
    }

};


int main(){
    Solution mySolution;
    return 0;
}