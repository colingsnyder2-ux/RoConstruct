// roc 2012-06 00b1c490  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c490
//
// 00b1c490  a178b0e400           mov eax, dword ptr [0xe4b078]
// 00b1c495  50                   push eax
// 00b1c496  e8795ce6ff           call 0x982114
// 00b1c49b  83c404               add esp, 4
// 00b1c49e  c7054cb0e4002c3cb400 mov dword ptr [0xe4b04c], 0xb43c2c
// 00b1c4a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c490(int);
void func_00b1c490()
{
    G4_func_00b1c490(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
