// roc 2012-06 00b154a0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b154a0
//
// 00b154a0  a1089be200           mov eax, dword ptr [0xe29b08]
// 00b154a5  50                   push eax
// 00b154a6  e869cce6ff           call 0x982114
// 00b154ab  83c404               add esp, 4
// 00b154ae  c705e09ae2002c3cb400 mov dword ptr [0xe29ae0], 0xb43c2c
// 00b154b8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b154a0(int);
void func_00b154a0()
{
    G4_func_00b154a0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
