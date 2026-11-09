// from server: 41% by atomic.potato
struct Node {
    Node* parent;
    Node* left;
    Node* right;
    char pad[9];
    char color;
};

struct Stage {
    char pad0[4];
    Node* header;
    int count;
    void erase_node(Node*);
    void insert_node(Node**, Node*);
};

void Stage::erase_node(Node* n) {
    Node* p = n->parent;
    Node* c = n->left;
    if (c->color == 0) {
        while (c->left->color == 0) {
            c = c->left;
        }
        p = c;
    } else {
        Node* r = n->right;
        if (r->color == 0) {
            while (n == r->left) {
                n = r;
                r = r->parent;
            }
            if (r->right->color == 0) {
                p = r;
            } else {
                p = r->parent;
            }
        } else {
            p = r;
        }
    }
    insert_node(&p, n);
}

void Stage::insert_node(Node** pos, Node* n) {
    Node* p = *pos;
    Node* h = header;
    if (p == h) {
        if (n == h) {
            erase_node(h->parent);
            header->parent = header;
            count = 0;
            header->left = header;
            header->right = header;
            *pos = header->parent;
            return;
        }
    }
    while (p != n) {
        Node* q = p;
        if (q->color == 0) {
            Node* r = q->left;
            if (r->color == 0) {
                while (r->left->color == 0) {
                    r = r->left;
                }
                q = r;
            } else {
                Node* s = q->right;
                if (s->color == 0) {
                    while (q == s->left) {
                        q = s;
                        s = s->parent;
                    }
                    if (s->right->color == 0) {
                        q = s;
                    } else {
                        q = s->parent;
                    }
                } else {
                    q = s;
                }
            }
        }
        insert_node(&q, p);
        p = *pos;
    }
    *pos = p;
}
