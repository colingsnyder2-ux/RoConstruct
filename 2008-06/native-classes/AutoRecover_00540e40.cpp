// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: class unknown; treated as an opaque object whose first helper takes one dword
struct Obj540e40;

extern "C" int __fastcall fn_005425f0(void* self, int unusedEdx, int a1);

// INFERRED: copy-constructor-like function: passes the first dword of the argument to the helper, returns this
extern "C" Obj540e40* __fastcall fn_00540e40(Obj540e40* self, int unusedEdx, const int* arg)
{
    fn_005425f0(self, 0, *arg);
    return self;
}
