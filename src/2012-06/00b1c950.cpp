// roc 2012-06 00b1c950  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c950
//
// 00b1c950  a110d0e400           mov eax, dword ptr [0xe4d010]
// 00b1c955  50                   push eax
// 00b1c956  e8b957e6ff           call 0x982114
// 00b1c95b  83c404               add esp, 4
// 00b1c95e  c705e8cfe4002c3cb400 mov dword ptr [0xe4cfe8], 0xb43c2c
// 00b1c968  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c950(int);
void func_00b1c950()
{
    G4_func_00b1c950(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
