// roc 2012-06 009d49c0  unit: CXTPPrintPageHeaderFooter  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d49c0
//
// 009d49c0  b8f45bc100           mov eax, 0xc15bf4
// 009d49c5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009d49c0()
{
    return &G;
}
