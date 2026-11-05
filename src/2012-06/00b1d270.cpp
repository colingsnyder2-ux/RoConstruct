// roc 2012-06 00b1d270  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d270
//
// 00b1d270  a128e7e400           mov eax, dword ptr [0xe4e728]
// 00b1d275  50                   push eax
// 00b1d276  e8994ee6ff           call 0x982114
// 00b1d27b  83c404               add esp, 4
// 00b1d27e  c70500e7e4002c3cb400 mov dword ptr [0xe4e700], 0xb43c2c
// 00b1d288  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d270(int);
void func_00b1d270()
{
    G4_func_00b1d270(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
