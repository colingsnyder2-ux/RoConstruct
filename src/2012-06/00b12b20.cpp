// roc 2012-06 00b12b20  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12b20
//
// 00b12b20  b918d0e100           mov ecx, 0xe1d018
// 00b12b25  e946ce8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b12b20 { void m(); };
extern T_func_00b12b20 G1_func_00b12b20;
void func_00b12b20()
{
    G1_func_00b12b20.m();
}
