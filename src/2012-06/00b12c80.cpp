// roc 2012-06 00b12c80  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12c80
//
// 00b12c80  b9e8dce100           mov ecx, 0xe1dce8
// 00b12c85  e9b6209fff           jmp 0x504d40
// auto-matched from its assembly shape

struct T_func_00b12c80 { void m(); };
extern T_func_00b12c80 G1_func_00b12c80;
void func_00b12c80()
{
    G1_func_00b12c80.m();
}
