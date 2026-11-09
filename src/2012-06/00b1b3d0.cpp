// roc 2012-06 00b1b3d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b3d0
//
// 00b1b3d0  b9e48ae400           mov ecx, 0xe48ae4
// 00b1b3d5  e9c61fc6ff           jmp 0x77d3a0
// auto-matched from its assembly shape

struct T_func_00b1b3d0 { void m(); };
extern T_func_00b1b3d0 G1_func_00b1b3d0;
void func_00b1b3d0()
{
    G1_func_00b1b3d0.m();
}
