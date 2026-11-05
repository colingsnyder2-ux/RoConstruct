// roc 2011-06 006e4645  unit: boost::iostreams::Uinput::?$filtering_stream  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006e4645
//
// 006e4645  b84b466e00           mov eax, 0x6e464b
// 006e464a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_006e4645()
{
    return &G;
}
