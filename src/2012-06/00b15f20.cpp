// roc 2012-06 00b15f20  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15f20
//
// 00b15f20  a12cc3e200           mov eax, dword ptr [0xe2c32c]
// 00b15f25  50                   push eax
// 00b15f26  e8e9c1e6ff           call 0x982114
// 00b15f2b  83c404               add esp, 4
// 00b15f2e  c70504c3e2002c3cb400 mov dword ptr [0xe2c304], 0xb43c2c
// 00b15f38  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15f20(int);
void func_00b15f20()
{
    G4_func_00b15f20(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
