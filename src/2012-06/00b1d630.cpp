// roc 2012-06 00b1d630  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d630
//
// 00b1d630  a120eae400           mov eax, dword ptr [0xe4ea20]
// 00b1d635  50                   push eax
// 00b1d636  e8d94ae6ff           call 0x982114
// 00b1d63b  83c404               add esp, 4
// 00b1d63e  c705f8e9e4002c3cb400 mov dword ptr [0xe4e9f8], 0xb43c2c
// 00b1d648  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d630(int);
void func_00b1d630()
{
    G4_func_00b1d630(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
