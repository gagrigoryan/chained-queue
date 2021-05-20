#include "TwoThreeNode.h"

TwoThreeNode::TwoThreeNode(TwoThreeNode *parent) {
    this->firstData = -1;
    this->secondData = -1;
    this->size = 0;
    this->label = -1;
    this->first = nullptr;
    this->second = nullptr;
    this->three = nullptr;

    this->parent = parent;
}

TwoThreeNode::TwoThreeNode(int label, TwoThreeNode *parent) {
    this->firstData = -1;
    this->secondData = -1;
    this->size = 0;
    this->label = label;
    this->first = nullptr;
    this->second = nullptr;
    this->three = nullptr;
    this->parent = parent;
}

TwoThreeNode::TwoThreeNode(int firstData, int secondData, TwoThreeNode *parent) {
    this->firstData = firstData;
    this->secondData = secondData;
    this->size = 0;
    this->label = -1;
    this->first = nullptr;
    this->second = nullptr;
    this->three = nullptr;
    this->parent = parent;
}

int TwoThreeNode::getFirstData() const {
    return this->firstData;
}

int TwoThreeNode::getSecondData() const {
    return this->secondData;
}

int TwoThreeNode::getSize() const {
    return this->size;
}

TwoThreeNode* TwoThreeNode::getFirstChild() const {
    return this->first;
}

TwoThreeNode* TwoThreeNode::getSecondChild() const {
    return this->second;
}

TwoThreeNode* TwoThreeNode::getThirdChild() const {
    return this->three;
}

void TwoThreeNode::addChild(TwoThreeNode *child) {
    if (this->size == 0)
        this->first = child;
    else if (this->size == 1)
        this->second = child;
    else if (this->size == 2)
        this->three = child;
    else if (this->size ==3)
        this->fakeChild = child;
    this->size++;
    child->setParent(this);
    this->normalize();
}

void TwoThreeNode::setFirstData(int value) {
    this->firstData = value;

}

void TwoThreeNode::setSecondData(int value) {
    this->secondData = value;
}

int TwoThreeNode::getLabel() const {
    return this->label;
}

void TwoThreeNode::setLabel(int value) {
    this->label = value;
}

bool TwoThreeNode::isSheet() {
    return this->size == 0 && this->label != -1;
}

TwoThreeNode *TwoThreeNode::getNthChild(int i) {
    if (i == 1)
        return this->getFirstChild();
    else if (i == 2)
        return this->getSecondChild();
    else if (i == 3)
        return this->getThirdChild();
}

TwoThreeNode* TwoThreeNode::operator[](const int index) const {
    if (index >= this->size) throw out_of_range("Index out of range");

    if (index == 0) return this->first;
    if (index == 1) return this->second;
    if (index == 2) return this->three;
    if (index == 3) return this->fakeChild;
}

void TwoThreeNode::normalize() {
    if (this->size < 2) return;
    if (this->first < this->second) swap(this->first, this->second);
    if (this->size == 3 && this->first < this->three) swap(this->first, this->three);
    if (this->size == 3 && this->second < this->three) swap(this->second, this->three);
    if (this->size == 4 && this->second < this->fakeChild) swap(this->second, this->fakeChild);
    if (this->size == 4 && this->three < this->fakeChild) swap(this->three, this->fakeChild);
}

TwoThreeNode *TwoThreeNode::getParent() const {
    return this->parent;
}

void TwoThreeNode::setParent(TwoThreeNode *parent) {
    this->parent = parent;
}

void TwoThreeNode::removeLastChild() {
    if (this->size == 0) return;
    if (this->size == 1) this->first = nullptr;
    if (this->size == 2) this->second = nullptr;
    if (this->size == 3) this->three = nullptr;
    if (this->size == 4) this->fakeChild = nullptr;
    this->size--;
}

bool TwoThreeNode::operator==(TwoThreeNode &otherNode) {
    if (this->isSheet() && otherNode.isSheet() && this->getLabel() == otherNode.getLabel()) return true;
    return this->getFirstData() == otherNode.getFirstData() && this->getSecondData() == otherNode.secondData;
}

void TwoThreeNode::addChildToRight(TwoThreeNode &sourceChild, TwoThreeNode &newChild) {
    bool isFindPos = false;
    TwoThreeNode* childArray [4];
    for (int i = 0; i < this->size; ++i) {
        TwoThreeNode* node = this->getNthChild(i + 1);
        if (!isFindPos) {
            childArray[i] = node;
        } else {
            childArray[i + 1] = node;
        }
        if (*node == sourceChild) {
            isFindPos = true;
            childArray[i + 1] = &newChild;
        }
    }

    for (int i = 0; i <= this->getSize(); ++i) {
        this->setNthChild(i + 1, *childArray[i]);
    }
    this->size++;
}

void TwoThreeNode::setFirstChild(TwoThreeNode *child) {
    this->first = child;
    child->setParent(this);
}

void TwoThreeNode::setSecondChild(TwoThreeNode *child) {
    this->second = child;
    child->setParent(this);
}

void TwoThreeNode::setThreeChild(TwoThreeNode *child) {
    this->three = child;
    child->setParent(this);
}

void TwoThreeNode::setFakeChild(TwoThreeNode *child) {
    this->fakeChild = child;
    child->setParent(this);
}

void TwoThreeNode::setNthChild(int index, TwoThreeNode &child) {
    if (index == 1)
        this->setFirstChild(&child);
    else if (index == 2)
        this->setSecondChild(&child);
    else if (index == 3)
        this->setThreeChild(&child);
    else
        this->setFakeChild(&child);
}

ostream & operator << (ostream & stream, const TwoThreeNode &node) {
    if (node.getSize() == 0)
        stream << "Sheet: " << node.getLabel();
    else
        stream << "[ " << node.getFirstData() << ", " << node.getSecondData() << " ]";
    return stream;
}

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

