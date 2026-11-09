// roc 2007-08 0040d781  unit: ChatEnter  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0040d781
//
// 0040d781  b887d74000           mov eax, 0x40d787
// 0040d786  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0040d781()
{
    return &G;
}
