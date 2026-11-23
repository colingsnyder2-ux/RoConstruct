// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <windows.h>

// INFERRED: minimal local stand-ins for the types involved (no headers were provided).
struct RcObject {
    virtual void* deleting_dtor(unsigned flags) = 0;
    volatile LONG refCount;
};

struct LevelPtr {
    RcObject* p;
    ~LevelPtr();
};

struct DerivedBuilder {
    void* vtbl;
    char  base[0x1c];
    float f20;
    int   i24;
};

// INFERRED: vtable of the derived builder class (unknown global at 0x00827194)
extern "C" void* g_00827194[];

// ReferenceCountedObject::zeroWeakPointers
extern "C" void __fastcall fn_0045ad90(RcObject* self, int unusedEdx);

// LevelBuilder::LevelBuilder(ReferenceCountedPointer<Level>&, 3 floats by value, int)
extern "C" DerivedBuilder* __fastcall fn_00500d80(DerivedBuilder* self, int unusedEdx,
                                                  LevelPtr& level,
                                                  float x, float y, float z,
                                                  int arg);

inline LevelPtr::~LevelPtr()
{
    if (p) {
        if (InterlockedDecrement(&p->refCount) == 0) {
            fn_0045ad90(p, 0);
            if (p)
                p->deleting_dtor(1);
        }
    }
}

extern "C" DerivedBuilder* __fastcall fn_004fdaf0(DerivedBuilder* self, int unusedEdx,
                                                  LevelPtr level,
                                                  float a, float y, float b,
                                                  int arg5, int arg6, float arg7)
{
    const float* p1 = (b < a) ? &b : &a;
    const float* p2 = (b < a) ? &b : &a;
    fn_00500d80(self, 0, level, *p2, y, *p1, arg5);
    self->f20 = arg7;
    self->vtbl = g_00827194; // INFERRED: vtable of derived class
    self->i24 = arg6;
    return self;
}
