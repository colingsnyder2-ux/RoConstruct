// roc 2012-06 00b12180  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12180
//
// 00b12180  a1bc98e100           mov eax, dword ptr [0xe198bc]
// 00b12185  50                   push eax
// 00b12186  e889ffe6ff           call 0x982114
// 00b1218b  83c404               add esp, 4
// 00b1218e  c7059498e1002c3cb400 mov dword ptr [0xe19894], 0xb43c2c
// 00b12198  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12180(int);
void func_00b12180()
{
    G4_func_00b12180(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
