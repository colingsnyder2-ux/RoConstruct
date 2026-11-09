// from server: 61% by atomic.potato
struct Node {
    Node* left;
    Node* parent;
    Node* right;
    char pad[0x1d - 0xc];
    char color;
};

struct Tree {
    char pad0[4];
    Node* header;
    int count;

    void erase(Node* first, Node* last, Node** out);
};

extern "C" void __stdcall sub_4c3d70(Node*);
extern "C" void __stdcall sub_90f040(Node**, Node*);

void Tree::erase(Node* first, Node* last, Node** out)
{
    Node* header = this->header;
    if (first == header->left && last == header) {
        sub_4c3d70(header->parent);
        Node* h = this->header;
        h->parent = h;
        this->count = 0;
        h->left = h;
        Node* h2 = this->header;
        h2->right = h2;
        Node* h3 = this->header;
        *out = h3->left;
        return;
    }
    if (first == last)
        goto done;
    do {
        Node* cur = first;
        if (cur->color == 0) {
            Node* n = cur->right;
            if (n->color != 0) {
                Node* p = cur->parent;
                if (p->color == 0 && cur == p->right) {
                    do {
                        cur = p;
                        first = cur;
                        p = p->parent;
                    } while (p->color == 0);
                }
                first = p;
            } else {
                Node* n2 = n;
                Node* l = n2->left;
                while (l->color == 0) {
                    n2 = l;
                    l = n2->left;
                }
                first = n2;
            }
        } else {
            Node* p = cur->parent;
            if (p->color == 0) {
                Node* n = p->right;
                if (n->color == 0) {
                    do {
                        cur = n;
                        first = cur;
                        n = n->right;
                    } while (n->color == 0);
                }
                first = n;
            }
        }
        sub_90f040(&first, cur);
    } while (first != last);
done:
    *out = first;
}
