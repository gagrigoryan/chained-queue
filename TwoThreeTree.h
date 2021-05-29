#include <fstream>

using namespace std;

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

    void print(ostream & stream, TwoThreeNode *node, int deep);

    void spaces(ostream & stream, int deep);

    int height ();

private:
    TwoThreeNode *root;
};

ostream & operator << (ostream & stream, TwoThreeTree tree);