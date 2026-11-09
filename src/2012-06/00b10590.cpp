// roc 2012-06 00b10590  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10590
//
// 00b10590  682016b200           push 0xb21620
// 00b10595  e85b2ce7ff           call 0x9831f5
// 00b1059a  59                   pop ecx
// 00b1059b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00b10590;
extern void G1_func_00b10590(void*);
void func_00b10590()
{
    G1_func_00b10590(&G2_func_00b10590);
}
