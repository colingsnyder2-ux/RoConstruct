// roc 2012-06 00b17690  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b17690
//
// 00b17690  b9dc1fe300           mov ecx, 0xe31fdc
// 00b17695  e9a620c0ff           jmp 0x719740
// auto-matched from its assembly shape

struct T_func_00b17690 { void m(); };
extern T_func_00b17690 G1_func_00b17690;
void func_00b17690()
{
    G1_func_00b17690.m();
}
