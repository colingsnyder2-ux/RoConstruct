// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

struct StrVecRaw {
    void** proxy;
    int    pad4;   // INFERRED: unused by target
    char   alloc[4];
    char*  first;
    char*  last;
    char*  end;
};

// INFERRED: empty iterator/allocator tag structs passed by value, as in std::_Uninit_copy.
struct Tag {};

extern "C" void* fn_006a0920(int size) throw(...);
extern "C" bool __fastcall fn_00428e50(StrVecRaw* self, int unusedEdx, int count) throw(...);
extern "C" void __fastcall fn_004077d0(StrVecRaw* self) throw(...);
extern "C" char* fn_0048b720(char* first, char* last, char* dest, void* alloc, Tag t1, Tag t2) throw(...);
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

extern "C" StrVecRaw* __fastcall fn_004299c0(StrVecRaw* self, int unusedEdx, StrVecRaw* other)
{
    void** p = (void**)fn_006a0920(4);
    self->proxy = p ? (*p = self, p) : 0;
    try {
        int junk;
        if (fn_00428e50(self, junk, (int)(other->last - other->first) / 28)) {
            char* lastp = other->last;
            if (other->first > lastp)
                _invalid_parameter_noinfo();
            char* firstp = other->first;
            if (firstp > other->last)
                _invalid_parameter_noinfo();
            Tag t;
            self->last = fn_0048b720(firstp, lastp, self->first, self->alloc, t, t);
        }
    } catch (...) {
        fn_004077d0(self);
        throw;
    }
    return self;
}
