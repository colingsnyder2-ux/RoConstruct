// roc 2012-06 009b9520  unit: CXTPReportRecordItemNumber  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b9520
//
// 009b9520  b87c3ae000           mov eax, 0xe03a7c
// 009b9525  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009b9520()
{
    return &G;
}
