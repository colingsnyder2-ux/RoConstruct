// roc 2012-06 00744b87  unit: boost::Vbad_lexical_cast::U?$error_info_injector::?$clone_impl  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00744b87
//
// 00744b87  b88d4b7400           mov eax, 0x744b8d
// 00744b8c  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00744b87()
{
    return &G;
}
