// roc 2012-06 00b1ec90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ec90
//
// 00b1ec90  b93015e500           mov ecx, 0xe51530
// 00b1ec95  e9a60dd6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1ec90 { void m(); };
extern T_func_00b1ec90 G1_func_00b1ec90;
void func_00b1ec90()
{
    G1_func_00b1ec90.m();
}
