// roc 2012-06 00a35bf0  unit: CXTPDockingPaneWindowSelect  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a35bf0
//
// 00a35bf0  b89c0ec200           mov eax, 0xc20e9c
// 00a35bf5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a35bf0()
{
    return &G;
}
