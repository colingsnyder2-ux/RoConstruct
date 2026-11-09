// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// scalar deleting dtor: inlined derived dtor (4 vptr stores) + base dtor sub_5d2b60
extern "C" char vt_8e2d44[], vt_8e2d34[], vt_8e2d2c[], vt_8e2d24[];
void __cdecl operator delete(void*);
struct Base_5d2b60 { ~Base_5d2b60(); };
struct Obj_0066a080 : Base_5d2b60 {
    void* vptr0; char pad4[0x10]; void* vptr14; void* vptr18; char pad1c[4]; void* vptr20;
    Obj_0066a080* destroy(unsigned int flags);
};
Obj_0066a080* Obj_0066a080::destroy(unsigned int flags)
{
    vptr0 = vt_8e2d44;
    vptr14 = vt_8e2d34;
    vptr18 = vt_8e2d2c;
    vptr20 = vt_8e2d24;
    this->Base_5d2b60::~Base_5d2b60();
    if (flags & 1)
        operator delete(this);
    return this;
}
