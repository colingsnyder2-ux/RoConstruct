// roc 2012-06 009b9740  unit: CXTPReportRecordItemPreview  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b9740
//
// 009b9740  b8b43ae000           mov eax, 0xe03ab4
// 009b9745  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009b9740()
{
    return &G;
}
