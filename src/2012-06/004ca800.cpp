// from server: 45% by tester
struct Node {
    Node* left;
    Node* parent;
    Node* right;
    char color;
    char pad[0x39 - 0x0d];
};

struct Map {
    Node* header;
    void erase_one();
};

void Map::erase_one()
{
    Node* n = header;
    if (n->color != 0) {
        return;
    }
    Node* p = n->parent;
    if (p->color != 0) {
        Node* q = n->left;
        if (q->color != 0) {
            header = p;
            return;
        }
        while (1) {
            Node* r = q->left;
            if (r->color != 0) {
                break;
            }
            q = r;
        }
        header = q;
        return;
    }
    Node* q = p->left;
    if (q->color != 0) {
        header = q;
        return;
    }
    while (1) {
        Node* r = header;
        if (r != q->right) {
            break;
        }
        header = q;
        q = q->left;
        if (q->color != 0) {
            break;
        }
    }
    header = q;
}
