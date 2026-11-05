// roc 2012-06 009c8930  unit: CXTPToolBar::CControlButtonExpand  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009c8930
//
// 009c8930  b8a03ee000           mov eax, 0xe03ea0
// 009c8935  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009c8930()
{
    return &G;
}
