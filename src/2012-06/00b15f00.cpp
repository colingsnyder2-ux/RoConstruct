// roc 2012-06 00b15f00  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15f00
//
// 00b15f00  a184c3e200           mov eax, dword ptr [0xe2c384]
// 00b15f05  50                   push eax
// 00b15f06  e809c2e6ff           call 0x982114
// 00b15f0b  83c404               add esp, 4
// 00b15f0e  c7055cc3e2002c3cb400 mov dword ptr [0xe2c35c], 0xb43c2c
// 00b15f18  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15f00(int);
void func_00b15f00()
{
    G4_func_00b15f00(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
