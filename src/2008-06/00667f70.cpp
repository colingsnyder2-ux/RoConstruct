// from server: 100% by king_originala
struct S;
struct Link {
    void* unused;
    S* object;
};

struct Context {
    char unused[12];
    Link* left;
    Link* right;
};

struct S {
    virtual void slot0();
    virtual int value();
    bool f(Context* context);
};

bool S::f(Context* context)
{
    Link* left = context->left;
    Link* right = context->right;

    if (left->object && right->object) {
        int first = left->object->value();
        if (first > value()) {
            int second = right->object->value();
            if (second > value())
                return true;
        }
    }
    return false;
}
