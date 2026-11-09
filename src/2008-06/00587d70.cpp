// from server: 100% by king_originala
struct Object
{
    virtual ~Object();
};

struct Node
{
    Node* left;
    Node* parent;
    Node* right;
    unsigned int reserved[2];
    Object* value;
    unsigned char color;
    unsigned char nil;
};

extern "C" void __cdecl func_006a067a(void*);

struct S
{
    void f(Node* root);
};

void S::f(Node* root)
{
    for (Node* node = root; !node->nil; root = node)
    {
        f(node->right);
        node = node->left;
        delete root->value;
        func_006a067a(root);
    }
}
