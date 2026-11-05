// roc 2007-08 0045158a  unit: ReportAbuseVerb  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0045158a
//
// 0045158a  b890154500           mov eax, 0x451590
// 0045158f  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0045158a()
{
    return &G;
}
