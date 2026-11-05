// roc 2012-06 00b1d990  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d990
//
// 00b1d990  a194f3e400           mov eax, dword ptr [0xe4f394]
// 00b1d995  50                   push eax
// 00b1d996  e87947e6ff           call 0x982114
// 00b1d99b  83c404               add esp, 4
// 00b1d99e  c7056cf3e4002c3cb400 mov dword ptr [0xe4f36c], 0xb43c2c
// 00b1d9a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d990(int);
void func_00b1d990()
{
    G4_func_00b1d990(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
