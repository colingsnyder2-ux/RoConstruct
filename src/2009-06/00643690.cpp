// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// scalar deleting dtor: inlined derived dtor (4 vptr stores) + base dtor sub_5d2b60
extern "C" char vt_8de304[], vt_8de2f8[], vt_8de2f0[], vt_8de2e8[];
void __cdecl operator delete(void*);
struct Base_5d2b60 { ~Base_5d2b60(); };
struct Obj_00643690 : Base_5d2b60 {
    void* vptr0; char pad4[0x10]; void* vptr14; void* vptr18; char pad1c[4]; void* vptr20;
    Obj_00643690* destroy(unsigned int flags);
};
Obj_00643690* Obj_00643690::destroy(unsigned int flags)
{
    vptr0 = vt_8de304;
    vptr14 = vt_8de2f8;
    vptr18 = vt_8de2f0;
    vptr20 = vt_8de2e8;
    this->Base_5d2b60::~Base_5d2b60();
    if (flags & 1)
        operator delete(this);
    return this;
}
