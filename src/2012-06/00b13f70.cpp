// roc 2012-06 00b13f70  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13f70
//
// 00b13f70  a19038e200           mov eax, dword ptr [0xe23890]
// 00b13f75  50                   push eax
// 00b13f76  e899e1e6ff           call 0x982114
// 00b13f7b  83c404               add esp, 4
// 00b13f7e  c7056838e2002c3cb400 mov dword ptr [0xe23868], 0xb43c2c
// 00b13f88  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13f70(int);
void func_00b13f70()
{
    G4_func_00b13f70(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
