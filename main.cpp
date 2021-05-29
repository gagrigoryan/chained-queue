#include <iostream>
#include "TwoThreeNode.h"
#include "TwoThreeTree.h"
#include "Queue.h"

using namespace std;

int main() {
//    TwoThreeNode root = TwoThreeNode(5, 9, nullptr);
//    TwoThreeNode a = TwoThreeNode(3, 5, &root);
//    TwoThreeNode a_ = TwoThreeNode(7, 9, &root);
//    TwoThreeNode b = TwoThreeNode(1, 3, &a);
//    TwoThreeNode c = TwoThreeNode(4, 5, &a);
//    TwoThreeNode c_ = TwoThreeNode(6, 7, &a_);
//    TwoThreeNode d = TwoThreeNode(8, 9, &a_);
//
//    TwoThreeNode sheet1 = TwoThreeNode(1, &b);
//    TwoThreeNode sheet2 = TwoThreeNode(3, &b);
//    TwoThreeNode sheet3 = TwoThreeNode(4, &c);
//    TwoThreeNode sheet4 = TwoThreeNode(5, &c);
//    TwoThreeNode sheet5 = TwoThreeNode(6, &c_);
//    TwoThreeNode sheet6 = TwoThreeNode(7, &c_);
//    TwoThreeNode sheet7 = TwoThreeNode(8, &d);
//    TwoThreeNode sheet8 = TwoThreeNode(9, &d);
//
//    b.addChild(&sheet1);
//    b.addChild(&sheet2);
//    c.addChild(&sheet3);
//    c.addChild(&sheet4);
//    c_.addChild(&sheet5);
//    c_.addChild(&sheet6);
//    d.addChild(&sheet7);
//    d.addChild(&sheet8);
//
//    a.addChild(&b);
//    a.addChild(&c);
//    a_.addChild(&c_);
//    a_.addChild(&d);
//
//    root.addChild(&a);
//    root.addChild(&a_);
//
//    TwoThreeTree tree = TwoThreeTree(root);

    TwoThreeNode a = TwoThreeNode(3, 7, nullptr);
    TwoThreeNode b = TwoThreeNode(1, 3, &a);
    TwoThreeNode c = TwoThreeNode(4, 6, &a);

    TwoThreeNode sheet1 = TwoThreeNode(1, &b);
    TwoThreeNode sheet2 = TwoThreeNode(3, &b);
    TwoThreeNode sheet3 = TwoThreeNode(4, &b);
    TwoThreeNode sheet4 = TwoThreeNode(6, &b);
    TwoThreeNode sheet5 = TwoThreeNode(7, &b);

    b.addChild(&sheet1);
    b.addChild(&sheet2);

    c.addChild(&sheet3);
    c.addChild(&sheet4);
    c.addChild(&sheet5);

    a.addChild(&b);
    a.addChild(&c);

    TwoThreeNode a1 = TwoThreeNode(3, 7, nullptr);
    TwoThreeNode b1 = TwoThreeNode(1, 3, &a1);
    TwoThreeNode c1 = TwoThreeNode(4, 6, &a1);

    TwoThreeNode sheet11 = TwoThreeNode(13, &b1);
    TwoThreeNode sheet21 = TwoThreeNode(15, &b1);
    TwoThreeNode sheet31 = TwoThreeNode(20, &c1);
    TwoThreeNode sheet41 = TwoThreeNode(31, &c1);
    TwoThreeNode sheet51 = TwoThreeNode(40, &c1);

    b1.addChild(&sheet11);
    b1.addChild(&sheet21);

    c1.addChild(&sheet31);
    c1.addChild(&sheet41);
    c1.addChild(&sheet51);

    a1.addChild(&b1);
    a1.addChild(&c1);

    TwoThreeTree tree = TwoThreeTree(a);
    TwoThreeTree tree2 = TwoThreeTree(a1);
    TwoThreeTree *leftTree, *rightTree;
    tree2.addNode(32);
    tree2.addNode(22);
    tree2.addNode(24);
    tree.addNode(5);
    tree.addNode(12);
    tree.addNode(9);
    Queue q = Queue(tree);
    TwoThreeTree* impTree = &q.implantation(tree, tree2);

    Queue impQ = Queue(*impTree);
    impQ.separation(6, *impTree, leftTree, rightTree);
    cout << *leftTree << endl << endl << endl;
    cout << *rightTree << endl;


//    TwoThreeNode root = TwoThreeNode(1, nullptr);
//    TwoThreeNode impNode = TwoThreeNode(6, nullptr);
//    TwoThreeNode child1 = TwoThreeNode(1, 3, nullptr);
//    TwoThreeNode child2 = TwoThreeNode(1, 3, nullptr);
//    TwoThreeNode child3 = TwoThreeNode(1, 3, nullptr);
//    TwoThreeNode child4 = TwoThreeNode(1, 3, nullptr);
//    TwoThreeTree t1 = TwoThreeTree(root);
//    TwoThreeTree impTree = TwoThreeTree(impNode);
//    t1.addNode(3);
//    t1.addNode(5);
//    t1.addNode(4);
//    cout << t1 << endl;
//    Queue q = Queue(t1);
//    cout << q.implantation(t1, impTree) << endl;
    return 0;
}
