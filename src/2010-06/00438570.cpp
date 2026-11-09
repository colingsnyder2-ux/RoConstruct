// from server: 100% by auto
// roc 2010-06 00438570  unit: std::D::DU?$char_traits::V?$basic_string::?$XItem  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00438570
//
// 00438570  8b442408             mov eax, dword ptr [esp + 8]
// 00438574  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00438578  50                   push eax
// 00438579  51                   push ecx
// 0043857a  ff158ca49e00         call dword ptr [0x9ea48c]
// 00438580  83c408               add esp, 8
// 00438583  c20800               ret 8
// standard library map_str<ptr> (function ??R?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@QBE_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
