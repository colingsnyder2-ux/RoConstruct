// roc 2012-06 00b154e0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b154e0
//
// 00b154e0  a1fc9de200           mov eax, dword ptr [0xe29dfc]
// 00b154e5  50                   push eax
// 00b154e6  e829cce6ff           call 0x982114
// 00b154eb  83c404               add esp, 4
// 00b154ee  c705d49de2002c3cb400 mov dword ptr [0xe29dd4], 0xb43c2c
// 00b154f8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b154e0(int);
void func_00b154e0()
{
    G4_func_00b154e0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
