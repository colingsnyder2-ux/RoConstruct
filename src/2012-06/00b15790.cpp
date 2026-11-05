// roc 2012-06 00b15790  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15790
//
// 00b15790  a158a4e200           mov eax, dword ptr [0xe2a458]
// 00b15795  50                   push eax
// 00b15796  e879c9e6ff           call 0x982114
// 00b1579b  83c404               add esp, 4
// 00b1579e  c7052ca4e2002c3cb400 mov dword ptr [0xe2a42c], 0xb43c2c
// 00b157a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15790(int);
void func_00b15790()
{
    G4_func_00b15790(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
