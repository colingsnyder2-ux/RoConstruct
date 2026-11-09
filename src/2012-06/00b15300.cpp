// roc 2012-06 00b15300  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15300
//
// 00b15300  a144a1e200           mov eax, dword ptr [0xe2a144]
// 00b15305  50                   push eax
// 00b15306  e809cee6ff           call 0x982114
// 00b1530b  83c404               add esp, 4
// 00b1530e  c7051ca1e2002c3cb400 mov dword ptr [0xe2a11c], 0xb43c2c
// 00b15318  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15300(int);
void func_00b15300()
{
    G4_func_00b15300(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
