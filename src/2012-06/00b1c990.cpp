// roc 2012-06 00b1c990  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1c990
//
// 00b1c990  a1d4d0e400           mov eax, dword ptr [0xe4d0d4]
// 00b1c995  50                   push eax
// 00b1c996  e87957e6ff           call 0x982114
// 00b1c99b  83c404               add esp, 4
// 00b1c99e  c705acd0e4002c3cb400 mov dword ptr [0xe4d0ac], 0xb43c2c
// 00b1c9a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1c990(int);
void func_00b1c990()
{
    G4_func_00b1c990(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
