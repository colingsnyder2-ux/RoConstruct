// roc 2012-06 00b14dc0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14dc0
//
// 00b14dc0  a19099e200           mov eax, dword ptr [0xe29990]
// 00b14dc5  50                   push eax
// 00b14dc6  e849d3e6ff           call 0x982114
// 00b14dcb  83c404               add esp, 4
// 00b14dce  c7056899e2002c3cb400 mov dword ptr [0xe29968], 0xb43c2c
// 00b14dd8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14dc0(int);
void func_00b14dc0()
{
    G4_func_00b14dc0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
