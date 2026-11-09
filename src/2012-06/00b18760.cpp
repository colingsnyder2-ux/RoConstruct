// roc 2012-06 00b18760  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18760
//
// 00b18760  a12462e300           mov eax, dword ptr [0xe36224]
// 00b18765  50                   push eax
// 00b18766  e8a999e6ff           call 0x982114
// 00b1876b  83c404               add esp, 4
// 00b1876e  c705fc61e3002c3cb400 mov dword ptr [0xe361fc], 0xb43c2c
// 00b18778  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18760(int);
void func_00b18760()
{
    G4_func_00b18760(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
