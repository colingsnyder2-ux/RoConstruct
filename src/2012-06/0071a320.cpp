// roc 2012-06 0071a320  unit: RBX::BaseScript  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0071a320
//
// 0071a320  b8e820e300           mov eax, 0xe320e8
// 0071a325  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_0071a320()
{
    return &G;
}
