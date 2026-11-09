// roc 2011-06 00654e54  unit: boost::Vthread::?$sp_counted_impl_p  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00654e54
//
// 00654e54  b85a4e6500           mov eax, 0x654e5a
// 00654e59  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00654e54()
{
    return &G;
}
