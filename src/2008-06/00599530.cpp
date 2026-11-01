// from server: 100% by king_originala
struct Edge;

struct Geometry {
    Edge* getFirst();
    Edge* getNextB(Edge*);
};

struct Transform {
    char data[48];
};

struct Edge {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int blocked();
    virtual void slot4();
    virtual int kind();

    char padding0[8];
    Geometry* g0;
    char padding1[24];
    Transform firstTransform;
    Transform secondTransform;
};

extern int __cdecl normalId(const Transform*);
extern int __cdecl normalIdOpposite(int);

struct S {
    char padding[0x228];
    Geometry geometry;
    int f();
};

int S::f()
{
    bool first = false;
    bool second = false;
    Geometry* g = &geometry;
    Edge* e = g->getFirst();

    while (e) {
        int type;
        if ((!e->blocked() &&
             ((type = e->kind()) == 6 || type == 7)) ||
            (!e->blocked() && e->kind() == 8)) {
            int normal;
            if (g == e->g0)
                normal = normalId(&e->firstTransform);
            else
                normal = normalIdOpposite(normalId(&e->secondTransform));

            if (normal == 1)
                first = true;
            else if (normal == 4)
                second = true;
        }
        e = g->getNextB(e);
    }

    if (first && second)
        return 1;
    return 0;
}
