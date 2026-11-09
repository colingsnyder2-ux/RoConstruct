// roc 2012-06 00b17990  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17990
//
// 00b17990  a1e02de300           mov eax, dword ptr [0xe32de0]
// 00b17995  50                   push eax
// 00b17996  e879a7e6ff           call 0x982114
// 00b1799b  83c404               add esp, 4
// 00b1799e  c705b82de3002c3cb400 mov dword ptr [0xe32db8], 0xb43c2c
// 00b179a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17990(int);
void func_00b17990()
{
    G4_func_00b17990(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
