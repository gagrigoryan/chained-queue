#include "TwoThreeTree.h"
#include "TwoThreeNode.h"

TwoThreeTree::TwoThreeTree(TwoThreeNode &root) {
    this->root = &root;
}

void TwoThreeTree::addNode(int value) {
    if (this->root->isSheet()) {
        TwoThreeNode newRoot = TwoThreeNode(nullptr);
        TwoThreeNode newNode = TwoThreeNode(value, &newRoot);

        if (this->root->getLabel() < value) {
            newRoot.addChild(this->root);
            this->root->setParent(&newRoot);
            newRoot.addChild(&newNode);
        } else {
            newRoot.addChild(&newNode);
            newRoot.addChild(this->root);
        }
        this->root = &newRoot;
    } else {
        if (this->root->getSize() >= 1) {
            TwoThreeNode* f = &this->search(value, *this->root);
            TwoThreeNode* newNode = new TwoThreeNode(value, f);
            if (f->getSize() == 2) f->addChild(newNode);
            else if (f->getSize() == 3) {
                f->addChild(newNode);
                this->addSon(f);
            }
        }
    }
}

TwoThreeNode& TwoThreeTree::getRoot() {
    TwoThreeNode* root = this->root;
    return *root;
}

TwoThreeNode& TwoThreeTree::search(int value, TwoThreeNode &root) {
    bool isAllNodesSheet = true;
    for (int i = 0; i < root.getSize(); ++i) {
        if (!root[i]->isSheet()){
            isAllNodesSheet = false;
        }
    }
    TwoThreeNode* returnedRoot = &root;
    if (isAllNodesSheet) return *returnedRoot;
    else {
        if (value <= root.getFirstData()) {
            TwoThreeNode* firstChild = root[0];
            return this->search(value, *firstChild);
        } else {
            if (root.getSize() == 2 || value <= root.getSecondData()) {
                TwoThreeNode* secondChild = root[1];
                return this->search(value, *secondChild);
            } else {
                TwoThreeNode* thirdChild = root[2];
                return this->search(value, *thirdChild);
            }
        }
    }
}

void TwoThreeTree::addSon(TwoThreeNode *node) {
    TwoThreeNode v_ = TwoThreeNode(102, 31,nullptr);
    TwoThreeNode threeChild = node[2];
    TwoThreeNode fourChild = node[3];
    v_.addChild(&threeChild);
    v_.addChild(&fourChild);
    node->removeLastChild();
    node->removeLastChild();


    if (node->getParent() == nullptr) {
        TwoThreeNode newRoot = TwoThreeNode(45, 88,nullptr);
        newRoot.addChild(node);
        newRoot.addChild(&v_);
        this->root = &newRoot;
    } else {
        TwoThreeNode f = *node->getParent();
        f.addChildToRight(*node, v_);

        if (f.getSize() == 4)
            this->addSon(&f);
    }
}

