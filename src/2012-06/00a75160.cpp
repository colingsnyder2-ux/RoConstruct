// roc 2012-06 00a75160  unit: CXTPRibbonControls  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a75160
//
// 00a75160  b89c7ac200           mov eax, 0xc27a9c
// 00a75165  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a75160()
{
    return &G;
}
