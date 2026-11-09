// roc 2012-06 00984e40  unit: CXTPPropertyGridItem  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00984e40
//
// 00984e40  b8e8cdc000           mov eax, 0xc0cde8
// 00984e45  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00984e40()
{
    return &G;
}
