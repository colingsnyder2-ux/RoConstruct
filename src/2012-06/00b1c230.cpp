// roc 2012-06 00b1c230  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c230
//
// 00b1c230  a18cace400           mov eax, dword ptr [0xe4ac8c]
// 00b1c235  50                   push eax
// 00b1c236  e8d95ee6ff           call 0x982114
// 00b1c23b  83c404               add esp, 4
// 00b1c23e  c70564ace4002c3cb400 mov dword ptr [0xe4ac64], 0xb43c2c
// 00b1c248  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c230(int);
void func_00b1c230()
{
    G4_func_00b1c230(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
