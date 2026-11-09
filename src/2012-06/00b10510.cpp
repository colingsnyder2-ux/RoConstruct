// roc 2012-06 00b10510  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10510
//
// 00b10510  e80beee8ff           call 0x99f320
// 00b10515  50                   push eax
// 00b10516  e88325e7ff           call 0x982a9e
// 00b1051b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10510();
extern int __stdcall G2_func_00b10510(int);
int func_00b10510()
{
    return G2_func_00b10510(G1_func_00b10510());
}
