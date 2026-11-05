// roc 2011-06 00929935  unit: std::D::DU?$char_traits::V?$basic_string::?$STLAllocator  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00929935
//
// 00929935  b83b999200           mov eax, 0x92993b
// 0092993a  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00929935()
{
    return &G;
}
