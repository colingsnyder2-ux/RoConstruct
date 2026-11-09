// from server: 66% by atomic.potato
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    char color;
    char pad[3];
};

struct S {
    Node* root;
    void f();
};

void S::f()
{
    Node* n = root;
    if (n->color != 0) {
        root = n->right;
        return;
    }
    Node* p = n->left;
    if (p->color == 0) {
        Node* q = p->right;
        if (q->color == 0) {
            do {
                p = q;
                q = p->right;
            } while (q->color == 0);
        }
        root = p;
        return;
    }
    Node* q = n->right;
    if (q->color == 0) {
        Node* r = root;
        while (r == q->left) {
            root = q;
            q = q->right;
            if (q->color != 0)
                break;
        }
    }
    Node* r = root;
    if (r->color == 0)
        root = q;
}
