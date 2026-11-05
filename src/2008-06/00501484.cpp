// roc 2008-06 00501484  unit: boost::bad_lexical_cast  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00501484
//
// 00501484  b801000000           mov eax, 1
// 00501489  c3                   ret 
// auto-matched from its assembly shape

int func_00501484()
{
    return 1;
}
