// roc 2012-06 00b1d350  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d350
//
// 00b1d350  a108e3e400           mov eax, dword ptr [0xe4e308]
// 00b1d355  50                   push eax
// 00b1d356  e8b94de6ff           call 0x982114
// 00b1d35b  83c404               add esp, 4
// 00b1d35e  c705e0e2e4002c3cb400 mov dword ptr [0xe4e2e0], 0xb43c2c
// 00b1d368  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d350(int);
void func_00b1d350()
{
    G4_func_00b1d350(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
