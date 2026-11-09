// roc 2012-06 00aeeef0  unit: seg_00ae0000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aeeef0
//
// 00aeeef0  b91137e200           mov ecx, 0xe23711
// 00aeeef5  e9066ef0ff           jmp 0x9f5d00
// auto-matched from its assembly shape

struct T_func_00aeeef0 { void m(); };
extern T_func_00aeeef0 G1_func_00aeeef0;
void func_00aeeef0()
{
    G1_func_00aeeef0.m();
}
