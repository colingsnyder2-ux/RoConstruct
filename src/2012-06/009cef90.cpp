// roc 2012-06 009cef90  unit: CXTPControls  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009cef90
//
// 009cef90  b86448c100           mov eax, 0xc14864
// 009cef95  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009cef90()
{
    return &G;
}
