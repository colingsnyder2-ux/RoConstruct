// roc 2012-06 00b18a10  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b18a10
//
// 00b18a10  b9d86ce300           mov ecx, 0xe36cd8
// 00b18a15  e95616b9ff           jmp 0x6aa070
// auto-matched from its assembly shape

struct T_func_00b18a10 { void m(); };
extern T_func_00b18a10 G1_func_00b18a10;
void func_00b18a10()
{
    G1_func_00b18a10.m();
}
