// roc 2012-06 009cefa0  unit: CXTPOriginalControls  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009cefa0
//
// 009cefa0  b88048c100           mov eax, 0xc14880
// 009cefa5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009cefa0()
{
    return &G;
}
