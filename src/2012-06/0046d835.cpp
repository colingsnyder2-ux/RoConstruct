// roc 2012-06 0046d835  unit: CRobloxApp  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0046d835
//
// 0046d835  b824d84600           mov eax, 0x46d824
// 0046d83a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0046d835()
{
    return &G;
}
