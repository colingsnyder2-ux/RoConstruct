// roc 2012-06 00b21750  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b21750
//
// 00b21750  b9ec9be500           mov ecx, 0xe59bec
// 00b21755  e99681f7ff           jmp 0xa998f0
// auto-matched from its assembly shape

struct T_func_00b21750 { void m(); };
extern T_func_00b21750 G1_func_00b21750;
void func_00b21750()
{
    G1_func_00b21750.m();
}
