// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// scalar deleting dtor: inlined derived dtor (4 vptr stores) + base dtor sub_5d2b60
extern "C" char vt_8e3a14[], vt_8e3a08[], vt_8e3a00[], vt_8e39f8[];
void __cdecl operator delete(void*);
struct Base_5d2b60 { ~Base_5d2b60(); };
struct Obj_00671ab0 : Base_5d2b60 {
    void* vptr0; char pad4[0x10]; void* vptr14; void* vptr18; char pad1c[4]; void* vptr20;
    Obj_00671ab0* destroy(unsigned int flags);
};
Obj_00671ab0* Obj_00671ab0::destroy(unsigned int flags)
{
    vptr0 = vt_8e3a14;
    vptr14 = vt_8e3a08;
    vptr18 = vt_8e3a00;
    vptr20 = vt_8e39f8;
    this->Base_5d2b60::~Base_5d2b60();
    if (flags & 1)
        operator delete(this);
    return this;
}
