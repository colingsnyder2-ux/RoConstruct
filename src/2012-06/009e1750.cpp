// roc 2012-06 009e1750  unit: CXTPPropertyGrid  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e1750
//
// 009e1750  b8dc6dc100           mov eax, 0xc16ddc
// 009e1755  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009e1750()
{
    return &G;
}
