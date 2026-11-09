// roc 2012-06 00b17ea0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17ea0
//
// 00b17ea0  a13847e300           mov eax, dword ptr [0xe34738]
// 00b17ea5  50                   push eax
// 00b17ea6  e869a2e6ff           call 0x982114
// 00b17eab  83c404               add esp, 4
// 00b17eae  c7050c47e3002c3cb400 mov dword ptr [0xe3470c], 0xb43c2c
// 00b17eb8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17ea0(int);
void func_00b17ea0()
{
    G4_func_00b17ea0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
