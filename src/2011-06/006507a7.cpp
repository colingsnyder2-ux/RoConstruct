// roc 2011-06 006507a7  unit: std::D::DU?$char_traits::DV?$basic_streambuf::?$lexical_stream_limited_src  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006507a7
//
// 006507a7  b8ad076500           mov eax, 0x6507ad
// 006507ac  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_006507a7()
{
    return &G;
}
