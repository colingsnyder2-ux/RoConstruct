// roc 2012-06 009b3750  unit: VCXTPReportRow::?$CXTPInternalCollectionT  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b3750
//
// 009b3750  b87808c100           mov eax, 0xc10878
// 009b3755  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009b3750()
{
    return &G;
}
