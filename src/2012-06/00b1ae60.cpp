// roc 2012-06 00b1ae60  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b1ae60
//
// 00b1ae60  b97835e400           mov ecx, 0xe43578
// 00b1ae65  e9064b8fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b1ae60 { void m(); };
extern T_func_00b1ae60 G1_func_00b1ae60;
void func_00b1ae60()
{
    G1_func_00b1ae60.m();
}
