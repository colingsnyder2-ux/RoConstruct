// roc 2012-06 00b13370  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b13370
//
// 00b13370  b9a0efe100           mov ecx, 0xe1efa0
// 00b13375  e9f6c58fff           jmp 0x40f970
// auto-matched from its assembly shape

struct T_func_00b13370 { void m(); };
extern T_func_00b13370 G1_func_00b13370;
void func_00b13370()
{
    G1_func_00b13370.m();
}
