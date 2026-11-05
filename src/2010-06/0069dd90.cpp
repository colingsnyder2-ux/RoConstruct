// from server: 100% by tester
struct S {
    bool f(int, int);
};

bool S::f(int, int)
{
    struct VTable {
        char pad[0x1c];
        void (__thiscall *fn)(S*);
    };
    VTable* vt = *(VTable**)this;
    vt->fn(this);
    return false;
}