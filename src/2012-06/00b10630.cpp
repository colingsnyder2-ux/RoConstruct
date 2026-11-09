// roc 2012-06 00b10630  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10630
//
// 00b10630  e80b91eaff           call 0x9b9740
// 00b10635  50                   push eax
// 00b10636  e86324e7ff           call 0x982a9e
// 00b1063b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10630();
extern int __stdcall G2_func_00b10630(int);
int func_00b10630()
{
    return G2_func_00b10630(G1_func_00b10630());
}
