// roc 2012-06 00b20480  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20480
//
// 00b20480  b9b451e500           mov ecx, 0xe551b4
// 00b20485  e9661aa7ff           jmp 0x591ef0
// auto-matched from its assembly shape

struct T_func_00b20480 { void m(); };
extern T_func_00b20480 G1_func_00b20480;
void func_00b20480()
{
    G1_func_00b20480.m();
}
