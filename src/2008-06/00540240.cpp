// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /Od /Ob0 /GS /EHsc /MD
#pragma optimize("g", off)
#pragma strict_gs_check(on)

struct Node;

struct Handle
{
    Node* pointer;
    void* control;

    Handle(Node*);
    ~Handle();
};

struct Iterator
{
    Node* node;
    void* owner;
};

struct InsertResult
{
    Iterator position;
    bool inserted;
};

struct Bucket
{
    unsigned char storage[32];

    InsertResult insert(const Handle&);
};

struct S
{
    unsigned char padding[40];
    Bucket first;
    Bucket second;

    void set(Node*, bool);
};

void S::set(Node* node, bool flag)
{
    if (flag)
    {
        {
            Handle value(node);
            InsertResult result = first.insert(value);
        }
        do {} while (0);
        do {} while (0);
    }
    else
    {
        {
            Handle value(node);
            InsertResult result = second.insert(value);
        }
        do {} while (0);
        do {} while (0);
    }
}
