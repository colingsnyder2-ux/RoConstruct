// roc 2012-06 00743d50  unit: boost::bad_lexical_cast  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00743d50
//
// 00743d50  b888a8ba00           mov eax, 0xbaa888
// 00743d55  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00743d50()
{
    return &G;
}
