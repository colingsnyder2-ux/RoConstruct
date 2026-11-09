// roc 2012-06 00b115f0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b115f0
//
// 00b115f0  a1f07de100           mov eax, dword ptr [0xe17df0]
// 00b115f5  50                   push eax
// 00b115f6  e8190be7ff           call 0x982114
// 00b115fb  83c404               add esp, 4
// 00b115fe  c705c87de1002c3cb400 mov dword ptr [0xe17dc8], 0xb43c2c
// 00b11608  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b115f0(int);
void func_00b115f0()
{
    G4_func_00b115f0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
