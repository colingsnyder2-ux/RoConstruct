// roc 2012-06 00b11860  unit: seg_00b10000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b11860
//
// 00b11860  b9e481e100           mov ecx, 0xe181e4
// 00b11865  ff253c26b200         jmp dword ptr [0xb2263c]
// auto-matched from its assembly shape

struct __declspec(dllimport) T_func_00b11860 { void m(); };
extern T_func_00b11860 G1_func_00b11860;
void func_00b11860()
{
    G1_func_00b11860.m();
}
