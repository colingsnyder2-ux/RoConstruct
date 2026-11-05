// roc 2012-06 00b12fb0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12fb0
//
// 00b12fb0  a1c008e200           mov eax, dword ptr [0xe208c0]
// 00b12fb5  50                   push eax
// 00b12fb6  e859f1e6ff           call 0x982114
// 00b12fbb  83c404               add esp, 4
// 00b12fbe  c7059808e2002c3cb400 mov dword ptr [0xe20898], 0xb43c2c
// 00b12fc8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12fb0(int);
void func_00b12fb0()
{
    G4_func_00b12fb0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
