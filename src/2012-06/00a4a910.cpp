// roc 2012-06 00a4a910  unit: CXTPShadowsManager::CShadowWnd  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a4a910
//
// 00a4a910  b8d42cc200           mov eax, 0xc22cd4
// 00a4a915  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a4a910()
{
    return &G;
}
