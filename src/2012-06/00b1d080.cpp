// roc 2012-06 00b1d080  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1d080
//
// 00b1d080  b9e0dee400           mov ecx, 0xe4dee0
// 00b1d085  e9b629d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b1d080 { void m(); };
extern T_func_00b1d080 G1_func_00b1d080;
void func_00b1d080()
{
    G1_func_00b1d080.m();
}
