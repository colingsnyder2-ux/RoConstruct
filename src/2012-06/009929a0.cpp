// roc 2012-06 009929a0  unit: CXTPCommandBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009929a0
//
// 009929a0  b8282be000           mov eax, 0xe02b28
// 009929a5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009929a0()
{
    return &G;
}
