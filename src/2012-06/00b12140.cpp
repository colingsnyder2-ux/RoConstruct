// roc 2012-06 00b12140  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12140
//
// 00b12140  a1409ce100           mov eax, dword ptr [0xe19c40]
// 00b12145  50                   push eax
// 00b12146  e8c9ffe6ff           call 0x982114
// 00b1214b  83c404               add esp, 4
// 00b1214e  c705189ce1002c3cb400 mov dword ptr [0xe19c18], 0xb43c2c
// 00b12158  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b12140(int);
void func_00b12140()
{
    G4_func_00b12140(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
