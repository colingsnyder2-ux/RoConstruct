// roc 2012-06 00984960  unit: CXTPControl  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00984960
//
// 00984960  b83428e000           mov eax, 0xe02834
// 00984965  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00984960()
{
    return &G;
}
