class TwoThreeNode;

class TwoThreeTree {
public:
    TwoThreeTree(TwoThreeNode &root);
    TwoThreeNode& search(int value, TwoThreeNode &root);

    TwoThreeNode& getRoot();

    void addNode(int value);

    void addSon(TwoThreeNode *node);

    void adjustmentRecursive(TwoThreeNode *node);

    void adjustment();

    void print(TwoThreeNode *node, int deep);

    void spaces(int deep);

private:
    TwoThreeNode *root;
};