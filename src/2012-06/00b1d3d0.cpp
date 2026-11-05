// roc 2012-06 00b1d3d0  unit: seg_00b10000  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d3d0
//
// 00b1d3d0  a1b0e7e400           mov eax, dword ptr [0xe4e7b0]
// 00b1d3d5  50                   push eax
// 00b1d3d6  e8394de6ff           call 0x982114
// 00b1d3db  83c404               add esp, 4
// 00b1d3de  c70588e7e4002c3cb400 mov dword ptr [0xe4e788], 0xb43c2c
// 00b1d3e8  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern int G1_VALUE;
extern int G2_VALUE;
extern char G3_OBJ;
extern int __cdecl G4_func_00b1d3d0(int);
void func_00b1d3d0()
{
    G4_func_00b1d3d0(G1_VALUE);
    G2_VALUE = (int)&G3_OBJ;
}
