// roc 2012-06 00b18080  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18080
//
// 00b18080  a1dc46e300           mov eax, dword ptr [0xe346dc]
// 00b18085  50                   push eax
// 00b18086  e889a0e6ff           call 0x982114
// 00b1808b  83c404               add esp, 4
// 00b1808e  c705b446e3002c3cb400 mov dword ptr [0xe346b4], 0xb43c2c
// 00b18098  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18080(int);
void func_00b18080()
{
    G4_func_00b18080(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
