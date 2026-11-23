// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" int __fastcall fn_0048d9e0(void* self, int unusedEdx, int a1, int a2);

extern "C" void* _AddressOfReturnAddress(void);
#pragma intrinsic(_AddressOfReturnAddress)

// INFERRED: the original reads two stack dwords (object, const char*) and returns with
// a plain ret, so no callee-cleaned stack args. The required signature is
// (self, unusedEdx) with 0 stack args, so the two real args are read from the caller's
// stack right above the return address.
extern "C" void* __fastcall fn_0048e620(void* self, int unusedEdx)
{
    void** ra = (void**)_AddressOfReturnAddress();
    void* obj = ra[1];
    const char* s = (const char*)ra[2];

    volatile int dummy = 0; // INFERRED: dead local stored to [esp+4]
    (void)dummy;
    const char* p = s;
    while (*p++ != '\0') {
    }
    const char* end = s + (p - (s + 1));
    fn_0048d9e0(obj, 0, (int)s, (int)end);
    return obj;
}
