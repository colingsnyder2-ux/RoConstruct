// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <string>

// INFERRED: all class/layout names below are guesses from the disassembly
// (no headers were provided).

extern "C" void __fastcall fn_0045ad90(void* self, int unusedEdx); // ReferenceCountedObject::zeroWeakPointers

struct RcObj;

// INFERRED: G3D::ReferenceCountedPointer-like smart pointer
struct RcPtr {
    RcObj* p;
    RcPtr() {} // intentionally uninitialised (used as an out-parameter)
    inline ~RcPtr();
};

struct RcObj {
    virtual ~RcObj() {}
    long refCount; // +4
    int  pad8;     // +8 (weak pointer list)
    std::string name; // +0xc
    virtual void v1() {}
    virtual void v2() {}
    virtual void v3() {}
    virtual void v4() {}
    virtual void v5() {}
    virtual void getChild(RcPtr* out, int arg) {} // slot 6 (+0x18)
};

extern "C" long __stdcall InterlockedDecrement(volatile long*);

inline RcPtr::~RcPtr()
{
    RcObj* o = p;
    if (o) {
        if (InterlockedDecrement(&o->refCount) == 0) {
            fn_0045ad90(p, 0);
            if (p) delete p;
        }
        p = 0;
    }
}

// INFERRED: owner object: +4 an int id, +8 a std::string
struct Owner {
    int         unk0;
    int         id;
    std::string name;
};

extern "C" void __fastcall fn_006700e0(Owner* self, int unusedEdx, int arg1, RcPtr arg2)
{
    if (arg2.p == 0) {
        self->name = "";  // INFERRED: literal at 0x80b716
        return;
    }
    self->name = arg2.p->name;
    RcPtr child;
    arg2.p->getChild(&child, self->id);
}
