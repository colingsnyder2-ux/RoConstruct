// roc 2012-06 00b18720  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18720
//
// 00b18720  a1185ee300           mov eax, dword ptr [0xe35e18]
// 00b18725  50                   push eax
// 00b18726  e8e999e6ff           call 0x982114
// 00b1872b  83c404               add esp, 4
// 00b1872e  c705f05de3002c3cb400 mov dword ptr [0xe35df0], 0xb43c2c
// 00b18738  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18720(int);
void func_00b18720()
{
    G4_func_00b18720(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
