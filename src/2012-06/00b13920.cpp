// roc 2012-06 00b13920  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13920
//
// 00b13920  a16023e200           mov eax, dword ptr [0xe22360]
// 00b13925  50                   push eax
// 00b13926  e8e9e7e6ff           call 0x982114
// 00b1392b  83c404               add esp, 4
// 00b1392e  c7053823e2002c3cb400 mov dword ptr [0xe22338], 0xb43c2c
// 00b13938  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13920(int);
void func_00b13920()
{
    G4_func_00b13920(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
