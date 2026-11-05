// roc 2007-08 00459494  unit: CRobloxWnd  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00459494
//
// 00459494  b89a944500           mov eax, 0x45949a
// 00459499  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00459494()
{
    return &G;
}
