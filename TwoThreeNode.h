#include "iostream"
#include "fstream"

using namespace std;

class TwoThreeNode {
public:
    TwoThreeNode(TwoThreeNode *parent);
    TwoThreeNode(int label, TwoThreeNode *parent);
    TwoThreeNode(int firstData, int secondData, TwoThreeNode *parent);

    int getFirstData() const;
    int getSecondData() const;
    int getLabel() const;
    int getSize() const;

    void setFirstData(int value);
    void setSecondData(int value);
    void setLabel(int value);
    void setParent(TwoThreeNode *parent);

    TwoThreeNode& getFirstChild() const;
    TwoThreeNode& getSecondChild() const;
    TwoThreeNode& getThirdChild() const;
    TwoThreeNode& getFakeChild() const;
    TwoThreeNode& getParent() const;

    void setFirstChild(TwoThreeNode *child);
    void setSecondChild(TwoThreeNode *child);
    void setThreeChild(TwoThreeNode *child);
    void setFakeChild(TwoThreeNode *child);

    void setNthChild(int index, TwoThreeNode &child);

    TwoThreeNode& getNthChild(int i);
    void removeLastChild();

    void addChild(TwoThreeNode *child);
    void addChildToRight(TwoThreeNode &sourceChild, TwoThreeNode &newChild);

    bool isSheet();

    TwoThreeNode *first, *second, *three, *fakeChild;
    TwoThreeNode *parent;

    TwoThreeNode* operator[](const int index) const;
    bool operator==(TwoThreeNode &otherNode);

    void correctNode();
    int maxInSubTree();

    void swapNodes(TwoThreeNode &child1, TwoThreeNode &child2);

    TwoThreeNode& operator=(const TwoThreeNode& other);

private:
    int firstData, secondData;
    int size;
    int label;

    void normalize();
};

ostream & operator << (ostream & stream, const TwoThreeNode &node);