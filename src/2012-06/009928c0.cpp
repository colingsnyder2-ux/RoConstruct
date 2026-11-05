// roc 2012-06 009928c0  unit: CXTPControlComboBoxList  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009928c0
//
// 009928c0  b8d8dfc000           mov eax, 0xc0dfd8
// 009928c5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009928c0()
{
    return &G;
}
