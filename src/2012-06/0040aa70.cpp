// from server: 100% by auto
// roc 2012-06 0040aa70  unit: RBX::VScriptContext::?$FactoryProduct::Creator  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0040aa70
//
// 0040aa70  8b442408             mov eax, dword ptr [esp + 8]
// 0040aa74  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0040aa78  50                   push eax
// 0040aa79  51                   push ecx
// 0040aa7a  ff155026b200         call dword ptr [0xb22650]
// 0040aa80  83c408               add esp, 8
// 0040aa83  c20800               ret 8
// standard library map_str<ptr> (function ??R?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@QBE_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
