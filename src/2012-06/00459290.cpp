// from server: 100% by auto
// roc 2012-06 00459290  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00459290
//
// 00459290  8b442408             mov eax, dword ptr [esp + 8]
// 00459294  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00459298  50                   push eax
// 00459299  51                   push ecx
// 0045929a  ff156026b200         call dword ptr [0xb22660]
// 004592a0  83c408               add esp, 8
// 004592a3  c20800               ret 8
// standard library map_str<ptr> (function ??R?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@QBE_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
