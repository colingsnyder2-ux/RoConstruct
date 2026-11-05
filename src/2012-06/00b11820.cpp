// roc 2012-06 00b11820  unit: seg_00b10000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11820
//
// 00b11820  b91481e100           mov ecx, 0xe18114
// 00b11825  e946e490ff           jmp 0x41fc70
// auto-matched from its assembly shape

struct T_func_00b11820 { void m(); };
extern T_func_00b11820 G1_func_00b11820;
void func_00b11820()
{
    G1_func_00b11820.m();
}
