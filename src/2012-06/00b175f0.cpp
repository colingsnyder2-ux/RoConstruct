// roc 2012-06 00b175f0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b175f0
//
// 00b175f0  b9981ce300           mov ecx, 0xe31c98
// 00b175f5  e94684d6ff           jmp 0x87fa40
// auto-matched from its assembly shape

struct T_func_00b175f0 { void m(); };
extern T_func_00b175f0 G1_func_00b175f0;
void func_00b175f0()
{
    G1_func_00b175f0.m();
}
