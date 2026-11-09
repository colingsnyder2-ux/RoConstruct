// roc 2012-06 00b155a0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b155a0
//
// 00b155a0  b94890e200           mov ecx, 0xe29048
// 00b155a5  e94657b6ff           jmp 0x67acf0
// auto-matched from its assembly shape

struct T_func_00b155a0 { void m(); };
extern T_func_00b155a0 G1_func_00b155a0;
void func_00b155a0()
{
    G1_func_00b155a0.m();
}
