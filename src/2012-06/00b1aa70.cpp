// roc 2012-06 00b1aa70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aa70
//
// 00b1aa70  b9808be300           mov ecx, 0xe38b80
// 00b1aa75  e9a61dc5ff           jmp 0x76c820
// auto-matched from its assembly shape

struct T_func_00b1aa70 { void m(); };
extern T_func_00b1aa70 G1_func_00b1aa70;
void func_00b1aa70()
{
    G1_func_00b1aa70.m();
}
