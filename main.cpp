#include <iostream>
#include "TwoThreeNode.h"
#include "TwoThreeTree.h"

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
    TwoThreeNode d = TwoThreeNode(10, 12, &a);

    TwoThreeNode sheet1 = TwoThreeNode(1, &b);
    TwoThreeNode sheet2 = TwoThreeNode(3, &b);
    TwoThreeNode sheet3 = TwoThreeNode(4, &b);
    TwoThreeNode sheet4 = TwoThreeNode(6, &b);
    TwoThreeNode sheet5 = TwoThreeNode(7, &b);
    TwoThreeNode sheet6 = TwoThreeNode(10, &b);
    TwoThreeNode sheet7 = TwoThreeNode(12, &b);

    b.addChild(&sheet1);
    b.addChild(&sheet2);

    c.addChild(&sheet3);
    c.addChild(&sheet4);
    c.addChild(&sheet5);

    d.addChild(&sheet6);
    d.addChild(&sheet7);

    a.addChild(&b);
    a.addChild(&c);
    a.addChild(&d);

    TwoThreeTree tree = TwoThreeTree(a);

    // to do sorting sheets
    tree.addNode(5);
    tree.addNode(16);
    tree.addNode(9);

    tree.print(&tree.getRoot(), 0);

    return 0;
}
