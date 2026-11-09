// roc 2010-06 006a6fbb  unit: boost::iostreams::Uinput::?$filtering_stream  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006a6fbb
//
// 006a6fbb  b8c16f6a00           mov eax, 0x6a6fc1
// 006a6fc0  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_006a6fbb()
{
    return &G;
}
