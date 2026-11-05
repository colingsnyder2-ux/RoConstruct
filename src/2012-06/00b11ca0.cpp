// roc 2012-06 00b11ca0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11ca0
//
// 00b11ca0  a1e48ce100           mov eax, dword ptr [0xe18ce4]
// 00b11ca5  50                   push eax
// 00b11ca6  e86904e7ff           call 0x982114
// 00b11cab  83c404               add esp, 4
// 00b11cae  c705bc8ce1002c3cb400 mov dword ptr [0xe18cbc], 0xb43c2c
// 00b11cb8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b11ca0(int);
void func_00b11ca0()
{
    G4_func_00b11ca0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
