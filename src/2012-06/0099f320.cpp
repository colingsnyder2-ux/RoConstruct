// roc 2012-06 0099f320  unit: CXTPToolBar  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0099f320
//
// 0099f320  b8242ee000           mov eax, 0xe02e24
// 0099f325  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0099f320()
{
    return &G;
}
