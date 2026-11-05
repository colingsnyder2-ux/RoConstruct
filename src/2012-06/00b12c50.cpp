// roc 2012-06 00b12c50  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12c50
//
// 00b12c50  b9f0dce100           mov ecx, 0xe1dcf0
// 00b12c55  e9562f9fff           jmp 0x505bb0
// auto-matched from its assembly shape

struct T_func_00b12c50 { void m(); };
extern T_func_00b12c50 G1_func_00b12c50;
void func_00b12c50()
{
    G1_func_00b12c50.m();
}
