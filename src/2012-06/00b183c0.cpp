// roc 2012-06 00b183c0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b183c0
//
// 00b183c0  a15059e300           mov eax, dword ptr [0xe35950]
// 00b183c5  50                   push eax
// 00b183c6  e8499de6ff           call 0x982114
// 00b183cb  83c404               add esp, 4
// 00b183ce  c7052859e3002c3cb400 mov dword ptr [0xe35928], 0xb43c2c
// 00b183d8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b183c0(int);
void func_00b183c0()
{
    G4_func_00b183c0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
