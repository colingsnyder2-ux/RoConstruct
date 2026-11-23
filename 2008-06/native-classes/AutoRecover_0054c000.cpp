// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: class unknown; object has an int field at +4 used as count/index.
struct Obj54c000 { int f0; int f4; };

extern "C" int __fastcall fn_0054d6e0(void* self, int unusedEdx, int a1, int a2);
extern "C" int __fastcall fn_0054d910(void* self, int unusedEdx);

extern "C" void __fastcall fn_0054c000(Obj54c000* self, int unusedEdx)
{
    fn_0054d6e0(self, 0, self->f4 + 1, 0);
    fn_0054d910(self, 0);
}
