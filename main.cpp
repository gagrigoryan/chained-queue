#include <iostream>
#include "TwoThreeNode.h"
#include "TwoThreeTree.h"
#include "Queue.h"

using namespace std;

int main() {
    TwoThreeNode root = TwoThreeNode(1, nullptr);
    TwoThreeNode root2 = TwoThreeNode(6, nullptr);
    TwoThreeTree T1 = TwoThreeTree(root);
    TwoThreeTree T2 = TwoThreeTree(root2);
    T1.addNode(2);
    T1.addNode(3);
    T1.addNode(4);
    T1.addNode(5);
    T1.addNode(6);

    T2.addNode(7);

    Queue q = Queue(T1);

    cout << q.implantation(T2, T1) << endl;

    return 0;
}
