// roc 2012-06 00b20c20  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b20c20
//
// 00b20c20  b9705fe500           mov ecx, 0xe55f70
// 00b20c25  e976c9dcff           jmp 0x8ed5a0
// auto-matched from its assembly shape

struct T_func_00b20c20 { void m(); };
extern T_func_00b20c20 G1_func_00b20c20;
void func_00b20c20()
{
    G1_func_00b20c20.m();
}
