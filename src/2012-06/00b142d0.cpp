// roc 2012-06 00b142d0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b142d0
//
// 00b142d0  a1883de200           mov eax, dword ptr [0xe23d88]
// 00b142d5  50                   push eax
// 00b142d6  e839dee6ff           call 0x982114
// 00b142db  83c404               add esp, 4
// 00b142de  c705603de2002c3cb400 mov dword ptr [0xe23d60], 0xb43c2c
// 00b142e8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b142d0(int);
void func_00b142d0()
{
    G4_func_00b142d0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
