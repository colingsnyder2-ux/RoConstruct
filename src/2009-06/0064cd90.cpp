// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// scalar deleting dtor: inlined derived dtor (4 vptr stores) + base dtor sub_5d2b60
extern "C" char vt_8df50c[], vt_8df4fc[], vt_8df4f4[], vt_8df4ec[];
void __cdecl operator delete(void*);
struct Base_5d2b60 { ~Base_5d2b60(); };
struct Obj_0064cd90 : Base_5d2b60 {
    void* vptr0; char pad4[0x10]; void* vptr14; void* vptr18; char pad1c[4]; void* vptr20;
    Obj_0064cd90* destroy(unsigned int flags);
};
Obj_0064cd90* Obj_0064cd90::destroy(unsigned int flags)
{
    vptr0 = vt_8df50c;
    vptr14 = vt_8df4fc;
    vptr18 = vt_8df4f4;
    vptr20 = vt_8df4ec;
    this->Base_5d2b60::~Base_5d2b60();
    if (flags & 1)
        operator delete(this);
    return this;
}
