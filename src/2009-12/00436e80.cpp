// from server: 100% by auto
// roc 2009-12 00436e80  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00436e80
//
// 00436e80  8b442408             mov eax, dword ptr [esp + 8]
// 00436e84  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00436e88  50                   push eax
// 00436e89  51                   push ecx
// 00436e8a  ff157cb69800         call dword ptr [0x98b67c]
// 00436e90  83c408               add esp, 8
// 00436e93  c20800               ret 8
// standard library map_str<ptr> (function ??R?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@QBE_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
