// roc 2012-06 00b15ea0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15ea0
//
// 00b15ea0  a14cc4e200           mov eax, dword ptr [0xe2c44c]
// 00b15ea5  50                   push eax
// 00b15ea6  e869c2e6ff           call 0x982114
// 00b15eab  83c404               add esp, 4
// 00b15eae  c70524c4e2002c3cb400 mov dword ptr [0xe2c424], 0xb43c2c
// 00b15eb8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15ea0(int);
void func_00b15ea0()
{
    G4_func_00b15ea0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
