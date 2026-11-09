// roc 2012-06 00b12ed0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12ed0
//
// 00b12ed0  a1ac0be200           mov eax, dword ptr [0xe20bac]
// 00b12ed5  50                   push eax
// 00b12ed6  e839f2e6ff           call 0x982114
// 00b12edb  83c404               add esp, 4
// 00b12ede  c705840be2002c3cb400 mov dword ptr [0xe20b84], 0xb43c2c
// 00b12ee8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12ed0(int);
void func_00b12ed0()
{
    G4_func_00b12ed0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
