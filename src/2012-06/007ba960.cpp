// roc 2012-06 007ba960  unit: RBX::AssemblyStage  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007ba960
//
// 007ba960  b809000000           mov eax, 9
// 007ba965  c3                   ret 
// auto-matched from its assembly shape

unsigned int func_007ba960()
{
    return 9u;
}
