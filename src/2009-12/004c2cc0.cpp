// from server: 29% by atomic.potato
struct Node {
    char pad0[4];
    Node* parent;
    Node* left;
    Node* right;
    char pad1[0x5d - 0x10];
    char color;
};

struct RbxCluster {
    Node* header;
    Node* root;
    void _Inc();
};

extern "C" void __stdcall _invalid_parameter_noinfo();

void RbxCluster::_Inc()
{
    if (header == 0)
        _invalid_parameter_noinfo();
    Node* n = root;
    if (n->color != 0) {
        _invalid_parameter_noinfo();
        return;
    }
    Node* p = n->left;
    if (p->color != 0) {
        Node* g = p->parent;
        if (g->color == 0) {
            while (g->left->color == 0)
                g = g->left;
        }
        root = g;
        return;
    }
    Node* q = n->parent;
    if (q->color != 0) {
        root = q;
        return;
    }
    while (1) {
        Node* r = root;
        if (r != q->left)
            break;
        root = q;
        Node* s = q->parent;
        if (s->color != 0)
            break;
        q = s;
    }
    root = q;
}
