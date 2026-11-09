// roc 2012-06 00b151e0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b151e0
//
// 00b151e0  a1a8a1e200           mov eax, dword ptr [0xe2a1a8]
// 00b151e5  50                   push eax
// 00b151e6  e829cfe6ff           call 0x982114
// 00b151eb  83c404               add esp, 4
// 00b151ee  c70580a1e2002c3cb400 mov dword ptr [0xe2a180], 0xb43c2c
// 00b151f8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b151e0(int);
void func_00b151e0()
{
    G4_func_00b151e0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
