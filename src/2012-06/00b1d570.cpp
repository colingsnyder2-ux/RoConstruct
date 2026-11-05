// roc 2012-06 00b1d570  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d570
//
// 00b1d570  a188e9e400           mov eax, dword ptr [0xe4e988]
// 00b1d575  50                   push eax
// 00b1d576  e8994be6ff           call 0x982114
// 00b1d57b  83c404               add esp, 4
// 00b1d57e  c7055ce9e4002c3cb400 mov dword ptr [0xe4e95c], 0xb43c2c
// 00b1d588  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d570(int);
void func_00b1d570()
{
    G4_func_00b1d570(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
