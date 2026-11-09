// from server: 67% by atomic.potato




extern "C" void __cdecl sub_4E06C0(void*, char*);
extern "C" void* __cdecl sub_7A79A0(unsigned int);

struct VBase {
    virtual void vf0();
    virtual void vf1();
};

struct VHolder {
    void* vt;
    char c;
};

void* __cdecl sub_4E9710(void* a, void** b)
{
    char tmp;
    sub_4E06C0(a, &tmp);
    VHolder* p = (VHolder*)sub_7A79A0(8);
    if (p) {
        p->vt = (void*)0xA00AA4;
        p->c = tmp;
    } else {
        p = 0;
    }
    void* old = *b;
    *b = p;
    if (old) {
        VBase* v = (VBase*)old;
        v->vf0();
    }
    return p;
}
