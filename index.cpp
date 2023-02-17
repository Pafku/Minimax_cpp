#include <bits/stdc++.h>

int minimax(int board[], int depth, bool isMax, int nodeIndex, int h){
    if (depth == h){
        // std::cout << "<><> " << nodeIndex << "   " << board[nodeIndex] << "   \n";
        return board[nodeIndex];
    } //else{
    //     std::cout << "\nd: " << depth << "  n: " << nodeIndex*2 << "  1: " << nodeIndex*2 + 1 << "\n";
    // }

    if(isMax){
        int tell = std::max(minimax(board, depth+1, false, nodeIndex*2, h), 
            minimax(board, depth+1, false, nodeIndex*2 + 1, h));
        // std::cout << tell << " < Max " << depth << "\n";
        return tell;
    } else{
        int tell = std::min(minimax(board, depth+1, true, nodeIndex*2, h), 
            minimax(board, depth+1, true, nodeIndex*2 + 1, h));
        // std::cout << tell << " < Min " << depth << "\n";
        return tell;
    }
}

int log2(int n)
{
    return (n==1)? 0 : 1 + log2(n/2);
}

int main(){
    int board[] = {3, -4, 8, 2, -10, 5, 4, 2, -6, 9, 0, -2, -6, -1, 1, 3};

    int n = sizeof(board)/sizeof(board[0]);
    int h = log2(n);

    std::cout << minimax(board, 0, true, 0, h) << "\n";

    return 0; 
}
