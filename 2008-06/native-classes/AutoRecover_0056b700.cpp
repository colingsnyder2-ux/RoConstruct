// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout and element types are guesses from the disassembly; not compile-verified.
#include <vector>
#include <algorithm>

struct NameRep;
struct Descriptor {
    int pad0;
    NameRep* name;      // +4
    int pad8;
    Descriptor* owner;  // +0xc, its +4 is a NameRep*
};

extern "C" int __fastcall fn_0056b530(void* self, int unusedEdx);
extern "C" void __fastcall fn_00563090(void* lockObj, int unusedEdx);
extern "C" void __fastcall fn_005630e0(void* lockObj, int unusedEdx);
extern "C" int fn_0041faa0(NameRep* a, NameRep* b);
extern "C" void fn_00557330(void (*fn)(), long* flag);
extern "C" void fn_0056b6f0();

static bool descLess(const Descriptor* a, const Descriptor* b) {
    int c = fn_0041faa0(a->name, b->name);
    if (c < 0) return true;
    if (c != 0) return false;
    return fn_0041faa0(a->owner->name, b->owner->name) < 0;
}

static long g_once;
// INFERRED: function-local static pointer to a vector, created after call_once
static std::vector<Descriptor*>& allDescs() {
    fn_00557330(fn_0056b6f0, &g_once);
    static std::vector<Descriptor*>* v = new std::vector<Descriptor*>();
    return *v;
}

struct ClassDesc {
    std::vector<Descriptor*> descs;   // INFERRED: vector at +0 (begin +0xc, end +0x10)
    std::vector<ClassDesc*> bases;    // INFERRED: vector at +0x18 (begin +0x24, end +0x28)
};

extern "C" void __fastcall fn_0056b700(ClassDesc* self, int unusedEdx, Descriptor* d)
{
    void* lockObj = (void*)(size_t)fn_0056b530(self, 0);
    fn_00563090(lockObj, 0);

    std::vector<Descriptor*>::iterator it =
        std::lower_bound(self->descs.begin(), self->descs.end(), d, descLess);
    if (it == self->descs.end() || *it != d)
        self->descs.insert(it, d);

    for (std::vector<ClassDesc*>::iterator b = self->bases.begin(); b != self->bases.end(); ++b)
        fn_0056b700(*b, 0, d);

    std::vector<Descriptor*>::iterator p =
        std::lower_bound(allDescs().begin(), allDescs().end(), d, descLess);
    if (p == allDescs().end() || *p != d)
        allDescs().insert(p, d);

    fn_005630e0(lockObj, 0);
}
