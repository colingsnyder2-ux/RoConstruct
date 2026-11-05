// roc 2007-08 0045252f  unit: ReportAbuseVerb  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045252f
//
// 0045252f  b835254500           mov eax, 0x452535
// 00452534  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0045252f()
{
    return &G;
}
