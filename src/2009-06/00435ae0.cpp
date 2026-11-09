// from server: 100% by auto
// roc 2009-06 00435ae0  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00435ae0
//
// 00435ae0  8b442408             mov eax, dword ptr [esp + 8]
// 00435ae4  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00435ae8  50                   push eax
// 00435ae9  51                   push ecx
// 00435aea  ff1544e48900         call dword ptr [0x89e444]
// 00435af0  83c408               add esp, 8
// 00435af3  c20800               ret 8
// standard library map_str<ptr> (function ??R?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@QBE_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
