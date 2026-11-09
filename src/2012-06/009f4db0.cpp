// roc 2012-06 009f4db0  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f4db0
//
// 009f4db0  b8dc9bc100           mov eax, 0xc19bdc
// 009f4db5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f4db0()
{
    return &G;
}
