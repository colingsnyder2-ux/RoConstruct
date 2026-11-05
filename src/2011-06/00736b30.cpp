// from server: 59% by atomic.potato
struct Node {
    Node* left;
    Node* right;
    Node* parent;
    char color;
    char pad[3];
};

struct Tree {
    Node* header;
    void decrement();
};

void Tree::decrement()
{
    Node* p = header;
    if (p->color != 0) {
        header = p->right;
        return;
    }
    Node* q = p->left;
    if (q->color == 0) {
        Node* r = q->right;
        while (r->color == 0) {
            q = r;
            r = q->right;
        }
        header = q;
        return;
    }
    Node* s = p->parent;
    if (s->color == 0) {
        Node* t = header;
        while (t == s->left) {
            header = s;
            s = s->parent;
            if (s->color != 0)
                break;
            t = header;
        }
    }
    Node* u = header;
    if (u->color == 0)
        header = s;
}
