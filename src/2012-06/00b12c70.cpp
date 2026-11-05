// roc 2012-06 00b12c70  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b12c70
//
// 00b12c70  b9d8dce100           mov ecx, 0xe1dcd8
// 00b12c75  e996259fff           jmp 0x505210
// auto-matched from its assembly shape

struct T_func_00b12c70 { void m(); };
extern T_func_00b12c70 G1_func_00b12c70;
void func_00b12c70()
{
    G1_func_00b12c70.m();
}
