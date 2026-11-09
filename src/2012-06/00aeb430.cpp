// roc 2012-06 00aeb430  unit: seg_00ae0000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00aeb430
//
// 00aeb430  684025b100           push 0xb12540
// 00aeb435  e8bb7de9ff           call 0x9831f5
// 00aeb43a  59                   pop ecx
// 00aeb43b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00aeb430;
extern void G1_func_00aeb430(void*);
void func_00aeb430()
{
    G1_func_00aeb430(&G2_func_00aeb430);
}
