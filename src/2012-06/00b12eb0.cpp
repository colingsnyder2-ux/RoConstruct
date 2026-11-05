// roc 2012-06 00b12eb0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12eb0
//
// 00b12eb0  a13811e200           mov eax, dword ptr [0xe21138]
// 00b12eb5  50                   push eax
// 00b12eb6  e859f2e6ff           call 0x982114
// 00b12ebb  83c404               add esp, 4
// 00b12ebe  c7051011e2002c3cb400 mov dword ptr [0xe21110], 0xb43c2c
// 00b12ec8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12eb0(int);
void func_00b12eb0()
{
    G4_func_00b12eb0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
