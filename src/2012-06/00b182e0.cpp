// roc 2012-06 00b182e0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b182e0
//
// 00b182e0  a1a057e300           mov eax, dword ptr [0xe357a0]
// 00b182e5  50                   push eax
// 00b182e6  e8299ee6ff           call 0x982114
// 00b182eb  83c404               add esp, 4
// 00b182ee  c7057857e3002c3cb400 mov dword ptr [0xe35778], 0xb43c2c
// 00b182f8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b182e0(int);
void func_00b182e0()
{
    G4_func_00b182e0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
