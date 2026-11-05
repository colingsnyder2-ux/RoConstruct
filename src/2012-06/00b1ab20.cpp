// roc 2012-06 00b1ab20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ab20
//
// 00b1ab20  b9f083e300           mov ecx, 0xe383f0
// 00b1ab25  e94602c5ff           jmp 0x76ad70
// auto-matched from its assembly shape

struct T_func_00b1ab20 { void m(); };
extern T_func_00b1ab20 G1_func_00b1ab20;
void func_00b1ab20()
{
    G1_func_00b1ab20.m();
}
