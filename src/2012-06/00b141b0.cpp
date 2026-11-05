// roc 2012-06 00b141b0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b141b0
//
// 00b141b0  a1e03ae200           mov eax, dword ptr [0xe23ae0]
// 00b141b5  50                   push eax
// 00b141b6  e859dfe6ff           call 0x982114
// 00b141bb  83c404               add esp, 4
// 00b141be  c705b83ae2002c3cb400 mov dword ptr [0xe23ab8], 0xb43c2c
// 00b141c8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b141b0(int);
void func_00b141b0()
{
    G4_func_00b141b0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
