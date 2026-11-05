// roc 2012-06 00b17f20  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17f20
//
// 00b17f20  a16c47e300           mov eax, dword ptr [0xe3476c]
// 00b17f25  50                   push eax
// 00b17f26  e8e9a1e6ff           call 0x982114
// 00b17f2b  83c404               add esp, 4
// 00b17f2e  c7054047e3002c3cb400 mov dword ptr [0xe34740], 0xb43c2c
// 00b17f38  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17f20(int);
void func_00b17f20()
{
    G4_func_00b17f20(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
