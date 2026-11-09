// roc 2012-06 00b18700  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18700
//
// 00b18700  a1705fe300           mov eax, dword ptr [0xe35f70]
// 00b18705  50                   push eax
// 00b18706  e8099ae6ff           call 0x982114
// 00b1870b  83c404               add esp, 4
// 00b1870e  c705485fe3002c3cb400 mov dword ptr [0xe35f48], 0xb43c2c
// 00b18718  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18700(int);
void func_00b18700()
{
    G4_func_00b18700(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
