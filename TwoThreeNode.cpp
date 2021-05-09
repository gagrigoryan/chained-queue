#include "TwoThreeNode.h"

TwoThreeNode::TwoThreeNode() {
    this->firstData = -1;
    this->secondData = -1;
    this->size = 0;
    this->label = -1;
    this->first = nullptr;
    this->second = nullptr;
    this->three = nullptr;
}

TwoThreeNode::TwoThreeNode(int label) {
    this->firstData = -1;
    this->secondData = -1;
    this->size = 0;
    this->label = label;
    this->first = nullptr;
    this->second = nullptr;
    this->three = nullptr;
}

TwoThreeNode::TwoThreeNode(int firstData, int secondData) {
    this->firstData = firstData;
    this->secondData = secondData;
    this->size = 0;
    this->label = -1;
    this->first = nullptr;
    this->second = nullptr;
    this->three = nullptr;
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
    this->size++;
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

ostream & operator << (ostream & stream, const TwoThreeNode &node) {
    if (node.getSize() == 0)
        stream << "Sheet: " << node.getLabel();
    else
        stream << "[ " << node.getFirstData() << ", " << node.getSecondData() << " ]";
    return stream;
}

