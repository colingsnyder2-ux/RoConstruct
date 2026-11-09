// roc 2012-06 00ae9aa0  unit: seg_00ae0000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00ae9aa0
//
// 00ae9aa0  687018b100           push 0xb11870
// 00ae9aa5  e84b97e9ff           call 0x9831f5
// 00ae9aaa  59                   pop ecx
// 00ae9aab  c3                   ret 
// auto-matched from its assembly shape

extern char G;

extern char G2_func_00ae9aa0;
extern void G1_func_00ae9aa0(void*);
void func_00ae9aa0()
{
    G1_func_00ae9aa0(&G2_func_00ae9aa0);
}
