// roc 2012-06 00b1af70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1af70
//
// 00b1af70  b91015e400           mov ecx, 0xe41510
// 00b1af75  e9f6498fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1af70 { void m(); };
extern T_func_00b1af70 G1_func_00b1af70;
void func_00b1af70()
{
    G1_func_00b1af70.m();
}
