// roc 2012-06 00a70c40  unit: CXTPDialogBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a70c40
//
// 00a70c40  b8647fe000           mov eax, 0xe07f64
// 00a70c45  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00a70c40()
{
    return &G;
}
