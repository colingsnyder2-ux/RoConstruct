// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: arg counts follow the disassembly pushes (5534a0 takes 2, 553480 takes 1); the hint above had them swapped.
extern "C" int __fastcall fn_005c72e0(void* self, int unusedEdx, int a1);
extern "C" Fn_005534a0_Obj* __fastcall fn_005534a0(Fn_005534a0_Obj* self, int unusedEdx, int arg1);
extern "C" fn_00553480_Obj* __fastcall fn_00553480(fn_00553480_Obj* self, int unusedEdx, int arg1, int arg2);

extern "C" void* fn_00553340(void* self, int arg, unsigned char flag)
{
    char local1;
    int local8[2];
    int r = fn_005c72e0(&local1, 0, flag);
    int* p = fn_005534a0(local8, 0, arg, r);
    fn_00553480(self, 0, *p);
    return self;
}
