// roc 2012-06 006c81d0  unit: RBX::Reflection::PAVPropertyDescriptor::?$trie::bad_key  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006c81d0
//
// 006c81d0  b84470b900           mov eax, 0xb97044
// 006c81d5  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_006c81d0()
{
    return &G;
}
