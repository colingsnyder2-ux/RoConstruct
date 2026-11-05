// roc 2012-06 00b13fb0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13fb0
//
// 00b13fb0  a13838e200           mov eax, dword ptr [0xe23838]
// 00b13fb5  50                   push eax
// 00b13fb6  e859e1e6ff           call 0x982114
// 00b13fbb  83c404               add esp, 4
// 00b13fbe  c7051038e2002c3cb400 mov dword ptr [0xe23810], 0xb43c2c
// 00b13fc8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13fb0(int);
void func_00b13fb0()
{
    G4_func_00b13fb0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
