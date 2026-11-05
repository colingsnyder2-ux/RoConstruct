// roc 2012-06 00b14ee0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14ee0
//
// 00b14ee0  a1f49ce200           mov eax, dword ptr [0xe29cf4]
// 00b14ee5  50                   push eax
// 00b14ee6  e829d2e6ff           call 0x982114
// 00b14eeb  83c404               add esp, 4
// 00b14eee  c705cc9ce2002c3cb400 mov dword ptr [0xe29ccc], 0xb43c2c
// 00b14ef8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14ee0(int);
void func_00b14ee0()
{
    G4_func_00b14ee0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
