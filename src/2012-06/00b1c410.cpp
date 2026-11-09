// roc 2012-06 00b1c410  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c410
//
// 00b1c410  a1ecade400           mov eax, dword ptr [0xe4adec]
// 00b1c415  50                   push eax
// 00b1c416  e8f95ce6ff           call 0x982114
// 00b1c41b  83c404               add esp, 4
// 00b1c41e  c705c4ade4002c3cb400 mov dword ptr [0xe4adc4], 0xb43c2c
// 00b1c428  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c410(int);
void func_00b1c410()
{
    G4_func_00b1c410(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
