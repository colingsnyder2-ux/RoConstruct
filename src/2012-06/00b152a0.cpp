// roc 2012-06 00b152a0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b152a0
//
// 00b152a0  a1ac9ae200           mov eax, dword ptr [0xe29aac]
// 00b152a5  50                   push eax
// 00b152a6  e869cee6ff           call 0x982114
// 00b152ab  83c404               add esp, 4
// 00b152ae  c705809ae2002c3cb400 mov dword ptr [0xe29a80], 0xb43c2c
// 00b152b8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b152a0(int);
void func_00b152a0()
{
    G4_func_00b152a0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
