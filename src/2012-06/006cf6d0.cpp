// roc 2012-06 006cf6d0  unit: boost::io::too_many_args  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006cf6d0
//
// 006cf6d0  b8e888b900           mov eax, 0xb988e8
// 006cf6d5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_006cf6d0()
{
    return &G;
}
