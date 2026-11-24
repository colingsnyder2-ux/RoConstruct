// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: the target looks like a bound-functor invoker. The argument is a
// pointer to a record whose first field is a call function pointer, whose
// +8 field is a polymorphic helper object, and whose +0x10 field is inline
// data. The call function takes (a1, a2, 32-byte struct by value).

struct FunctorHelper;
typedef void (*HelperOp)(void* src, void* dst, int op);

struct FunctorHelperVtbl {
    HelperOp op;
};

struct FunctorHelper {
    FunctorHelperVtbl* vt;
};

struct BoundArg {
    FunctorHelper* helper;
    int pad4;
    char rest[24];
};

struct BoundFunctor {
    void (*call)(int a1, int a2, BoundArg arg);
    int pad4;
    FunctorHelper* helper;
    int padC;
    char data[16];
};

extern "C" void fn_0055edd0(BoundFunctor** self, int a1, int a2)
{
    BoundFunctor* f = *self;
    BoundArg arg;
    arg.helper = 0;
    if (f->helper) {
        arg.helper = f->helper;
        f->helper->vt->op(f->data, arg.rest, 0);
    }
    f->call(a1, a2, arg);
}
