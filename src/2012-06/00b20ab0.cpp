// roc 2012-06 00b20ab0  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20ab0
//
// 00b20ab0  a1705de500           mov eax, dword ptr [0xe55d70]
// 00b20ab5  50                   push eax
// 00b20ab6  e85916e6ff           call 0x982114
// 00b20abb  83c404               add esp, 4
// 00b20abe  c705445de5002c3cb400 mov dword ptr [0xe55d44], 0xb43c2c
// 00b20ac8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20ab0(int);
void func_00b20ab0()
{
    G4_func_00b20ab0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
