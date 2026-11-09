// roc 2012-06 00b14d20  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14d20
//
// 00b14d20  a16499e200           mov eax, dword ptr [0xe29964]
// 00b14d25  50                   push eax
// 00b14d26  e8e9d3e6ff           call 0x982114
// 00b14d2b  83c404               add esp, 4
// 00b14d2e  c7053c99e2002c3cb400 mov dword ptr [0xe2993c], 0xb43c2c
// 00b14d38  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14d20(int);
void func_00b14d20()
{
    G4_func_00b14d20(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
