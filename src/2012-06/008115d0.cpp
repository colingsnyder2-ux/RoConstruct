// roc 2012-06 008115d0  unit: RBX::EdgeStage  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 008115d0
//
// 008115d0  b803000000           mov eax, 3
// 008115d5  c3                   ret 
// auto-matched from its assembly shape

unsigned int func_008115d0()
{
    return 3u;
}
