// roc 2012-06 00b11d20  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11d20
//
// 00b11d20  a13c8de100           mov eax, dword ptr [0xe18d3c]
// 00b11d25  50                   push eax
// 00b11d26  e8e903e7ff           call 0x982114
// 00b11d2b  83c404               add esp, 4
// 00b11d2e  c705148de1002c3cb400 mov dword ptr [0xe18d14], 0xb43c2c
// 00b11d38  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b11d20(int);
void func_00b11d20()
{
    G4_func_00b11d20(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
