// roc 2012-06 00b17a60  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17a60
//
// 00b17a60  a18433e300           mov eax, dword ptr [0xe33384]
// 00b17a65  50                   push eax
// 00b17a66  e8a9a6e6ff           call 0x982114
// 00b17a6b  83c404               add esp, 4
// 00b17a6e  c7055c33e3002c3cb400 mov dword ptr [0xe3335c], 0xb43c2c
// 00b17a78  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17a60(int);
void func_00b17a60()
{
    G4_func_00b17a60(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
