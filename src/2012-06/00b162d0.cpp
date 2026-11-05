// roc 2012-06 00b162d0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b162d0
//
// 00b162d0  a100d8e200           mov eax, dword ptr [0xe2d800]
// 00b162d5  50                   push eax
// 00b162d6  e839bee6ff           call 0x982114
// 00b162db  83c404               add esp, 4
// 00b162de  c705d8d7e2002c3cb400 mov dword ptr [0xe2d7d8], 0xb43c2c
// 00b162e8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b162d0(int);
void func_00b162d0()
{
    G4_func_00b162d0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
