// from server: 100% by king_originala
struct Link
{
    unsigned int tagged;
    Link* left;
    Link* right;
};

struct Node
{
    char padding0[8];
    double key;
    char padding1[80];
    Link link;
};

struct Owner
{
    unsigned int unused;
    Node* anchor;
};

struct Result
{
    int right;
    Link* link;
};

struct S
{
    bool find(const double* key, Result* result, int unused);
};

bool S::find(const double* key, Result* result, int unused)
{
    Node* previous = (this ? (Owner*)((char*)this - 12) : 0)->anchor;
    unsigned int root =
        (this ? (Owner*)((char*)this - 12) : 0)->anchor->link.tagged & ~1u;
    Node* current = root ? (Node*)(root - 96) : 0;
    bool left = true;

    while (current)
    {
        previous = current;
        Link* next;
        if (*key > current->key)
        {
            next = current->link.left;
            left = true;
        }
        else
        {
            next = current->link.right;
            left = false;
        }
        current = next ? (Node*)((char*)next - 96) : 0;
    }

    result->right = !left;
    result->link = previous ? &previous->link : 0;
    return true;
}
