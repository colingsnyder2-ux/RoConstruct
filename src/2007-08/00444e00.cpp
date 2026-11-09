// from server: 100% by auto
// roc 2007-08 00444e00  unit: RBX::Reflection::Metadata::VItem::?$BoundPropGetSet  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00444e00
//
// 00444e00  8b442408             mov eax, dword ptr [esp + 8]
// 00444e04  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00444e08  50                   push eax
// 00444e09  51                   push ecx
// 00444e0a  ff1520e67700         call dword ptr [0x77e620]
// 00444e10  83c408               add esp, 8
// 00444e13  c20800               ret 8
// standard library map_str<ptr> (function ??R?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@QBE_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
