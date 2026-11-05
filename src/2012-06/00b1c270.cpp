// roc 2012-06 00b1c270  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c270
//
// 00b1c270  a160ace400           mov eax, dword ptr [0xe4ac60]
// 00b1c275  50                   push eax
// 00b1c276  e8995ee6ff           call 0x982114
// 00b1c27b  83c404               add esp, 4
// 00b1c27e  c70538ace4002c3cb400 mov dword ptr [0xe4ac38], 0xb43c2c
// 00b1c288  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c270(int);
void func_00b1c270()
{
    G4_func_00b1c270(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
