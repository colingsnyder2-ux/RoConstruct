// from server: 100% by auto
// roc 2007-08 0043ca90  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043ca90
//
// 0043ca90  8b442408             mov eax, dword ptr [esp + 8]
// 0043ca94  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0043ca98  50                   push eax
// 0043ca99  51                   push ecx
// 0043ca9a  ff1594e67700         call dword ptr [0x77e694]
// 0043caa0  83c408               add esp, 8
// 0043caa3  c20800               ret 8
// standard library map_str<ptr> (function ??R?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@QBE_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
