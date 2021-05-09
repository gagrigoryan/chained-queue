#include "TwoThreeTree.h"
#include "TwoThreeNode.h"

TwoThreeTree::TwoThreeTree(TwoThreeNode &root) {
    this->root = &root;
}

void TwoThreeTree::addNode(int value) {
    if (this->root->isSheet()) {
        TwoThreeNode newRoot = TwoThreeNode();
        TwoThreeNode newNode = TwoThreeNode(value);

        if (this->root->getLabel() < value) {
            newRoot.addChild(this->root);
            newRoot.addChild(&newNode);
        } else {
            newRoot.addChild(&newNode);
            newRoot.addChild(this->root);
        }
        this->root = &newRoot;
    }
}

TwoThreeNode *TwoThreeTree::getRoot() const {
    return this->root;
}

TwoThreeNode TwoThreeTree::search(int value, TwoThreeNode &root) {
    for (int i = 1; i <= root.getSize(); ++i) {
        if (root.getNthChild(i)->isSheet()){
            return root;
        }
    }

    return TwoThreeNode();
}

