// roc 2008-06 00500b7f  unit: RBX::ViewNew::HeadBuilder  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00500b7f
//
// 00500b7f  b8e5075000           mov eax, 0x5007e5
// 00500b84  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00500b7f()
{
    return &G;
}
