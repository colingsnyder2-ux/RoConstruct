// from server: 100% by auto
// roc 2008-06 0055c000  unit: RBX::VInstance::?$SignalDesc  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055c000
//
// 0055c000  8b442408             mov eax, dword ptr [esp + 8]
// 0055c004  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0055c008  50                   push eax
// 0055c009  51                   push ecx
// 0055c00a  ff155c238000         call dword ptr [0x80235c]
// 0055c010  83c408               add esp, 8
// 0055c013  c20800               ret 8
// standard library map_str<ptr> (function ??R?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@QBE_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
