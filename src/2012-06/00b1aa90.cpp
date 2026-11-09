// roc 2012-06 00b1aa90  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1aa90
//
// 00b1aa90  b9208ae300           mov ecx, 0xe38a20
// 00b1aa95  e94618c5ff           jmp 0x76c2e0
// auto-matched from its assembly shape

struct T_func_00b1aa90 { void m(); };
extern T_func_00b1aa90 G1_func_00b1aa90;
void func_00b1aa90()
{
    G1_func_00b1aa90.m();
}
