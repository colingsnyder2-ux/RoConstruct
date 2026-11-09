// roc 2012-06 00b15e30  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15e30
//
// 00b15e30  a180c5e200           mov eax, dword ptr [0xe2c580]
// 00b15e35  50                   push eax
// 00b15e36  e8d9c2e6ff           call 0x982114
// 00b15e3b  83c404               add esp, 4
// 00b15e3e  c70558c5e2002c3cb400 mov dword ptr [0xe2c558], 0xb43c2c
// 00b15e48  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15e30(int);
void func_00b15e30()
{
    G4_func_00b15e30(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
