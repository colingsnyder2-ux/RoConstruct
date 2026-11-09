// roc 2012-06 00b1d8b0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d8b0
//
// 00b1d8b0  a178eee400           mov eax, dword ptr [0xe4ee78]
// 00b1d8b5  50                   push eax
// 00b1d8b6  e85948e6ff           call 0x982114
// 00b1d8bb  83c404               add esp, 4
// 00b1d8be  c70550eee4002c3cb400 mov dword ptr [0xe4ee50], 0xb43c2c
// 00b1d8c8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d8b0(int);
void func_00b1d8b0()
{
    G4_func_00b1d8b0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
