// roc 2012-06 009f3b70  unit: CPropertyGridItemBrickColor  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009f3b70
//
// 009f3b70  b87496c100           mov eax, 0xc19674
// 009f3b75  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009f3b70()
{
    return &G;
}
