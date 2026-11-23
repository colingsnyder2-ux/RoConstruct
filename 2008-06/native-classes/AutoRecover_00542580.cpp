// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no headers were available, so the layout is reconstructed from the
// disassembly. Each reference-counted object has a vtable at +0 and its atomic
// refcount at +4. The slot-0 virtual is the deleting destructor, called with 1.
struct RCObjectLocal {
    virtual int deletingDtor(int flags);
    int refCount; // G3D::AtomicInt32 at +4
};

struct RCPointerLocal {
    RCObjectLocal* m_p;
};

// G3D::AtomicInt32::decrement (thiscall)
extern "C" unsigned int __fastcall fn_0045ad80(int* atomic, int unusedEdx);
// G3D::ReferenceCountedObject::zeroWeakPointers (thiscall)
extern "C" void __fastcall fn_0045ad90(RCObjectLocal* obj, int unusedEdx);

extern "C" void __fastcall fn_00542580(RCPointerLocal* self, int unusedEdx)
{
    if (self->m_p != 0) {
        if (fn_0045ad80(&self->m_p->refCount, 0) == 0) {
            fn_0045ad90(self->m_p, 0);
            RCObjectLocal* obj = self->m_p;
            if (obj != 0) {
                obj->deletingDtor(1);
            }
        }
        self->m_p = 0;
    }
}
