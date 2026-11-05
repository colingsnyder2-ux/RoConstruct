// roc 2012-06 00b1f390  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f390
//
// 00b1f390  a1cc26e500           mov eax, dword ptr [0xe526cc]
// 00b1f395  50                   push eax
// 00b1f396  e8792de6ff           call 0x982114
// 00b1f39b  83c404               add esp, 4
// 00b1f39e  c705a026e5002c3cb400 mov dword ptr [0xe526a0], 0xb43c2c
// 00b1f3a8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f390(int);
void func_00b1f390()
{
    G4_func_00b1f390(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
