// roc 2012-06 00b14e40  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b14e40
//
// 00b14e40  a118a1e200           mov eax, dword ptr [0xe2a118]
// 00b14e45  50                   push eax
// 00b14e46  e8c9d2e6ff           call 0x982114
// 00b14e4b  83c404               add esp, 4
// 00b14e4e  c705f0a0e2002c3cb400 mov dword ptr [0xe2a0f0], 0xb43c2c
// 00b14e58  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b14e40(int);
void func_00b14e40()
{
    G4_func_00b14e40(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
