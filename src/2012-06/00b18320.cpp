// roc 2012-06 00b18320  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18320
//
// 00b18320  a1b856e300           mov eax, dword ptr [0xe356b8]
// 00b18325  50                   push eax
// 00b18326  e8e99de6ff           call 0x982114
// 00b1832b  83c404               add esp, 4
// 00b1832e  c7059056e3002c3cb400 mov dword ptr [0xe35690], 0xb43c2c
// 00b18338  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b18320(int);
void func_00b18320()
{
    G4_func_00b18320(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
