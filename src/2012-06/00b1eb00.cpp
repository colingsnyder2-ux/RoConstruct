// roc 2012-06 00b1eb00  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1eb00
//
// 00b1eb00  a1000ce500           mov eax, dword ptr [0xe50c00]
// 00b1eb05  50                   push eax
// 00b1eb06  e80936e6ff           call 0x982114
// 00b1eb0b  83c404               add esp, 4
// 00b1eb0e  c705d80be5002c3cb400 mov dword ptr [0xe50bd8], 0xb43c2c
// 00b1eb18  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1eb00(int);
void func_00b1eb00()
{
    G4_func_00b1eb00(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
