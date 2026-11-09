// roc 2012-06 00b17930  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17930
//
// 00b17930  a1842de300           mov eax, dword ptr [0xe32d84]
// 00b17935  50                   push eax
// 00b17936  e8d9a7e6ff           call 0x982114
// 00b1793b  83c404               add esp, 4
// 00b1793e  c7055c2de3002c3cb400 mov dword ptr [0xe32d5c], 0xb43c2c
// 00b17948  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17930(int);
void func_00b17930()
{
    G4_func_00b17930(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
