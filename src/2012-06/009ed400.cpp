// roc 2012-06 009ed400  unit: CXTPToolTipContext  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009ed400
//
// 009ed400  b8188ac100           mov eax, 0xc18a18
// 009ed405  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009ed400()
{
    return &G;
}
