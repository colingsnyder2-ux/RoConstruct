// roc 2012-06 00b13f10  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13f10
//
// 00b13f10  a1303ae200           mov eax, dword ptr [0xe23a30]
// 00b13f15  50                   push eax
// 00b13f16  e8f9e1e6ff           call 0x982114
// 00b13f1b  83c404               add esp, 4
// 00b13f1e  c705083ae2002c3cb400 mov dword ptr [0xe23a08], 0xb43c2c
// 00b13f28  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13f10(int);
void func_00b13f10()
{
    G4_func_00b13f10(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
