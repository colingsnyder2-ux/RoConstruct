// roc 2012-06 00b15ab0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15ab0
//
// 00b15ab0  a148b2e200           mov eax, dword ptr [0xe2b248]
// 00b15ab5  50                   push eax
// 00b15ab6  e859c6e6ff           call 0x982114
// 00b15abb  83c404               add esp, 4
// 00b15abe  c70520b2e2002c3cb400 mov dword ptr [0xe2b220], 0xb43c2c
// 00b15ac8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15ab0(int);
void func_00b15ab0()
{
    G4_func_00b15ab0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
