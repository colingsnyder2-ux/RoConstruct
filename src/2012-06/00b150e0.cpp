// roc 2012-06 00b150e0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b150e0
//
// 00b150e0  a1209de200           mov eax, dword ptr [0xe29d20]
// 00b150e5  50                   push eax
// 00b150e6  e829d0e6ff           call 0x982114
// 00b150eb  83c404               add esp, 4
// 00b150ee  c705f89ce2002c3cb400 mov dword ptr [0xe29cf8], 0xb43c2c
// 00b150f8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b150e0(int);
void func_00b150e0()
{
    G4_func_00b150e0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
