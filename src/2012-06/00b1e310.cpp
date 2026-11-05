// roc 2012-06 00b1e310  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1e310
//
// 00b1e310  a14404e500           mov eax, dword ptr [0xe50444]
// 00b1e315  50                   push eax
// 00b1e316  e8f93de6ff           call 0x982114
// 00b1e31b  83c404               add esp, 4
// 00b1e31e  c7051804e5002c3cb400 mov dword ptr [0xe50418], 0xb43c2c
// 00b1e328  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1e310(int);
void func_00b1e310()
{
    G4_func_00b1e310(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
