// roc 2012-06 009b6c70  unit: CInstanceRecord::CNameItem  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009b6c70
//
// 009b6c70  b8e838e000           mov eax, 0xe038e8
// 009b6c75  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009b6c70()
{
    return &G;
}
