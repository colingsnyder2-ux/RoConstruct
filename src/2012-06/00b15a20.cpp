// roc 2012-06 00b15a20  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b15a20
//
// 00b15a20  a1d8b1e200           mov eax, dword ptr [0xe2b1d8]
// 00b15a25  50                   push eax
// 00b15a26  e8e9c6e6ff           call 0x982114
// 00b15a2b  83c404               add esp, 4
// 00b15a2e  c705acb1e2002c3cb400 mov dword ptr [0xe2b1ac], 0xb43c2c
// 00b15a38  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b15a20(int);
void func_00b15a20()
{
    G4_func_00b15a20(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
