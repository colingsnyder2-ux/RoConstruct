// roc 2012-06 00b12ff0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12ff0
//
// 00b12ff0  a1080ae200           mov eax, dword ptr [0xe20a08]
// 00b12ff5  50                   push eax
// 00b12ff6  e819f1e6ff           call 0x982114
// 00b12ffb  83c404               add esp, 4
// 00b12ffe  c705e009e2002c3cb400 mov dword ptr [0xe209e0], 0xb43c2c
// 00b13008  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12ff0(int);
void func_00b12ff0()
{
    G4_func_00b12ff0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
