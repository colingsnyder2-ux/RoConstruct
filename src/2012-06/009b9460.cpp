// roc 2012-06 009b9460  unit: CXTPReportRecordItemText  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b9460
//
// 009b9460  b8603ae000           mov eax, 0xe03a60
// 009b9465  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009b9460()
{
    return &G;
}
