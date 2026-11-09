// roc 2012-06 00b1c630  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c630
//
// 00b1c630  a164b1e400           mov eax, dword ptr [0xe4b164]
// 00b1c635  50                   push eax
// 00b1c636  e8d95ae6ff           call 0x982114
// 00b1c63b  83c404               add esp, 4
// 00b1c63e  c7053cb1e4002c3cb400 mov dword ptr [0xe4b13c], 0xb43c2c
// 00b1c648  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c630(int);
void func_00b1c630()
{
    G4_func_00b1c630(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
