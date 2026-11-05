// roc 2012-06 00b11ad0  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11ad0
//
// 00b11ad0  b95089e100           mov ecx, 0xe18950
// 00b11ad5  e9e6e892ff           jmp 0x4403c0
// auto-matched from its assembly shape

struct T_func_00b11ad0 { void m(); };
extern T_func_00b11ad0 G1_func_00b11ad0;
void func_00b11ad0()
{
    G1_func_00b11ad0.m();
}
