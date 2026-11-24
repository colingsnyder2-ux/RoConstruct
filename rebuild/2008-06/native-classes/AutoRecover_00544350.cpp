// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: CRT import declared by hand; the call goes through the IAT (call [0x802890]).
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo(void);

// INFERRED: checked-iterator object, current pointer at +4 (SCL-style validation)
struct CheckedIter {
    int pad0;
    char* cur;
};

// INFERRED: the target pushes no stack args to these helpers, so none are declared.
extern "C" int __fastcall fn_00402410(void* self, int unusedEdx);
extern "C" char* __fastcall fn_00402400(void* self, int unusedEdx);
extern "C" char *fn_00543640(char* self);

extern "C" int __fastcall fn_00544350(CheckedIter* self, int unusedEdx)
{
    if (!(unsigned char)fn_00402410(self, 0))
        _invalid_parameter_noinfo();
    if (self->cur == *(char**)(fn_00402400(self, 0) + 0x18))
        _invalid_parameter_noinfo();
    return fn_00543640(self, 0, (int)self->cur);
}
