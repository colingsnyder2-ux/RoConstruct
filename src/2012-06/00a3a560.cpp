// roc 2012-06 00a3a560  unit: CXTPDockingPaneTabbedContainer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a3a560
//
// 00a3a560  b82c17c200           mov eax, 0xc2172c
// 00a3a565  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a3a560()
{
    return &G;
}
