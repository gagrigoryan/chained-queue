#include "fstream"

using namespace std;

class TwoThreeTree;

class Queue {
public:
    Queue(TwoThreeTree &tree);

    TwoThreeTree& implantation(TwoThreeTree &T1, TwoThreeTree &T2);
    void separation(int a, TwoThreeTree &T, TwoThreeTree *&leftTree, TwoThreeTree *&rightTree);

    TwoThreeTree& tree;
};

ostream & operator << (ostream & stream, Queue queue);
