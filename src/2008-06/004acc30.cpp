// from server: 100% by king_originala
struct Node {
    unsigned int flag : 1;
    unsigned int remaining : 31;
    Node* previous;
    Node* next;

    void clearFlag();
    void clearRemaining();
};

inline void Node::clearFlag()
{
    flag = 0;
}

inline void Node::clearRemaining()
{
    remaining = 0;
}

struct Padding {
    unsigned char bytes[0x280];
};

struct Owner : Padding, Node {
};

struct S {
    void reset();
};

struct ItemPrefix {
    unsigned int unused;
    Owner* owner;
    unsigned int reserved;
};

struct ChangeItem : ItemPrefix, S {
};

void S::reset()
{
    static_cast<ChangeItem*>(this)->owner->clearFlag();
    static_cast<ChangeItem*>(this)->owner->clearRemaining();
    static_cast<ChangeItem*>(this)->owner->previous =
        static_cast<Node*>(static_cast<ChangeItem*>(this)->owner);
    static_cast<ChangeItem*>(this)->owner->next =
        static_cast<Node*>(static_cast<ChangeItem*>(this)->owner);
}
