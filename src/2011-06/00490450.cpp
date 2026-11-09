// from server: 100% by auto
// roc 2011-06 00490450  unit: CRobloxScriptReviewPaneView  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00490450
//
// 00490450  8b442408             mov eax, dword ptr [esp + 8]
// 00490454  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00490458  50                   push eax
// 00490459  51                   push ecx
// 0049045a  ff153405a400         call dword ptr [0xa40534]
// 00490460  83c408               add esp, 8
// 00490463  c20800               ret 8
// standard library map_str<ptr> (function ??R?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@std@@QBE_NABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@0@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
