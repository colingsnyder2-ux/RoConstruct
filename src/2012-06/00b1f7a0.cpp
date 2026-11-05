// roc 2012-06 00b1f7a0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f7a0
//
// 00b1f7a0  a1f42ce500           mov eax, dword ptr [0xe52cf4]
// 00b1f7a5  50                   push eax
// 00b1f7a6  e86929e6ff           call 0x982114
// 00b1f7ab  83c404               add esp, 4
// 00b1f7ae  c705cc2ce5002c3cb400 mov dword ptr [0xe52ccc], 0xb43c2c
// 00b1f7b8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f7a0(int);
void func_00b1f7a0()
{
    G4_func_00b1f7a0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
