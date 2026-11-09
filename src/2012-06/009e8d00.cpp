// roc 2012-06 009e8d00  unit: CXTPStatusBar::CStatusCmdUI  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e8d00
//
// 009e8d00  b8487bc100           mov eax, 0xc17b48
// 009e8d05  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009e8d00()
{
    return &G;
}
