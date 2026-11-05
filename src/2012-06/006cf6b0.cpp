// roc 2012-06 006cf6b0  unit: boost::io::bad_format_string  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006cf6b0
//
// 006cf6b0  b84488b900           mov eax, 0xb98844
// 006cf6b5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_006cf6b0()
{
    return &G;
}
