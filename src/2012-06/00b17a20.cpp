// roc 2012-06 00b17a20  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17a20
//
// 00b17a20  a1e033e300           mov eax, dword ptr [0xe333e0]
// 00b17a25  50                   push eax
// 00b17a26  e8e9a6e6ff           call 0x982114
// 00b17a2b  83c404               add esp, 4
// 00b17a2e  c705b833e3002c3cb400 mov dword ptr [0xe333b8], 0xb43c2c
// 00b17a38  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b17a20(int);
void func_00b17a20()
{
    G4_func_00b17a20(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
