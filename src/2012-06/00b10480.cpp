// roc 2012-06 00b10480  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10480
//
// 00b10480  688015b200           push 0xb21580
// 00b10485  e86b2de7ff           call 0x9831f5
// 00b1048a  59                   pop ecx
// 00b1048b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00b10480;
extern void G1_func_00b10480(void*);
void func_00b10480()
{
    G1_func_00b10480(&G2_func_00b10480);
}
