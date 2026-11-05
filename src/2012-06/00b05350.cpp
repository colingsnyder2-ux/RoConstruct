// roc 2012-06 00b05350  unit: seg_00b00000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00b05350
//
// 00b05350  68d0d0b100           push 0xb1d0d0
// 00b05355  e89bdee7ff           call 0x9831f5
// 00b0535a  59                   pop ecx
// 00b0535b  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00b05350;
extern void G1_func_00b05350(void*);
void func_00b05350()
{
    G1_func_00b05350(&G2_func_00b05350);
}
