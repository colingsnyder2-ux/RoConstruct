// roc 2012-06 00b14410  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14410
//
// 00b14410  a13045e200           mov eax, dword ptr [0xe24530]
// 00b14415  50                   push eax
// 00b14416  e8f9dce6ff           call 0x982114
// 00b1441b  83c404               add esp, 4
// 00b1441e  c7050845e2002c3cb400 mov dword ptr [0xe24508], 0xb43c2c
// 00b14428  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14410(int);
void func_00b14410()
{
    G4_func_00b14410(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
