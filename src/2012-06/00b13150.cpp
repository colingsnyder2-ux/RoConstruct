// roc 2012-06 00b13150  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13150
//
// 00b13150  a1c40fe200           mov eax, dword ptr [0xe20fc4]
// 00b13155  50                   push eax
// 00b13156  e8b9efe6ff           call 0x982114
// 00b1315b  83c404               add esp, 4
// 00b1315e  c7059c0fe2002c3cb400 mov dword ptr [0xe20f9c], 0xb43c2c
// 00b13168  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b13150(int);
void func_00b13150()
{
    G4_func_00b13150(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
