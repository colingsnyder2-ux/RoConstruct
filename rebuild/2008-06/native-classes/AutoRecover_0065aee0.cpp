// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: checked-iterator vector<8-byte element>::erase(first, last); layout from disassembly.
struct Elem { unsigned a, b; };
struct Iter { void* cont; Elem* ptr; };
struct Vec8 {
    void* proxy;
    unsigned pad[2];
    Elem* first;
    Elem* last;
};

extern "C" Iter* __fastcall fn_0065aee0(Vec8* self, int unusedEdx, Iter* out,
                                        void* firstCont, Elem* firstPtr,
                                        void* lastCont, Elem* lastPtr)
{
    out->cont = 0;
    if (!self || firstPtr < self->first || firstPtr > self->last)
        _invalid_parameter_noinfo();
    out->cont = self->proxy;
    out->ptr = firstPtr;
    if (self->first > lastPtr || lastPtr > self->last)
        _invalid_parameter_noinfo();
    if (!out->cont || out->cont != self->proxy)
        _invalid_parameter_noinfo();
    if (out->ptr != lastPtr) {
        Elem* end = self->last;
        Elem* newEnd = out->ptr + (end - lastPtr);
        for (Elem* p = lastPtr; p != end; ++p)
            p[out->ptr - lastPtr] = *p;
        self->last = newEnd;
    }
    return out;
}
