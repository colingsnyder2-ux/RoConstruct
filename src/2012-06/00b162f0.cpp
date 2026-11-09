// roc 2012-06 00b162f0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b162f0
//
// 00b162f0  a12cd8e200           mov eax, dword ptr [0xe2d82c]
// 00b162f5  50                   push eax
// 00b162f6  e819bee6ff           call 0x982114
// 00b162fb  83c404               add esp, 4
// 00b162fe  c70504d8e2002c3cb400 mov dword ptr [0xe2d804], 0xb43c2c
// 00b16308  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b162f0(int);
void func_00b162f0()
{
    G4_func_00b162f0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
