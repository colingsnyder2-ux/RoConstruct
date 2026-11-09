// roc 2012-06 009d2420  unit: CXTPControlWindowList  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d2420
//
// 009d2420  b8c840e000           mov eax, 0xe040c8
// 009d2425  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009d2420()
{
    return &G;
}
