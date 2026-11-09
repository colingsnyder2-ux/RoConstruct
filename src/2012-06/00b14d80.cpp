// roc 2012-06 00b14d80  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14d80
//
// 00b14d80  a1a49de200           mov eax, dword ptr [0xe29da4]
// 00b14d85  50                   push eax
// 00b14d86  e889d3e6ff           call 0x982114
// 00b14d8b  83c404               add esp, 4
// 00b14d8e  c7057c9de2002c3cb400 mov dword ptr [0xe29d7c], 0xb43c2c
// 00b14d98  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14d80(int);
void func_00b14d80()
{
    G4_func_00b14d80(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
