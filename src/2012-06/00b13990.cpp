// roc 2012-06 00b13990  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13990
//
// 00b13990  a13420e200           mov eax, dword ptr [0xe22034]
// 00b13995  50                   push eax
// 00b13996  e879e7e6ff           call 0x982114
// 00b1399b  83c404               add esp, 4
// 00b1399e  c7050c20e2002c3cb400 mov dword ptr [0xe2200c], 0xb43c2c
// 00b139a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13990(int);
void func_00b13990()
{
    G4_func_00b13990(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
