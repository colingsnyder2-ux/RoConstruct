// roc 2012-06 00b1deb0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1deb0
//
// 00b1deb0  a110fce400           mov eax, dword ptr [0xe4fc10]
// 00b1deb5  50                   push eax
// 00b1deb6  e85942e6ff           call 0x982114
// 00b1debb  83c404               add esp, 4
// 00b1debe  c705e8fbe4002c3cb400 mov dword ptr [0xe4fbe8], 0xb43c2c
// 00b1dec8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1deb0(int);
void func_00b1deb0()
{
    G4_func_00b1deb0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
