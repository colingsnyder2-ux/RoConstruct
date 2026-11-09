// roc 2012-06 00b1c610  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c610
//
// 00b1c610  a1a0b2e400           mov eax, dword ptr [0xe4b2a0]
// 00b1c615  50                   push eax
// 00b1c616  e8f95ae6ff           call 0x982114
// 00b1c61b  83c404               add esp, 4
// 00b1c61e  c70578b2e4002c3cb400 mov dword ptr [0xe4b278], 0xb43c2c
// 00b1c628  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c610(int);
void func_00b1c610()
{
    G4_func_00b1c610(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
