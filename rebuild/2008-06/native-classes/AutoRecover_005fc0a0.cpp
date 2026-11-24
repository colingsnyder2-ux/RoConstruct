// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" int __fastcall fn_005fbff0(void* self, int unusedEdx, int a1);
extern "C" void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: layout from disassembly; vector-like container of 8-byte elements (begin +0xc, end +0x10).
struct PairVec {
    char pad[0xc];
    struct Elem { int first; int second; } *begin;
    Elem* end;
};

struct Target {
    char pad[0x108];
    PairVec* vec;
};

extern "C" bool __fastcall fn_005fc0a0(Target* self, int unusedEdx, unsigned int index)
{
    PairVec* v = self->vec;
    unsigned int size = v ? (unsigned int)(v->end - v->begin) : 0;
    if (index > size)
        return false;
    unsigned int i = index - 1;
    if (i >= (unsigned int)(v->end - v->begin))
        _invalid_parameter_noinfo();
    fn_005fbff0(self, 0, v->begin[i].first);
    return true;
}
