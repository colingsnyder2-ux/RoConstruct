// roc 2012-06 00b1c020  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c020
//
// 00b1c020  a174a7e400           mov eax, dword ptr [0xe4a774]
// 00b1c025  50                   push eax
// 00b1c026  e8e960e6ff           call 0x982114
// 00b1c02b  83c404               add esp, 4
// 00b1c02e  c7054ca7e4002c3cb400 mov dword ptr [0xe4a74c], 0xb43c2c
// 00b1c038  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c020(int);
void func_00b1c020()
{
    G4_func_00b1c020(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
