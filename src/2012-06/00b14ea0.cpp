// roc 2012-06 00b14ea0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14ea0
//
// 00b14ea0  a1609be200           mov eax, dword ptr [0xe29b60]
// 00b14ea5  50                   push eax
// 00b14ea6  e869d2e6ff           call 0x982114
// 00b14eab  83c404               add esp, 4
// 00b14eae  c705389be2002c3cb400 mov dword ptr [0xe29b38], 0xb43c2c
// 00b14eb8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14ea0(int);
void func_00b14ea0()
{
    G4_func_00b14ea0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
