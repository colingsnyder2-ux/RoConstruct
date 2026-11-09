// roc 2012-06 00b15380  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15380
//
// 00b15380  a1489ae200           mov eax, dword ptr [0xe29a48]
// 00b15385  50                   push eax
// 00b15386  e889cde6ff           call 0x982114
// 00b1538b  83c404               add esp, 4
// 00b1538e  c705209ae2002c3cb400 mov dword ptr [0xe29a20], 0xb43c2c
// 00b15398  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15380(int);
void func_00b15380()
{
    G4_func_00b15380(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
