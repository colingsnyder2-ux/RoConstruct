// roc 2012-06 00a3e480  unit: CXTPDockingPaneSplitterContainer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a3e480
//
// 00a3e480  b8401ec200           mov eax, 0xc21e40
// 00a3e485  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a3e480()
{
    return &G;
}
