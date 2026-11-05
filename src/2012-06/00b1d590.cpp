// roc 2012-06 00b1d590  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d590
//
// 00b1d590  a120e9e400           mov eax, dword ptr [0xe4e920]
// 00b1d595  50                   push eax
// 00b1d596  e8794be6ff           call 0x982114
// 00b1d59b  83c404               add esp, 4
// 00b1d59e  c705f4e8e4002c3cb400 mov dword ptr [0xe4e8f4], 0xb43c2c
// 00b1d5a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d590(int);
void func_00b1d590()
{
    G4_func_00b1d590(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
