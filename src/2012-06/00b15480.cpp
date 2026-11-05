// roc 2012-06 00b15480  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15480
//
// 00b15480  a1c09ee200           mov eax, dword ptr [0xe29ec0]
// 00b15485  50                   push eax
// 00b15486  e889cce6ff           call 0x982114
// 00b1548b  83c404               add esp, 4
// 00b1548e  c705989ee2002c3cb400 mov dword ptr [0xe29e98], 0xb43c2c
// 00b15498  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15480(int);
void func_00b15480()
{
    G4_func_00b15480(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
