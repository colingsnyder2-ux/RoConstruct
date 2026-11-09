// roc 2012-06 00b1def0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1def0
//
// 00b1def0  a164fee400           mov eax, dword ptr [0xe4fe64]
// 00b1def5  50                   push eax
// 00b1def6  e81942e6ff           call 0x982114
// 00b1defb  83c404               add esp, 4
// 00b1defe  c70538fee4002c3cb400 mov dword ptr [0xe4fe38], 0xb43c2c
// 00b1df08  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1def0(int);
void func_00b1def0()
{
    G4_func_00b1def0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
