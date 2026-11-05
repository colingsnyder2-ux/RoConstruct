// roc 2012-06 00b11d00  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11d00
//
// 00b11d00  a1688de100           mov eax, dword ptr [0xe18d68]
// 00b11d05  50                   push eax
// 00b11d06  e80904e7ff           call 0x982114
// 00b11d0b  83c404               add esp, 4
// 00b11d0e  c705408de1002c3cb400 mov dword ptr [0xe18d40], 0xb43c2c
// 00b11d18  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b11d00(int);
void func_00b11d00()
{
    G4_func_00b11d00(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
