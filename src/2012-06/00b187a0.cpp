// roc 2012-06 00b187a0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b187a0
//
// 00b187a0  a11c61e300           mov eax, dword ptr [0xe3611c]
// 00b187a5  50                   push eax
// 00b187a6  e86999e6ff           call 0x982114
// 00b187ab  83c404               add esp, 4
// 00b187ae  c705f460e3002c3cb400 mov dword ptr [0xe360f4], 0xb43c2c
// 00b187b8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b187a0(int);
void func_00b187a0()
{
    G4_func_00b187a0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
