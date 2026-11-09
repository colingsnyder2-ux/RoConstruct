// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// scalar deleting dtor: inlined derived dtor (4 vptr stores) + base dtor sub_643df0
extern "C" char vt_8de534[], vt_8de524[], vt_8de51c[], vt_8de514[];
void __cdecl operator delete(void*);
struct Base_643df0 { ~Base_643df0(); };
struct Obj_006473f0 : Base_643df0 {
    void* vptr0; char pad4[0x10]; void* vptr14; void* vptr18; char pad1c[4]; void* vptr20;
    Obj_006473f0* destroy(unsigned int flags);
};
Obj_006473f0* Obj_006473f0::destroy(unsigned int flags)
{
    vptr0 = vt_8de534;
    vptr14 = vt_8de524;
    vptr18 = vt_8de51c;
    vptr20 = vt_8de514;
    this->Base_643df0::~Base_643df0();
    if (flags & 1)
        operator delete(this);
    return this;
}
