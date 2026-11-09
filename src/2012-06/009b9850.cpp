// roc 2012-06 009b9850  unit: CXTPReportRecordItemVariant  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b9850
//
// 009b9850  b8d43ae000           mov eax, 0xe03ad4
// 009b9855  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009b9850()
{
    return &G;
}
