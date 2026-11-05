// roc 2012-06 00b1c470  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c470
//
// 00b1c470  a1a0afe400           mov eax, dword ptr [0xe4afa0]
// 00b1c475  50                   push eax
// 00b1c476  e8995ce6ff           call 0x982114
// 00b1c47b  83c404               add esp, 4
// 00b1c47e  c70574afe4002c3cb400 mov dword ptr [0xe4af74], 0xb43c2c
// 00b1c488  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c470(int);
void func_00b1c470()
{
    G4_func_00b1c470(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
