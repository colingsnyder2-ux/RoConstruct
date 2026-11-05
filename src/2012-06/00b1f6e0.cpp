// roc 2012-06 00b1f6e0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f6e0
//
// 00b1f6e0  a1102ce500           mov eax, dword ptr [0xe52c10]
// 00b1f6e5  50                   push eax
// 00b1f6e6  e8292ae6ff           call 0x982114
// 00b1f6eb  83c404               add esp, 4
// 00b1f6ee  c705e82be5002c3cb400 mov dword ptr [0xe52be8], 0xb43c2c
// 00b1f6f8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f6e0(int);
void func_00b1f6e0()
{
    G4_func_00b1f6e0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
