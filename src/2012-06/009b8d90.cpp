// roc 2012-06 009b8d90  unit: CInstanceRecord  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b8d90
//
// 009b8d90  b80c3ae000           mov eax, 0xe03a0c
// 009b8d95  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009b8d90()
{
    return &G;
}
