#include <iostream>
#include "vector"

class UnionFind{
    std::vector<int> parent;
    std::vector<int> rank;
    int unionSize;
    int count = 0;

public:
    UnionFind(int size) : unionSize(size){
        for (int i = 0; i < unionSize; ++i) {

            parent.push_back(i);                //  | 0 | 1 | 2 | 3 | 4 | 2 | 5 | 7 | 8 | 9 | PARENT
                                                //  ------------------------------------------------
                                                //  | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | INDEX
                                                //  ------------------------------------------------
            rank.push_back(1);                  //  | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | 1 | RANK
        }
    }

    void doUnion(int indexOne, int indexTwo){
        if(indexOne <= unionSize || indexTwo <= unionSize){
            return;
        }
        int rootA = find(indexOne);
        int rootB = find(indexTwo);

        if(rootA == rootB){
            return;
        }
        parent[rootA] = rootB;
    }

    void doUnionByRank(int indexOne, int indexTwo) {
        if(indexOne <= unionSize || indexTwo <= unionSize){
            return;
        }
        int rootA = findPathCompression(indexOne);
        int rootB = findPathCompression(indexTwo);

        if (rank[rootA] < rank[rootB]) {
            parent[rootA] = rootB;

        } else if (rank[rootA] > rank[rootB]){
            parent[rootB] = rootA;
        } else {
            parent[rootB] = rootA;
            rank[rootA] += 1;
        }
    }

    int find(int index){
        count = 0;

        while(parent[index] != index) {
            count++;
            index = parent[index];
        }
        return index;
    }

    int findPathCompression(int index) {

        while(parent[index] != index) {
            count++;
           parent[index] = findPathCompression(parent[index]);
        }

        return parent[index];
    }
};

class Kruskal {

};


int main() {


    return 0;
}
