// roc 2012-06 00b10460  unit: seg_00b10000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b10460
//
// 00b10460  687015b200           push 0xb21570
// 00b10465  e88b2de7ff           call 0x9831f5
// 00b1046a  59                   pop ecx
// 00b1046b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00b10460;
extern void G1_func_00b10460(void*);
void func_00b10460()
{
    G1_func_00b10460(&G2_func_00b10460);
}
