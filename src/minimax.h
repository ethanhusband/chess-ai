
using namespace std;

// Structure to represent a node in a tree
struct Node
{
    NodeData data;   // Information at this node
    Node **children; // The child nodes of the node
    char n; // Number of children
    bool turn; // Whose turn it is: FALSE for MIN, TRUE for MAX
};

// Data stored in a given node
struct NodeData
{
    int eval;
    float alpha; // α for α-β pruning (the best score MAX has already found)
    float beta; // β for α-β pruning (the best score MIN has already found)
};

// Abstraction for the evaluation function, such that any valid eval function can 
// be passed in as an argument
typedef int (*Evalfunc)(Node node);

// Typedef for Tree - a pointer to a node
typedef Node *Root;