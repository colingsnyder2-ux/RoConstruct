// from server: 52% by colin
extern "C" void __stdcall _invalid_parameter_noinfo();

struct Node {
    Node* left;
    Node* parent;
    Node* right;
    char color;
    char pad[3];
    int key;
};

struct Tree {
    Node* head;
    int size;
};

struct Obj {
    char pad0[0x24];
    int field24;
    char pad28[0x4];
    char field2c;
    char pad2d[0x3];
    Tree tree30;
    int field38;
    char pad3c[0x10];
    char field4c;

    void method();
};

extern "C" void __stdcall sub_5B4820(int);
extern "C" void __stdcall sub_5E24B0(int);
extern "C" void __stdcall sub_5375C0(void*, void*, void*, void*, void*, void*);
extern "C" void __stdcall sub_5B3A60(void*, void*, void*, void*, void*);

char sub_60BB80();

void Obj::method()
{
    if (this->field38 == 0)
        return;

    Tree* t = &this->tree30;

    for (;;) {
        Node* header = t->head;
        Node* first = header->left;
        if (first == header)
            _invalid_parameter_noinfo();

        Node* cur = first->right;
        if (cur == (Node*)this->field24)
            this->field24 = 0;

        this->field4c = 1;
        sub_5B4820(0);
        sub_5E24B0(0);

        Node* root = t->head->parent;
        Node* lower;
        if (root->color == 0) {
            Node* n = root;
            Node* best = t->head;
            while (n->color == 0) {
                if (cur < (Node*)n->key) {
                    best = n;
                    n = n->left;
                } else {
                    n = n->right;
                }
            }
            lower = best;
        } else {
            lower = t->head;
        }

        Node* upper;
        Node* n2 = root;
        if (n2->color == 0) {
            Node* best2 = root;
            while (n2->color == 0) {
                if ((Node*)n2->key < cur) {
                    n2 = n2->right;
                } else {
                    best2 = n2;
                    n2 = n2->left;
                }
            }
            upper = best2;
        } else {
            upper = root;
        }

        int tmp = 0;
        sub_5375C0(t, upper, t, &tmp, lower, 0);
        sub_5B3A60(t, &tmp, lower, t, 0);

        this->field2c = sub_60BB80();

        if (this->field38 == 0)
            break;
    }
}
