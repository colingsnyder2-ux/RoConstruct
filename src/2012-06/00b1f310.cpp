// roc 2012-06 00b1f310  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f310
//
// 00b1f310  a1fc26e500           mov eax, dword ptr [0xe526fc]
// 00b1f315  50                   push eax
// 00b1f316  e8f92de6ff           call 0x982114
// 00b1f31b  83c404               add esp, 4
// 00b1f31e  c705d426e5002c3cb400 mov dword ptr [0xe526d4], 0xb43c2c
// 00b1f328  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f310(int);
void func_00b1f310()
{
    G4_func_00b1f310(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
