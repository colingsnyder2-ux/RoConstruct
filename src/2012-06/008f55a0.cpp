// from server: 33% by atomic.potato
struct Node {
    Node* parent;
    Node* left;
    Node* right;
    char color;
    char pad[3];
};

struct Tree {
    Node* head;
    int count;
    char pad[0x14 - 8];
    char color;
};

struct Alloc {
    void* alloc(unsigned int);
    void dealloc(void*);
};

extern "C" {
    void* __stdcall sub_8f5550(void*, void*, void*, int, char, int);
    void __stdcall sub_961560(void*, void*);
    void __stdcall sub_766bc0(void*, void*);
    void __stdcall sub_983144(void*, int);
    void* __stdcall sub_b22648(void*, const char*);
    void* __stdcall sub_b229dc(void*, void*);
    void* __stdcall sub_b22644(void*, void*, void*);
}

struct EventDesc {
    char pad0[4];
    Node* head;
    int count;
    char pad1[0x14 - 0xc];
    char color;

    void insert(void* a, void* b, int c, char d);
};

void EventDesc::insert(void* a, void* b, int c, char d)
{
    if (count >= 0x1ffffffe) {
        char buf[0x20];
        sub_b22648(buf, "map/set<T> too long");
        sub_b229dc(buf + 0x1c, 0);
        sub_b22644(buf + 0x1c, buf, 0);
        sub_983144(buf + 0x1c, 0xcd6204);
    }

    Node* newNode = (Node*)sub_8f5550(head, a, b, c, d, 0);
    Node* h = head;
    count++;
    if (a == h) {
        h->parent = newNode;
        head->left = newNode;
        head->right = newNode;
    } else {
        if (d) {
            ((Node*)a)->left = newNode;
            if (a == head->left)
                head->left = newNode;
        } else {
            ((Node*)a)->right = newNode;
            if (a == head->right)
                head->right = newNode;
        }
    }

    Node* x = newNode;
    Node* y = newNode->parent;
    while (y->color == 0) {
        Node* p = x->parent;
        if (p == p->parent->left) {
            Node* uncle = p->parent->right;
            if (uncle->color == 1) {
                p->color = 1;
                uncle->color = 1;
                p->parent->color = 0;
                x = p->parent;
            } else {
                if (x == p->right) {
                    x = p;
                    sub_961560(this, x);
                }
                x->parent->color = 1;
                x->parent->parent->color = 0;
                sub_766bc0(this, x->parent->parent);
            }
        } else {
            Node* uncle = p->parent->left;
            if (uncle->color == 1) {
                p->color = 1;
                uncle->color = 1;
                p->parent->color = 0;
                x = p->parent;
            } else {
                if (x == p->left) {
                    x = p;
                    sub_766bc0(this, x);
                }
                x->parent->color = 1;
                x->parent->parent->color = 0;
                Node* gp = x->parent->parent;
                Node* gpr = gp->right;
                gp->right = gpr->left;
                if (gpr->left->color == 0)
                    gpr->left->parent = gp;
                gpr->parent = gp->parent;
                if (gp == head->parent)
                    head->parent = gpr;
                else if (gp == gp->parent->left)
                    gp->parent->left = gpr;
                else
                    gp->parent->right = gpr;
                gpr->left = gp;
                gp->parent = gpr;
            }
        }
        y = x->parent;
    }
    head->parent->color = 1;
    *(Node**)a = newNode;
}
