// roc 2012-06 009b96a0  unit: CXTPReportRecordItemDateTime  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b96a0
//
// 009b96a0  b8983ae000           mov eax, 0xe03a98
// 009b96a5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009b96a0()
{
    return &G;
}
