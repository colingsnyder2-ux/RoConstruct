// roc 2012-06 00b15830  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15830
//
// 00b15830  a128a4e200           mov eax, dword ptr [0xe2a428]
// 00b15835  50                   push eax
// 00b15836  e8d9c8e6ff           call 0x982114
// 00b1583b  83c404               add esp, 4
// 00b1583e  c70500a4e2002c3cb400 mov dword ptr [0xe2a400], 0xb43c2c
// 00b15848  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15830(int);
void func_00b15830()
{
    G4_func_00b15830(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
