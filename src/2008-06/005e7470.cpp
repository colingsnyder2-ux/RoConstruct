// from server: 100% by king_originala
struct Node {
    int func_005e7370();
};

struct Link {
    char padding[0x14];
    Node* node;
    __forceinline int value();
};

struct Ball {
    char padding[0xa0];
    Link* link;
    int func_005e7470();
};

__forceinline int Link::value()
{
    if (node)
        return node->func_005e7370() + 1;
    return 1;
}

int Ball::func_005e7470()
{
    return link->value();
}
