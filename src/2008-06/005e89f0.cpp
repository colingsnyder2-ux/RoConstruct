// from server: 100% by king_originala
struct Primitive;

struct List {
    void remove(Primitive*);
};

struct Primitive {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();

    int reserved[2];
    char* first;
    char* second;
};

void __cdecl f(Primitive* p)
{
    char* first = p->first;
    char* second = p->second;

    if (!p->slot3()) {
        reinterpret_cast<List*>(first + 0x34)->remove(p);
        if (second)
            reinterpret_cast<List*>(second + 0x34)->remove(p);
    } else {
        reinterpret_cast<List*>(first + 0x18)->remove(p);
        reinterpret_cast<List*>(second + 0x18)->remove(p);
    }
}
