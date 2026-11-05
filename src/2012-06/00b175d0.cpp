// roc 2012-06 00b175d0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b175d0
//
// 00b175d0  b9481ce300           mov ecx, 0xe31c48
// 00b175d5  e96684d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b175d0 { void m(); };
extern T_func_00b175d0 G1_func_00b175d0;
void func_00b175d0()
{
    G1_func_00b175d0.m();
}
