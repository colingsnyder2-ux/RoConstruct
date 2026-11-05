// from server: 100% by king_originala
struct Viewport;
extern bool (__thiscall *getShadowsEnabled)(const Viewport*);

struct Object;
struct ObjectVTable {
    void* unused[12];
    bool (__thiscall *query)(Object*);
};
struct Object {
    ObjectVTable* vtable;
};

struct Item {
    unsigned long unused;
    unsigned short count;
};

struct S;
struct SVTable {
    void* unused[187];
    bool (__thiscall *queryFirst)(S*);
    bool (__thiscall *querySecond)(S*);
};

struct S {
    SVTable* vtable;
    char pad0[0xb8];
    Viewport* viewport;
    char pad1[0x8994];
    int mode;
    char pad2[0xa0];
    bool flag8af8;
    char pad3[0x88];
    bool flag8b81;
    bool flag8b82;

    bool f(Item* item, Object* object);
};

bool S::f(Item* item, Object* object)
{
    if (!flag8b82 && getShadowsEnabled(viewport) &&
        vtable->queryFirst(this)) {
        if (mode == 2 && object->vtable->query(object) && !flag8af8)
            return false;

        if ((vtable->querySecond(this) && mode == 2) ||
            mode == 1 || flag8b81) {
            if (item->count > 0)
                return false;
        }
    }
    return true;
}
