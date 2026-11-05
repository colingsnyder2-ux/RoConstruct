// roc 2012-06 00b1f7e0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f7e0
//
// 00b1f7e0  a1fc2de500           mov eax, dword ptr [0xe52dfc]
// 00b1f7e5  50                   push eax
// 00b1f7e6  e82929e6ff           call 0x982114
// 00b1f7eb  83c404               add esp, 4
// 00b1f7ee  c705d42de5002c3cb400 mov dword ptr [0xe52dd4], 0xb43c2c
// 00b1f7f8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f7e0(int);
void func_00b1f7e0()
{
    G4_func_00b1f7e0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
