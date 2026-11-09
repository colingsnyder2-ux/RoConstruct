// from server: 100% by king_originala
struct S {
    virtual void slot0();
    virtual void slot1();
    virtual bool slot2(S*);
    virtual unsigned char slot3(S*);

    char padding[256];
    S* parent;

    bool contains(S*);
    bool f(S*);
};

bool S::f(S* other)
{
    if (other->contains(this))
        return false;
    if (other->parent == this)
        return false;
    if (slot2(other))
        return true;
    return other->slot3(this);
}
