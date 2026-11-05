// roc 2012-06 00b20930  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20930
//
// 00b20930  a19059e500           mov eax, dword ptr [0xe55990]
// 00b20935  50                   push eax
// 00b20936  e8d917e6ff           call 0x982114
// 00b2093b  83c404               add esp, 4
// 00b2093e  c7056859e5002c3cb400 mov dword ptr [0xe55968], 0xb43c2c
// 00b20948  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20930(int);
void func_00b20930()
{
    G4_func_00b20930(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
