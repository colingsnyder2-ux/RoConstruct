// roc 2012-06 00b147f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b147f0
//
// 00b147f0  b9944ee200           mov ecx, 0xe24e94
// 00b147f5  e986a4a6ff           jmp 0x57ec80
// auto-matched from its assembly shape

struct T_func_00b147f0 { void m(); };
extern T_func_00b147f0 G1_func_00b147f0;
void func_00b147f0()
{
    G1_func_00b147f0.m();
}
