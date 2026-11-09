// from server: 100% by why2
struct S {
    bool f(int, int);
};

bool S::f(int, int)
{
    struct VTable {
        char pad[0x18];
        void (__thiscall *fn)(S*);
    };
    VTable* vt = *(VTable**)this;
    vt->fn(this);
    return false;
}
