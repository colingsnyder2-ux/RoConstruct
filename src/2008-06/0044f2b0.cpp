// from server: 100% by auto
// roc 2008-06 0044f2b0  unit: CRobloxDoc  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0044f2b0
//
// 0044f2b0  8b442404             mov eax, dword ptr [esp + 4]
// 0044f2b4  8b08                 mov ecx, dword ptr [eax]
// 0044f2b6  8b542408             mov edx, dword ptr [esp + 8]
// 0044f2ba  3b0a                 cmp ecx, dword ptr [edx]
// 0044f2bc  1bc0                 sbb eax, eax
// 0044f2be  f7d8                 neg eax
// 0044f2c0  c20800               ret 8
// standard library map_ptr<ptr> (function ??R?$less@PAUK@@@std@@QBE_NABQAUK@@0@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
