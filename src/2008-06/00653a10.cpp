// from server: 100% by king_originala
struct String;
extern void (__thiscall *destroyString)(String *);
extern void __cdecl operator delete(void *);

struct String {
    char storage[28];
    __forceinline ~String();
};

struct Value {
    char storage[32];
    ~Value();
};

struct Pair {
    String first;
    Value second;
};

struct Node {
    Node *left;
    Node *parent;
    Node *right;
    Pair value;
    unsigned char color;
    unsigned char nil;
};

struct S {
    void erase(Node *);
};

__forceinline String::~String()
{
    destroyString(this);
}

void S::erase(Node *node)
{
    for (Node *current = node; !current->nil; node = current) {
        erase(current->right);
        current = current->left;
        node->value.~Pair();
        operator delete(node);
    }
}
