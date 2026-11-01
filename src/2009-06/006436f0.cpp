// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// scalar deleting dtor: inlined derived dtor (4 vptr stores) + base dtor sub_5d2b60
extern "C" char vt_8de36c[], vt_8de35c[], vt_8de354[], vt_8de34c[];
void __cdecl operator delete(void*);
struct Base_5d2b60 { ~Base_5d2b60(); };
struct Obj_006436f0 : Base_5d2b60 {
    void* vptr0; char pad4[0x10]; void* vptr14; void* vptr18; char pad1c[4]; void* vptr20;
    Obj_006436f0* destroy(unsigned int flags);
};
Obj_006436f0* Obj_006436f0::destroy(unsigned int flags)
{
    vptr0 = vt_8de36c;
    vptr14 = vt_8de35c;
    vptr18 = vt_8de354;
    vptr20 = vt_8de34c;
    this->Base_5d2b60::~Base_5d2b60();
    if (flags & 1)
        operator delete(this);
    return this;
}
