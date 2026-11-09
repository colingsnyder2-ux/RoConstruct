// roc 2012-06 00b15ad0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15ad0
//
// 00b15ad0  a1a0b1e200           mov eax, dword ptr [0xe2b1a0]
// 00b15ad5  50                   push eax
// 00b15ad6  e839c6e6ff           call 0x982114
// 00b15adb  83c404               add esp, 4
// 00b15ade  c70578b1e2002c3cb400 mov dword ptr [0xe2b178], 0xb43c2c
// 00b15ae8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15ad0(int);
void func_00b15ad0()
{
    G4_func_00b15ad0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
