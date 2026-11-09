// roc 2012-06 00b10580  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10580
//
// 00b10580  68f015b200           push 0xb215f0
// 00b10585  e86b2ce7ff           call 0x9831f5
// 00b1058a  59                   pop ecx
// 00b1058b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00b10580;
extern void G1_func_00b10580(void*);
void func_00b10580()
{
    G1_func_00b10580(&G2_func_00b10580);
}
