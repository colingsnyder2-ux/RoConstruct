// roc 2012-06 0063e2f0  unit: seg_00630000  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0063e2f0
//
// 0063e2f0  b85441b800           mov eax, 0xb84154
// 0063e2f5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0063e2f0()
{
    return &G;
}
