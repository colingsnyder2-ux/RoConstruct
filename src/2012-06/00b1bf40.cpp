// roc 2012-06 00b1bf40  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1bf40
//
// 00b1bf40  b9a8a2e400           mov ecx, 0xe4a2a8
// 00b1bf45  e9263a8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1bf40 { void m(); };
extern T_func_00b1bf40 G1_func_00b1bf40;
void func_00b1bf40()
{
    G1_func_00b1bf40.m();
}
