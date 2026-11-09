// roc 2012-06 00b1f760  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f760
//
// 00b1f760  a1402ce500           mov eax, dword ptr [0xe52c40]
// 00b1f765  50                   push eax
// 00b1f766  e8a929e6ff           call 0x982114
// 00b1f76b  83c404               add esp, 4
// 00b1f76e  c705142ce5002c3cb400 mov dword ptr [0xe52c14], 0xb43c2c
// 00b1f778  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f760(int);
void func_00b1f760()
{
    G4_func_00b1f760(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
