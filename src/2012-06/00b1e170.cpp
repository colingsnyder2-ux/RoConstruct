// roc 2012-06 00b1e170  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e170
//
// 00b1e170  a1a000e500           mov eax, dword ptr [0xe500a0]
// 00b1e175  50                   push eax
// 00b1e176  e8993fe6ff           call 0x982114
// 00b1e17b  83c404               add esp, 4
// 00b1e17e  c7057800e5002c3cb400 mov dword ptr [0xe50078], 0xb43c2c
// 00b1e188  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e170(int);
void func_00b1e170()
{
    G4_func_00b1e170(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
