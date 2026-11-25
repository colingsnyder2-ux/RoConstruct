// from server: 100% by Xemicl
﻿// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Node {
    unsigned int flag : 1;
    unsigned int parent : 31;
    Node* left;
    Node* right;

    Node* clearFlag();
    Node* clearParent();
};

__forceinline Node* Node::clearFlag()
{
    flag = 0;
    return this;
}

__forceinline Node* Node::clearParent()
{
    parent = 0;
    return this;
}

struct Padding {
    unsigned char data[0x20];
};

struct Owner : Padding, Node {
};

struct S {
    unsigned int reserved;
    void reset();
};

#pragma pack(push, 1)
struct Prefix {
    unsigned int reserved0;
    Owner* owner;
    unsigned char reserved1;
};

struct Holder : Prefix, S {
};
#pragma pack(pop)

void S::reset()
{
    static_cast<Holder*>(this)->owner->clearFlag();
    static_cast<Holder*>(this)->owner->clearParent();
    static_cast<Holder*>(this)->owner->left =
        static_cast<Node*>(static_cast<Holder*>(this)->owner);
    static_cast<Holder*>(this)->owner->right =
        static_cast<Node*>(static_cast<Holder*>(this)->owner);
}