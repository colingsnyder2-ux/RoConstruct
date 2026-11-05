// roc 2012-06 00b1ea00  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ea00
//
// 00b1ea00  a1e40ce500           mov eax, dword ptr [0xe50ce4]
// 00b1ea05  50                   push eax
// 00b1ea06  e80937e6ff           call 0x982114
// 00b1ea0b  83c404               add esp, 4
// 00b1ea0e  c705bc0ce5002c3cb400 mov dword ptr [0xe50cbc], 0xb43c2c
// 00b1ea18  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1ea00(int);
void func_00b1ea00()
{
    G4_func_00b1ea00(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
