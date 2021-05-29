#include "Queue.h"
#include "TwoThreeTree.h"
#include "TwoThreeNode.h"

Queue::Queue(TwoThreeTree &tree1) : tree(tree1){}

TwoThreeTree& Queue::implantation(TwoThreeTree &T1, TwoThreeTree &T2) {
    if (T1.height() == T2.height()) {
        TwoThreeNode* root1 = &T1.getRoot();
        TwoThreeNode* root2 = &T2.getRoot();
        TwoThreeNode* newRoot = new TwoThreeNode(1000, 1000, nullptr);
        newRoot->addChild(root1);
        newRoot->addChild(root2);
        newRoot->correctNode();
        TwoThreeTree* newTree = new TwoThreeTree(*newRoot);
        return *newTree;
    } else {
        TwoThreeTree *littleTree, *bigTree;
        bool isRight = true;
        if (T1.height() > T2.height()) {
            bigTree = &T1;
            littleTree = &T2;
        } else {
            bigTree = &T2;
            littleTree = &T1;
            isRight = false;
        }
        int difference = bigTree->height() - littleTree->height();
        TwoThreeNode *v = &bigTree->getRoot();
        TwoThreeNode *lR = &littleTree->getRoot();
        for (int i = 0; i < difference; ++i) {
            if (isRight)
                v = &v->getNthChild(v->getSize());
            else
                v = &v->getNthChild(1);
        }
        TwoThreeNode *f = &v->getParent();
        f->addChildToRight(*v, *lR);
        if (v->getFirstData() > lR->getFirstData()) {
            f->swapNodes(*v, *lR);
        }
        if (f->getSize() == 4) {
            bigTree->addSon(f);
        }
        bigTree->getRoot().correctNode();
        return *bigTree;
    }
}

void Queue::separation(int a, TwoThreeTree &T, TwoThreeTree *&leftTree, TwoThreeTree *&rightTree) {
    TwoThreeNode* node = &T.search(a, T.getRoot());
    int leftWoodSize = 0;
    int rightWoodSize = 0;
    auto* leftWood = new TwoThreeTree[0]{};
    auto* rightWood = new TwoThreeTree[0]{};
    for (int i = 1; i <= node->getSize(); ++i) {
        TwoThreeNode* child = &node->getNthChild(i);
        int childLabel = child->getLabel();
        if (a >= childLabel) {
            TwoThreeTree* childTree = new TwoThreeTree(*child);
            leftWood[leftWoodSize] = *childTree;
            leftWoodSize++;
        } else {
            rightWood[rightWoodSize] = TwoThreeTree(node->getNthChild(i));
            rightWoodSize++;
        }
    }
    TwoThreeNode* parent = &node->getParent();
    while (parent != nullptr) {
        bool isRight = false;
        for (int i = 1; i <= parent->getSize(); ++i) {
            if (*node == parent->getNthChild(i)) {
                isRight = true;
                continue;
            }
            if (isRight) {
                rightWood[rightWoodSize] = TwoThreeTree(parent->getNthChild(i));
                rightWoodSize++;
            } else {
                leftWood[leftWoodSize] = TwoThreeTree(parent->getNthChild(i));
                leftWoodSize++;
            }
        }
        node = parent;
        parent = &parent->getParent();
    }
//    cout << "LeftWood" << endl;
//    for (int i = 0; i < leftWoodSize; ++i) {
//        cout << leftWood[i];
//    }
//    cout << endl << "Right Wood" << endl;
//    for (int i = 0; i < rightWoodSize; ++i) {
//        cout << rightWood[i];
//    }
//    cout << endl << endl;
    TwoThreeTree* LT =  &implantation(leftWood[1], leftWood[0]);
    TwoThreeTree* RT =  &implantation(rightWood[0], rightWood[1]);
    for (int i = 2; i < leftWoodSize; ++i) {
        LT = &implantation(leftWood[i], *LT);
    }
    for (int i = 2; i < rightWoodSize; ++i) {
        RT = &implantation(*RT, rightWood[i]);
    }
    leftTree = LT;
    rightTree = RT;
}

ostream & operator << (ostream & stream, Queue queue) {
    stream << queue.tree;
    return stream;
}

