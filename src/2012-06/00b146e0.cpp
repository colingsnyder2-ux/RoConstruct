// roc 2012-06 00b146e0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b146e0
//
// 00b146e0  a1f04de200           mov eax, dword ptr [0xe24df0]
// 00b146e5  50                   push eax
// 00b146e6  e829dae6ff           call 0x982114
// 00b146eb  83c404               add esp, 4
// 00b146ee  c705c84de2002c3cb400 mov dword ptr [0xe24dc8], 0xb43c2c
// 00b146f8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b146e0(int);
void func_00b146e0()
{
    G4_func_00b146e0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
