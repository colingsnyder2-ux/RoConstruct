// roc 2012-06 00b14cc0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14cc0
//
// 00b14cc0  a1a897e200           mov eax, dword ptr [0xe297a8]
// 00b14cc5  50                   push eax
// 00b14cc6  e849d4e6ff           call 0x982114
// 00b14ccb  83c404               add esp, 4
// 00b14cce  c7058097e2002c3cb400 mov dword ptr [0xe29780], 0xb43c2c
// 00b14cd8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14cc0(int);
void func_00b14cc0()
{
    G4_func_00b14cc0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
