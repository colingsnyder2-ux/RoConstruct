// from server: 100% by king_originala
struct Geometry;

struct Primitive {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int isA();

    char pad08[8];
    Geometry* owner;
    char pad10[4];
    int ownerIndex;
    int otherIndex;
};

struct Geometry {
    char pad00[0x1c];
    Primitive** a;
    int aCount;
    int aCapacity;
    char pad28[0x10];
    Primitive** b;
    int bCount;

    Primitive* getNext(Primitive* p);
};

Primitive* Geometry::getNext(Primitive* p)
{
    if (!p->isA()) {
        int index = (this == p->owner ? p->ownerIndex : p->otherIndex) + 1;
        Primitive* next = index < bCount ? b[index] : 0;
        if (next)
            return next;
        if (aCount > 0)
            return a[0];
    } else {
        int index = (this == p->owner ? p->ownerIndex : p->otherIndex) + 1;
        if (index < aCount)
            return a[index];
    }
    return 0;
}
