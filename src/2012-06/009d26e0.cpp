// roc 2012-06 009d26e0  unit: CXTPControlLabel  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d26e0
//
// 009d26e0  b87041e000           mov eax, 0xe04170
// 009d26e5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009d26e0()
{
    return &G;
}
