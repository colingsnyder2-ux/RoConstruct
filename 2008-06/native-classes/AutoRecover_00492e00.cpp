// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: Src/Dst are opaque polymorphic types; real names unknown (TDs 0x92907c / 0x92e15c).
// Src has a parent pointer at +0x104 (vptr + 0x100 bytes of unknown members).
struct Dst;
struct Src {
    virtual ~Src() {}
    char pad[0x100];
    Src* parent; // +0x104
};
struct Dst : Src {
};

extern "C" void* __fastcall fn_004530f0(Dst* self, int unusedEdx);

// INFERRED: cdecl; walks the parent chain to the first Dst ancestor-or-self, then tail-calls fn_004530f0.
extern "C" void* fn_00492e00(Src* node)
{
    for (; node; node = node->parent) {
        Dst* d = dynamic_cast<Dst*>(node);
        if (d)
            return fn_004530f0(d, 0);
    }
    return 0;
}
