// roc 2012-06 007a4480  unit: RBX::ExtrudedPartInstance  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007a4480
//
// 007a4480  b8a45edc00           mov eax, 0xdc5ea4
// 007a4485  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_007a4480()
{
    return &G;
}
