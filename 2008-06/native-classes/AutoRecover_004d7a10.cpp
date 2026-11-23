// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <new>

// INFERRED: layout and types are guesses from the constructor-like disassembly.
struct SrcImpl {
    // called cdecl-style (caller cleans 12 bytes), no 'this' passed
    void (__cdecl *fn)(void* a, void* b, int c);
};

struct SrcHolder {
    SrcImpl* impl;   // +0
    int pad;         // +4
    int data[1];     // +8 (address passed on)
};

struct Payload {
    int words[4];
    // INFERRED: non-trivial destructor explains the EH frame / state store
    ~Payload() {}
};

struct Obj {
    virtual ~Obj() {}   // INFERRED: vtable at 0x826bd4
    int field4;
    SrcImpl* source;    // +8
    int fieldC;
    Payload payload;    // +0x10
    Obj(SrcHolder* h);
};

Obj::Obj(SrcHolder* h)
{
    source = 0;
    if (h->impl != 0) {
        source = h->impl;
        h->impl->fn(h->data, &payload, 0);
    }
}

extern "C" Obj* __fastcall fn_004d7a10(Obj* self, int unusedEdx, SrcHolder* h)
{
    return new (self) Obj(h);
}
