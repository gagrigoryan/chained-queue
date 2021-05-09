#include <iostream>
#include "TwoThreeNode.h"
#include "TwoThreeTree.h"

using namespace std;

int main() {
    TwoThreeNode root = TwoThreeNode(30);
    TwoThreeTree tree = TwoThreeTree(root);

    tree.addNode(25);

    cout << tree.search(2, *tree.getRoot());

    return 0;
}
