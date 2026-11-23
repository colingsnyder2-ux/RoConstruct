// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: layout and class names guessed from the disassembly.
// The object at +0x108 is a container: +0 iterator-proxy pointer, +0xc first, +0x10 last.
// Elements are 8 bytes (pointer + refcount, shared_ptr style).
// The _invalid_parameter_noinfo calls come from checked-iterator checks (_SECURE_SCL).
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

struct SrcBase { virtual ~SrcBase() {} };
struct DstType : SrcBase {};

struct Elem8 {
    SrcBase* ptr;
    int      rc;
};

struct Range8 {
    Range8* cont;       // +0: iterator-base container pointer
    int     pad[2];
    Elem8*  first;      // +0xc
    Elem8*  last;       // +0x10
};

struct Owner {
    char    pad[0x108];
    Range8* range;
};

extern "C" DstType* __fastcall fn_005fdf00(Owner* self, int unusedEdx)
{
    if (!self->range)
        return 0;

    Range8* r = self->range;
    Elem8*  endPtr = r->last;
    if (r->first > endPtr)
        _invalid_parameter_noinfo();
    Range8* endCont = r->cont;

    r = self->range;
    Elem8* cur = r->first;
    if (cur > r->last)
        _invalid_parameter_noinfo();
    Range8* curCont = r->cont;

    for (;;) {
        if (!curCont || curCont != endCont)
            _invalid_parameter_noinfo();
        if (cur == endPtr)
            return 0;
        if (!curCont)
            _invalid_parameter_noinfo();
        if (!(cur < curCont->last))
            _invalid_parameter_noinfo();
        DstType* d = dynamic_cast<DstType*>(cur->ptr);
        if (d)
            return d;
        if (!curCont)
            _invalid_parameter_noinfo();
        if (!(cur < curCont->last))
            _invalid_parameter_noinfo();
        ++cur;
    }
}
