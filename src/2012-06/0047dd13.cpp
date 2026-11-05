// roc 2012-06 0047dd13  unit: CRobloxDoc  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0047dd13
//
// 0047dd13  b819dd4700           mov eax, 0x47dd19
// 0047dd18  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0047dd13()
{
    return &G;
}
