// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: no BallBallContact header excerpt was provided, so the class is not
// defined here (that would export duplicate symbols). A file-local stand-in with
// a vptr and an inline virtual destructor models the compiler-generated deleting
// destructor, which stores the vptr, calls operator delete(this) when bit 0 of
// the flag is set, and returns this.
struct Local_0060cb70 {
    virtual ~Local_0060cb70() {}
};

// INFERRED: ??_E cannot be written directly, so the body is spelled out by hand.
// The explicit destructor call inlines the vptr store.
extern "C" void* __fastcall fn_0060cb70(Local_0060cb70* self, int unusedEdx, unsigned int flags)
{
    self->Local_0060cb70::~Local_0060cb70();
    if (flags & 1)
        ::operator delete((void*)self);
    return self;
}
