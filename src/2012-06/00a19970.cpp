// roc 2012-06 00a19970  unit: CXTPToolBar::CControlButtonHide  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a19970
//
// 00a19970  b8f85be000           mov eax, 0xe05bf8
// 00a19975  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a19970()
{
    return &G;
}
