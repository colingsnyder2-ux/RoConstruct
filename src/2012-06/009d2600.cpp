// roc 2012-06 009d2600  unit: CXTPControlRecentFileList  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009d2600
//
// 009d2600  b81c41e000           mov eax, 0xe0411c
// 009d2605  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009d2600()
{
    return &G;
}
