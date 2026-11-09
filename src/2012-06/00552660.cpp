// from server: 26% by tester
struct Node {
    Node* left;
    Node* parent;
    Node* right;
    char  color;
    char  pad[0x10];
    int   key;
};

struct Map {
    Node* head;
};

struct Temp {
    Node* node;
    int   key;
    int   flag;
};

struct Target {
    Map  map;
    char pad[0x10];
    int  f(int* arg);
};

void* __stdcall sub_5423f0(void* p);
void  __stdcall sub_547f40(void* dst, void* src);
void* __stdcall sub_5509a0(Target* self, void* a, void* b, void* c);
void  __stdcall sub_5467d0(void* dst, void* a, void* b);
void* __stdcall sub_982114(void* p);

int Target::f(int* arg)
{
    Node* header = map.head;
    Node* cur = header->parent;
    int key = *arg;

    while (cur->color == 0) {
        if (cur->key < key)
            cur = cur->right;
        else
            cur = cur->left;
    }

    if (cur != map.head && cur->key <= key) {
        return 0;
    }

    void* mem = sub_5423f0(0);
    Node* n = (Node*)mem;
    n->color = 1;
    n->parent = n;
    n->left = n;
    n->right = n;

    Temp tmp;
    tmp.node = n;
    tmp.key = key;
    tmp.flag = 0;

    sub_547f40(&tmp, &tmp);

    void* res = sub_5509a0(this, &tmp, cur, &tmp);

    int* p = (int*)res;
    int v = *p;

    void* a = (void*)tmp.node;
    int  b = *(int*)a;
    sub_5467d0(&tmp, a, (void*)b);

    sub_982114((void*)tmp.node);

    void* q = (void*)tmp.node;
    int  r = *(int*)q;
    sub_5467d0(&tmp, q, (void*)r);

    sub_982114((void*)tmp.node);

    return v;
}
