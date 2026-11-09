// roc 2012-06 00b17120  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17120
//
// 00b17120  b95802e300           mov ecx, 0xe30258
// 00b17125  e9f6f6bdff           jmp 0x6f6820
// auto-matched from its assembly shape

struct T_func_00b17120 { void m(); };
extern T_func_00b17120 G1_func_00b17120;
void func_00b17120()
{
    G1_func_00b17120.m();
}
