// roc 2012-06 00b16c50  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b16c50
//
// 00b16c50  a11cf0e200           mov eax, dword ptr [0xe2f01c]
// 00b16c55  50                   push eax
// 00b16c56  e8b9b4e6ff           call 0x982114
// 00b16c5b  83c404               add esp, 4
// 00b16c5e  c705f4efe2002c3cb400 mov dword ptr [0xe2eff4], 0xb43c2c
// 00b16c68  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b16c50(int);
void func_00b16c50()
{
    G4_func_00b16c50(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
