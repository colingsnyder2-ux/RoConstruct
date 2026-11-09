// roc 2012-06 00b17b80  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17b80
//
// 00b17b80  a19034e300           mov eax, dword ptr [0xe33490]
// 00b17b85  50                   push eax
// 00b17b86  e889a5e6ff           call 0x982114
// 00b17b8b  83c404               add esp, 4
// 00b17b8e  c7056834e3002c3cb400 mov dword ptr [0xe33468], 0xb43c2c
// 00b17b98  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17b80(int);
void func_00b17b80()
{
    G4_func_00b17b80(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
