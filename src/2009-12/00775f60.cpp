// from server: 23% by atomic.potato
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);

struct Obj {
    void ctor(void*);
    void dtor();
};

struct Kernel {
    void addPoint(Obj*);
};

void* __fastcall sub_7c11e0(void*, void*);
void __fastcall sub_7c13a0(void*, void*);

void Kernel::addPoint(Obj* p)
{
    Obj* o = (Obj*)operator_new(0x34);
    if (o != 0) {
        o->ctor(p);
    }
    o->dtor();
    this->addPoint(o);
}
