// roc 2012-06 00b2185a  unit: seg_00b20000  size: 10 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b2185a
//
// 00b2185a  b980a4e500           mov ecx, 0xe5a480
// 00b2185f  e94ba1f5ff           jmp 0xa7b9af
// auto-matched from its assembly shape

struct T_func_00b2185a { void m(); };
extern T_func_00b2185a G1_func_00b2185a;
void func_00b2185a()
{
    G1_func_00b2185a.m();
}
