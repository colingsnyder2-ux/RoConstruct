// roc 2011-06 00656f73  unit: std::D::DU?$char_traits::V?$basic_string::V?$basic_path::V?$basic_filesystem_error::U?$error_info_injector::?$clone_impl  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00656f73
//
// 00656f73  b8796f6500           mov eax, 0x656f79
// 00656f78  c3                   ret 
// auto-matched from its assembly shape

extern char G;

char* func_00656f73()
{
    return &G;
}
