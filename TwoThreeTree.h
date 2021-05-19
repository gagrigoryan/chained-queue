class TwoThreeNode;

class TwoThreeTree {
public:
    TwoThreeTree(TwoThreeNode &root);
    TwoThreeNode search(int value, TwoThreeNode &root);

    TwoThreeNode* getRoot() const;

    void addNode(int value);

    void addSon(TwoThreeNode &node);

private:
    TwoThreeNode *root;
};