// from server: 100% by auto
// roc 2008-06 0043b910  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0043b910
//
// 0043b910  8b442408             mov eax, dword ptr [esp + 8]
// 0043b914  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0043b918  50                   push eax
// 0043b919  51                   push ecx
// 0043b91a  ff1544248000         call dword ptr [0x802444]
// 0043b920  83c408               add esp, 8
// 0043b923  c20800               ret 8
// standard library map_str<ptr> (function ??R?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@QBE_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
