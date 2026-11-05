// roc 2010-06 009608cc  unit: RBX::SphereBuilder  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 009608cc
//
// 009608cc  b866079600           mov eax, 0x960766
// 009608d1  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_009608cc()
{
    return &G;
}
