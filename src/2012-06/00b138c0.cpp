// roc 2012-06 00b138c0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b138c0
//
// 00b138c0  a1c41fe200           mov eax, dword ptr [0xe21fc4]
// 00b138c5  50                   push eax
// 00b138c6  e849e8e6ff           call 0x982114
// 00b138cb  83c404               add esp, 4
// 00b138ce  c705981fe2002c3cb400 mov dword ptr [0xe21f98], 0xb43c2c
// 00b138d8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b138c0(int);
void func_00b138c0()
{
    G4_func_00b138c0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
