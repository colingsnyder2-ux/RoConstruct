// roc 2012-06 00b152c0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b152c0
//
// 00b152c0  a19c9fe200           mov eax, dword ptr [0xe29f9c]
// 00b152c5  50                   push eax
// 00b152c6  e849cee6ff           call 0x982114
// 00b152cb  83c404               add esp, 4
// 00b152ce  c705749fe2002c3cb400 mov dword ptr [0xe29f74], 0xb43c2c
// 00b152d8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b152c0(int);
void func_00b152c0()
{
    G4_func_00b152c0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
