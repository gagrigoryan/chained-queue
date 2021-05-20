#include <iostream>
#include "TwoThreeNode.h"
#include "TwoThreeTree.h"

using namespace std;

int main() {
    TwoThreeNode root = TwoThreeNode(5, 9, nullptr);
    TwoThreeNode a = TwoThreeNode(3, 5, &root);
    TwoThreeNode a_ = TwoThreeNode(7, 9, &root);
    TwoThreeNode b = TwoThreeNode(1, 3, &a);
    TwoThreeNode c = TwoThreeNode(4, 5, &a);
    TwoThreeNode c_ = TwoThreeNode(6, 7, &a_);
    TwoThreeNode d = TwoThreeNode(8, 9, &a_);

    TwoThreeNode sheet1 = TwoThreeNode(1, &b);
    TwoThreeNode sheet2 = TwoThreeNode(3, &b);
    TwoThreeNode sheet3 = TwoThreeNode(4, &c);
    TwoThreeNode sheet4 = TwoThreeNode(5, &c);
    TwoThreeNode sheet5 = TwoThreeNode(6, &c_);
    TwoThreeNode sheet6 = TwoThreeNode(7, &c_);
    TwoThreeNode sheet7 = TwoThreeNode(8, &d);
    TwoThreeNode sheet8 = TwoThreeNode(9, &d);

    b.addChild(&sheet1);
    b.addChild(&sheet2);
    c.addChild(&sheet3);
    c.addChild(&sheet4);
    c_.addChild(&sheet5);
    c_.addChild(&sheet6);
    d.addChild(&sheet7);
    d.addChild(&sheet8);

    a.addChild(&b);
    a.addChild(&c);
    a_.addChild(&c_);
    a_.addChild(&d);

    root.addChild(&a);
    root.addChild(&a_);

    TwoThreeTree tree = TwoThreeTree(root);

    TwoThreeNode searchResult = tree.search(12, root);

    a.addChildToRight(b, sheet8);
    a.addChildToRight(c, sheet3);

    TwoThreeNode child1 = *a[0];
    TwoThreeNode child2 = *a[1];
    TwoThreeNode child3 = *a[2];
    TwoThreeNode child4 = *a[3];

    cout << child1 << endl << child2 << endl << child3 << endl << child4;

    return 0;
}
