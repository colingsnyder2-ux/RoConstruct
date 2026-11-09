// roc 2012-06 00b1c830  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c830
//
// 00b1c830  a174d4e400           mov eax, dword ptr [0xe4d474]
// 00b1c835  50                   push eax
// 00b1c836  e8d958e6ff           call 0x982114
// 00b1c83b  83c404               add esp, 4
// 00b1c83e  c7054cd4e4002c3cb400 mov dword ptr [0xe4d44c], 0xb43c2c
// 00b1c848  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c830(int);
void func_00b1c830()
{
    G4_func_00b1c830(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
