// roc 2012-06 00b20dd0  unit: seg_00b20000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20dd0
//
// 00b20dd0  a1c463e500           mov eax, dword ptr [0xe563c4]
// 00b20dd5  50                   push eax
// 00b20dd6  e83913e6ff           call 0x982114
// 00b20ddb  83c404               add esp, 4
// 00b20dde  c7059c63e5002c3cb400 mov dword ptr [0xe5639c], 0xb43c2c
// 00b20de8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b20dd0(int);
void func_00b20dd0()
{
    G4_func_00b20dd0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
