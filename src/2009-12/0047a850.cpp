// from server: 100% by auto
// roc 2009-12 0047a850  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0047a850
//
// 0047a850  8b442408             mov eax, dword ptr [esp + 8]
// 0047a854  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0047a858  50                   push eax
// 0047a859  51                   push ecx
// 0047a85a  ff15d8b59800         call dword ptr [0x98b5d8]
// 0047a860  83c408               add esp, 8
// 0047a863  c20800               ret 8
// standard library map_str<ptr> (function ??R?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@QBE_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
