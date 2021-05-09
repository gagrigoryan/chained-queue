#include "iostream"
#include "fstream"

using namespace std;

class TwoThreeNode {
public:
    TwoThreeNode();
    TwoThreeNode(int label);
    TwoThreeNode(int firstData, int secondData);

    int getFirstData() const;
    int getSecondData() const;
    int getLabel() const;
    int getSize() const;

    void setFirstData(int value);
    void setSecondData(int value);
    void setLabel(int value);

    TwoThreeNode* getFirstChild() const;
    TwoThreeNode* getSecondChild() const;
    TwoThreeNode* getThirdChild() const;

    TwoThreeNode* getNthChild(int i);

    void addChild(TwoThreeNode *child);

    bool isSheet();

    TwoThreeNode *first, *second, *three;

private:
    int firstData, secondData;
    int size;
    int label;

};

ostream & operator << (ostream & stream, const TwoThreeNode &node);