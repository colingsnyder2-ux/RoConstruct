// roc 2012-06 004ca665  unit: std::D::DU?$char_traits::V?$basic_string::?$STLAllocator  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004ca665
//
// 004ca665  b86ba64c00           mov eax, 0x4ca66b
// 004ca66a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_004ca665()
{
    return &G;
}
