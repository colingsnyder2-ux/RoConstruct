// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Control {
    virtual void unused();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
    void release();
};

__forceinline void Control::release()
{
    if (_InterlockedDecrement(&strong) == 0) {
        dispose();
        if (_InterlockedDecrement(&weak) == 0)
            destroy();
    }
}

struct S {
    void* pointer;
};

// INFERRED: callee takes a pointer to the first of the 5 stack dwords (a by-value record)
extern "C" int __stdcall fn_0048e3b0(unsigned long* a1);

// INFERRED: the 5 stack dwords form a record: 3 words, a ref-count control block pointer, and a trailing dword
extern "C" S* __fastcall fn_0048e5d0(S* self, int unusedEdx,
                                     unsigned long a1, unsigned long a2, unsigned long a3,
                                     Control* control, unsigned long last)
{
    self->pointer = 0;
    fn_0048e3b0(&a1);

    if (control)
        control->release();

    return self;
}
