// roc 2012-06 00b1b350  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1b350
//
// 00b1b350  b9e09ee300           mov ecx, 0xe39ee0
// 00b1b355  e916468fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1b350 { void m(); };
extern T_func_00b1b350 G1_func_00b1b350;
void func_00b1b350()
{
    G1_func_00b1b350.m();
}
