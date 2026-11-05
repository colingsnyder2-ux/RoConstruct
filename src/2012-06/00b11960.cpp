// roc 2012-06 00b11960  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11960
//
// 00b11960  b91487e100           mov ecx, 0xe18714
// 00b11965  e9e6c391ff           jmp 0x42dd50
// auto-matched from its assembly shape

struct T_func_00b11960 { void m(); };
extern T_func_00b11960 G1_func_00b11960;
void func_00b11960()
{
    G1_func_00b11960.m();
}
