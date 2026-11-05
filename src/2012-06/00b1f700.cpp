// roc 2012-06 00b1f700  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1f700
//
// 00b1f700  a14c2de500           mov eax, dword ptr [0xe52d4c]
// 00b1f705  50                   push eax
// 00b1f706  e8092ae6ff           call 0x982114
// 00b1f70b  83c404               add esp, 4
// 00b1f70e  c705242de5002c3cb400 mov dword ptr [0xe52d24], 0xb43c2c
// 00b1f718  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1f700(int);
void func_00b1f700()
{
    G4_func_00b1f700(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
