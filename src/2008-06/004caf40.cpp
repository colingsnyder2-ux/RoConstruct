// from server: 100% by colin
struct Link;

struct Node
{
    char padding[0x44];
    int priority;
    char gap[8];
    Link* next;
    Link* previous;
};

struct Owner
{
    int unused;
    Node* node;
};

struct Sender
{
    bool f(Node* value, Node* cursor, int unused);
};

extern void __cdecl previousLink(Link** cursor);
extern void __cdecl nextLink(Link** cursor);

bool Sender::f(Node* value, Node* cursor, int unused)
{
    Owner* owner = this ? reinterpret_cast<Owner*>(
        reinterpret_cast<char*>(this) - 12) : 0;

    Link* link = owner->node->previous;
    Node* original = cursor;
    Node* end = link ? reinterpret_cast<Node*>(
        reinterpret_cast<char*>(link) - 0x50) : 0;

    Node* slot = 0;

    if (original != end)
    {
        slot = original ? reinterpret_cast<Node*>(
            reinterpret_cast<char*>(original) + 0x50) : 0;

        previousLink(reinterpret_cast<Link**>(&slot));

        Node* previous = slot ? reinterpret_cast<Node*>(
            reinterpret_cast<char*>(slot) - 0x50) : 0;

        if (value->priority < previous->priority)
            return false;
    }

    slot = original ? reinterpret_cast<Node*>(
        reinterpret_cast<char*>(original) + 0x50) : 0;

    nextLink(reinterpret_cast<Link**>(&slot));

    Node* next = slot ? reinterpret_cast<Node*>(
        reinterpret_cast<char*>(slot) - 0x50) : 0;

    owner = this ? reinterpret_cast<Owner*>(
        reinterpret_cast<char*>(this) - 12) : 0;

    return next == owner->node || next->priority >= value->priority;
}
