// roc 2012-06 00b17aa0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17aa0
//
// 00b17aa0  a1b033e300           mov eax, dword ptr [0xe333b0]
// 00b17aa5  50                   push eax
// 00b17aa6  e869a6e6ff           call 0x982114
// 00b17aab  83c404               add esp, 4
// 00b17aae  c7058833e3002c3cb400 mov dword ptr [0xe33388], 0xb43c2c
// 00b17ab8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17aa0(int);
void func_00b17aa0()
{
    G4_func_00b17aa0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
