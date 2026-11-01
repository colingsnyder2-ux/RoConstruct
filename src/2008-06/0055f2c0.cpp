// from server: 100% by king_originala
extern void (__thiscall *destroy_string)(void *);
void __cdecl operator delete(void *);

struct StringStorage
{
    char storage[32];
    ~StringStorage();
};

inline StringStorage::~StringStorage()
{
    destroy_string(this);
}

struct Member
{
    char storage[16];
    ~Member();
};

struct Value : StringStorage
{
    Member member;
    ~Value();
};

inline Value::~Value()
{
}

struct Node
{
    Node *left;
    Node *parent;
    Node *right;
    Value value;
    unsigned char color;
    unsigned char isNil;
};

struct S
{
    void erase(Node *);
};

void S::erase(Node *node)
{
    Node *cursor = node;
    while (!cursor->isNil)
    {
        erase(cursor->right);
        cursor = cursor->left;
        node->value.~Value();
        operator delete(node);
        node = cursor;
    }
}
