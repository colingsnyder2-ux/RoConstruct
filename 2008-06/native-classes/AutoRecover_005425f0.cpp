// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

namespace G3D {
    // INFERRED: minimal local stand-in for G3D::AtomicInt32 (real header not shown)
    class AtomicInt32 {
    public:
        int value;
        void increment();
    };
}

// INFERRED: referenced object has a G3D::AtomicInt32 refcount at offset 4
struct RefCountedObj {
    int vtableOrPad;
    G3D::AtomicInt32 refCount;
};

// INFERRED: intrusive smart-pointer-like holder; pointer stored at offset 0
struct RefHolder {
    RefCountedObj* ptr;
};

// INFERRED: the disassembly pushes no stack args for this call (release of current pointer)
extern "C" int __fastcall fn_00542580(void* self, int unusedEdx);

extern "C" void __fastcall fn_005425f0(RefHolder* self, int unusedEdx, RefCountedObj* p)
{
    if (p != self->ptr) {
        fn_00542580(self, 0);
        if (p) {
            self->ptr = p;
            self->ptr->refCount.increment();
        }
    }
}
