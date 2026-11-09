// from server: 100% by auto
// roc 2011-06 00446ee0  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00446ee0
//
// 00446ee0  8b442408             mov eax, dword ptr [esp + 8]
// 00446ee4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00446ee8  50                   push eax
// 00446ee9  51                   push ecx
// 00446eea  ff15ac04a400         call dword ptr [0xa404ac]
// 00446ef0  83c408               add esp, 8
// 00446ef3  c20800               ret 8
// standard library map_str<ptr> (function ??R?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@QBE_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
