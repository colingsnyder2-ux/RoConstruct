// roc 2012-06 00b14de0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14de0
//
// 00b14de0  a1189ce200           mov eax, dword ptr [0xe29c18]
// 00b14de5  50                   push eax
// 00b14de6  e829d3e6ff           call 0x982114
// 00b14deb  83c404               add esp, 4
// 00b14dee  c705f09be2002c3cb400 mov dword ptr [0xe29bf0], 0xb43c2c
// 00b14df8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14de0(int);
void func_00b14de0()
{
    G4_func_00b14de0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
