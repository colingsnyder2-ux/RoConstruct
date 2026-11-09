// roc 2012-06 00b10600  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10600
//
// 00b10600  e85b8eeaff           call 0x9b9460
// 00b10605  50                   push eax
// 00b10606  e89324e7ff           call 0x982a9e
// 00b1060b  c3                   ret 
// auto-matched from its assembly shape

extern int G1_func_00b10600();
extern int __stdcall G2_func_00b10600(int);
int func_00b10600()
{
    return G2_func_00b10600(G1_func_00b10600());
}
