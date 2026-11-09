// from server: 100% by colin
struct Node
{
    char padding0[0x44];
    int key;
    char padding1[0x0c];
    Node* left;
    Node* right;
};

struct Sentinel
{
    char padding[0x50];
    unsigned int link;
};

struct Owner
{
    char padding0[4];
    Sentinel* anchor;
};

struct Result
{
    int right;
    Node* link;
};

struct S
{
    bool find(int key, Result* result, int unused);
};

bool S::find(int key, Result* result, int unused)
{
    Sentinel* anchor = (this ? (Owner*)((char*)this - 12) : 0)->anchor;
    Node* previous = (Node*)anchor;
    unsigned int root =
        (this ? (Owner*)((char*)this - 12) : 0)->anchor->link & ~1u;
    Node* current = root ? (Node*)(root - 0x50) : 0;
    bool left = true;

    while (current)
    {
        previous = current;
        Node* next;
        left = key < current->key;
        if (left)
        {
            next = current->left;
        }
        else
        {
            next = current->right;
        }
        current = next ? (Node*)((char*)next - 0x50) : 0;
    }

    result->right = !left;
    result->link = previous ? (Node*)((char*)previous + 0x50) : 0;
    return true;
}
