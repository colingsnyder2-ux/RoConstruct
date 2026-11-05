// from server: 62% by tester
struct Node {
    Node* left;
    Node* parent;
    Node* right;
    char color;
    char pad[3];
    int value;
};

struct Tree {
    Node* head;
    int size;
};

struct Container {
    char pad0[0x14];
    Tree* tree;
};

struct S {
    char pad0[0x1c];
    Tree tree;
    int f(Node* node, int value);
};

extern "C" void __stdcall _invalid_parameter_noinfo();

extern "C" void __stdcall sub_6efd80(Tree* tree, Node* node, int value);

extern "C" void __stdcall sub_65c9d0(S* self, int a, int b, int c, int d, int e);

int S::f(Node* node, int value)
{
    Tree* t = &tree;
    sub_6efd80(t, node, value);

    Node* head = t->head;
    Node* parent = head->parent;
    Node* left = head->left;

    if (node->left == 0 || node->left != left)
    {
        _invalid_parameter_noinfo();
    }

    if (node->parent != parent)
    {
        if (node->left == 0)
        {
            _invalid_parameter_noinfo();
            if (node->left == 0)
            {
                goto skip;
            }
        }
        if (node->parent != node->left->parent)
        {
            _invalid_parameter_noinfo();
        }
        skip:
        {
            Node* p = node->parent;
            int a = p->value;
            int b = p->color;
            int c = *(int*)((char*)this + 0x14);
            int d = *(int*)this;
            sub_65c9d0(this, d, c, b, a, (int)this);
        }
    }

    return (int)node;
}
