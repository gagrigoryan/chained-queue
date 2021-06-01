#include <iostream>
#include "TwoThreeNode.h"
#include "TwoThreeTree.h"
#include "Queue.h"

using namespace std;

int main() {
    TwoThreeNode root = TwoThreeNode(1, nullptr);
    TwoThreeTree T1 = TwoThreeTree(root);
    T1.addNode(2);
    T1.addNode(3);
    T1.addNode(4);
    T1.addNode(5);
    T1.addNode(7);
    T1.addNode(9);
    T1.addNode(8);
    T1.addNode(10);
    T1.addNode(11);
    T1.addNode(14);
    T1.addNode(13);

    cout << T1 << endl;

    TwoThreeTree *lT, *rT;
    separation(4, T1, lT, rT);

    cout << "Separation: -----------------" << endl;
    cout << *lT << endl;
    cout << *rT << endl;

    cout << "Implantation: -----------------" << endl;
    cout << implantation(*lT, *rT);

    return 0;
}
