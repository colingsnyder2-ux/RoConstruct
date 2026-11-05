// roc 2012-06 009a1fd0  unit: CXTPDialogBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009a1fd0
//
// 009a1fd0  b8bcf0c000           mov eax, 0xc0f0bc
// 009a1fd5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009a1fd0()
{
    return &G;
}
