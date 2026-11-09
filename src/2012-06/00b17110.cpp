// roc 2012-06 00b17110  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17110
//
// 00b17110  b95402e300           mov ecx, 0xe30254
// 00b17115  e9d6fbbdff           jmp 0x6f6cf0
// auto-matched from its assembly shape

struct T_func_00b17110 { void m(); };
extern T_func_00b17110 G1_func_00b17110;
void func_00b17110()
{
    G1_func_00b17110.m();
}
