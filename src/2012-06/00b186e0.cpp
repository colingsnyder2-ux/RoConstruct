// roc 2012-06 00b186e0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b186e0
//
// 00b186e0  a1bc62e300           mov eax, dword ptr [0xe362bc]
// 00b186e5  50                   push eax
// 00b186e6  e8299ae6ff           call 0x982114
// 00b186eb  83c404               add esp, 4
// 00b186ee  c7059462e3002c3cb400 mov dword ptr [0xe36294], 0xb43c2c
// 00b186f8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b186e0(int);
void func_00b186e0()
{
    G4_func_00b186e0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
