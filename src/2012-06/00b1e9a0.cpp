// roc 2012-06 00b1e9a0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e9a0
//
// 00b1e9a0  a1d80ee500           mov eax, dword ptr [0xe50ed8]
// 00b1e9a5  50                   push eax
// 00b1e9a6  e86937e6ff           call 0x982114
// 00b1e9ab  83c404               add esp, 4
// 00b1e9ae  c705ac0ee5002c3cb400 mov dword ptr [0xe50eac], 0xb43c2c
// 00b1e9b8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e9a0(int);
void func_00b1e9a0()
{
    G4_func_00b1e9a0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
