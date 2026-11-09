// from server: 40% by atomic.potato
// roc 2010-06 00774f70  unit: RBX::EquationDisplay  size: 140 bytes

extern "C" void* __stdcall sub_7A79A0(int);
extern "C" void __stdcall sub_9EA404();
extern "C" void __stdcall sub_9EA468(void*);
extern "C" void __stdcall sub_9EA400();

struct String {
    void ctor();
    void dtor();
    void assign(const String&);
    char pad[4];
};

struct EquationDisplay {
    void* field0;
    char pad1[8];
    void* fieldC;
    void* field10;
    void* field14;
    String field18;
    void* init(void* a, void* b, void* c, void* d, void* e, void* f, void* g);
};

void* EquationDisplay::init(void* a, void* b, void* c, void* d, void* e, void* f, void* g)
{
    void* p = sub_7A79A0(4);
    if (p != 0)
        *(void**)p = this;
    else
        p = 0;
    field0 = p;
    fieldC = 0;
    field10 = 0;
    field14 = 0;
    field18.ctor();
    sub_9EA468(&field18);
    field18.dtor();

    return this;
}
