// from server: 31% by atomic.potato
// roc 2012-06 004ce5a0  unit: Ogre::GfxClustererPart  size: 497 bytes

struct Node {
    Node* parent;
    Node* left;
    Node* right;
    char color;
    char pad[0x3f];
};

struct Tree {
    Node* header;
    int count;
};

struct Part {
    char pad0[0x10];
    Tree* tree;
    int count;
    int insert(Node* hint, int a, int b, int c, int d);
    void rotate_left(Node* x);
    void rotate_right(Node* x);
};

extern "C" {
    void* __stdcall sub_b22648(void*);
    void* __stdcall sub_b229dc(void*);
    void* __stdcall sub_b22644(void*, void*);
    void __stdcall sub_983144(void*, void*);
    void* __stdcall sub_4cdae0(void*, void*, int, int, int, int);
}

int Part::insert(Node* hint, int a, int b, int c, int d)
{
    if (this->count >= -2) {
        char buf1[0x1c];
        char buf2[0x1c];
        sub_b22648(buf1);
        sub_b229dc(buf2);
        sub_b22644(buf2, buf1);
        sub_983144(buf2, (void*)0xcd6204);
    }

    Node* x = (Node*)0;
    Node* y = hint;
    int comp = 0;
    x = (Node*)sub_4cdae0(this->tree, hint, a, b, c, d);
    Node* z = x;
    this->count++;

    if (hint == this->tree->header) {
        this->tree->header->parent = z;
        this->tree->header->left = z;
        this->tree->header->right = z;
    } else if (comp) {
        hint->parent = z;
        if (hint == this->tree->header->left)
            this->tree->header->left = z;
    } else {
        hint->right = z;
        if (hint == this->tree->header->right)
            this->tree->header->right = z;
    }

    Node* w = z;
    while (w != this->tree->header && w->parent->color == 0) {
        Node* p = w->parent;
        Node* g = p->parent;
        if (p == g->left) {
            Node* u = g->right;
            if (u->color == 0) {
                p->color = 1;
                u->color = 1;
                g->color = 0;
                w = g;
            } else {
                if (w == p->right) {
                    w = p;
                    this->rotate_left(w);
                }
                w->parent->color = 1;
                w->parent->parent->color = 0;
                this->rotate_right(w->parent->parent);
            }
        } else {
            Node* u = g->left;
            if (u->color == 0) {
                p->color = 1;
                u->color = 1;
                g->color = 0;
                w = g;
            } else {
                if (w == p->left) {
                    w = p;
                    this->rotate_right(w);
                }
                w->parent->color = 1;
                w->parent->parent->color = 0;
                this->rotate_left(w->parent->parent);
            }
        }
    }

    this->tree->header->parent->color = 1;
    return 0;
}
