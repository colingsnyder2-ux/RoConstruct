// roc 2012-06 00b138a0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b138a0
//
// 00b138a0  a10825e200           mov eax, dword ptr [0xe22508]
// 00b138a5  50                   push eax
// 00b138a6  e869e8e6ff           call 0x982114
// 00b138ab  83c404               add esp, 4
// 00b138ae  c705dc24e2002c3cb400 mov dword ptr [0xe224dc], 0xb43c2c
// 00b138b8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b138a0(int);
void func_00b138a0()
{
    G4_func_00b138a0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
