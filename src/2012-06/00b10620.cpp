// roc 2012-06 00b10620  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10620
//
// 00b10620  e87b90eaff           call 0x9b96a0
// 00b10625  50                   push eax
// 00b10626  e87324e7ff           call 0x982a9e
// 00b1062b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10620();
extern int __stdcall G2_func_00b10620(int);
int func_00b10620()
{
    return G2_func_00b10620(G1_func_00b10620());
}
