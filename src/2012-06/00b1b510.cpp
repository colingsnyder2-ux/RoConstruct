// roc 2012-06 00b1b510  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b510
//
// 00b1b510  b9108ae400           mov ecx, 0xe48a10
// 00b1b515  e926b2c5ff           jmp 0x776740
// auto-matched from its assembly shape

struct T_func_00b1b510 { void m(); };
extern T_func_00b1b510 G1_func_00b1b510;
void func_00b1b510()
{
    G1_func_00b1b510.m();
}
