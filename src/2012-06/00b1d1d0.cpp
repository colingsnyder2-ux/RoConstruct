// roc 2012-06 00b1d1d0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d1d0
//
// 00b1d1d0  a190e3e400           mov eax, dword ptr [0xe4e390]
// 00b1d1d5  50                   push eax
// 00b1d1d6  e8394fe6ff           call 0x982114
// 00b1d1db  83c404               add esp, 4
// 00b1d1de  c70568e3e4002c3cb400 mov dword ptr [0xe4e368], 0xb43c2c
// 00b1d1e8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d1d0(int);
void func_00b1d1d0()
{
    G4_func_00b1d1d0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
