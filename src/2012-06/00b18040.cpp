// roc 2012-06 00b18040  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18040
//
// 00b18040  a19c45e300           mov eax, dword ptr [0xe3459c]
// 00b18045  50                   push eax
// 00b18046  e8c9a0e6ff           call 0x982114
// 00b1804b  83c404               add esp, 4
// 00b1804e  c7057445e3002c3cb400 mov dword ptr [0xe34574], 0xb43c2c
// 00b18058  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18040(int);
void func_00b18040()
{
    G4_func_00b18040(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
