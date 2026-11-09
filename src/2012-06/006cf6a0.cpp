// roc 2012-06 006cf6a0  unit: boost::io::format_error  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006cf6a0
//
// 006cf6a0  b80c88b900           mov eax, 0xb9880c
// 006cf6a5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_006cf6a0()
{
    return &G;
}
