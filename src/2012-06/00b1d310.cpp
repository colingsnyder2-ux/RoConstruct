// roc 2012-06 00b1d310  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d310
//
// 00b1d310  a1dce7e400           mov eax, dword ptr [0xe4e7dc]
// 00b1d315  50                   push eax
// 00b1d316  e8f94de6ff           call 0x982114
// 00b1d31b  83c404               add esp, 4
// 00b1d31e  c705b4e7e4002c3cb400 mov dword ptr [0xe4e7b4], 0xb43c2c
// 00b1d328  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d310(int);
void func_00b1d310()
{
    G4_func_00b1d310(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
