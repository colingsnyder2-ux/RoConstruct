// from server: 100% by auto
// roc 2009-06 005d9010  unit: VAuthoringSettings::?$BoundPropGetSet  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005d9010
//
// 005d9010  8b442408             mov eax, dword ptr [esp + 8]
// 005d9014  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005d9018  50                   push eax
// 005d9019  51                   push ecx
// 005d901a  ff15e0e48900         call dword ptr [0x89e4e0]
// 005d9020  83c408               add esp, 8
// 005d9023  c20800               ret 8
// standard library map_str<ptr> (function ??R?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@QBE_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
