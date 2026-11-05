// roc 2011-06 0042c2b7  unit: RBX::Kernel  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0042c2b7
//
// 0042c2b7  b8bdc24200           mov eax, 0x42c2bd
// 0042c2bc  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0042c2b7()
{
    return &G;
}
