// roc 2012-06 006cf6c0  unit: boost::io::too_few_args  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006cf6c0
//
// 006cf6c0  b88888b900           mov eax, 0xb98888
// 006cf6c5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_006cf6c0()
{
    return &G;
}
