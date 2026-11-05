// roc 2012-06 00b14f80  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14f80
//
// 00b14f80  a19c95e200           mov eax, dword ptr [0xe2959c]
// 00b14f85  50                   push eax
// 00b14f86  e889d1e6ff           call 0x982114
// 00b14f8b  83c404               add esp, 4
// 00b14f8e  c7057495e2002c3cb400 mov dword ptr [0xe29574], 0xb43c2c
// 00b14f98  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14f80(int);
void func_00b14f80()
{
    G4_func_00b14f80(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
