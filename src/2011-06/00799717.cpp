// roc 2011-06 00799717  unit: RBX::AsyncHttpQueue  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00799717
//
// 00799717  b81d977900           mov eax, 0x79971d
// 0079971c  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00799717()
{
    return &G;
}
