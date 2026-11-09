// roc 2012-06 00744b17  unit: boost::Vbad_lexical_cast::U?$error_info_injector::?$clone_impl  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00744b17
//
// 00744b17  b81d4b7400           mov eax, 0x744b1d
// 00744b1c  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00744b17()
{
    return &G;
}
