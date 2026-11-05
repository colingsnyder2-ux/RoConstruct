// roc 2012-06 009d2620  unit: CXTPControlSelector  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d2620
//
// 009d2620  b83841e000           mov eax, 0xe04138
// 009d2625  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009d2620()
{
    return &G;
}
