// roc 2012-06 00b1b800  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b800
//
// 00b1b800  b9c891e400           mov ecx, 0xe491c8
// 00b1b805  e9e666a7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b1b800 { void m(); };
extern T_func_00b1b800 G1_func_00b1b800;
void func_00b1b800()
{
    G1_func_00b1b800.m();
}
