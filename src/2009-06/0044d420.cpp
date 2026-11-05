// from server: 100% by auto
// roc 2009-06 0044d420  unit: CRobloxDoc  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0044d420
//
// 0044d420  8b442404             mov eax, dword ptr [esp + 4]
// 0044d424  8b08                 mov ecx, dword ptr [eax]
// 0044d426  8b542408             mov edx, dword ptr [esp + 8]
// 0044d42a  3b0a                 cmp ecx, dword ptr [edx]
// 0044d42c  1bc0                 sbb eax, eax
// 0044d42e  f7d8                 neg eax
// 0044d430  c20800               ret 8
// standard library map_ptr<ptr> (function ??R?$less@PAUK@@@std@@QBE_NABQAUK@@0@Z)

// stl: map_ptr<ptr>
struct T; typedef T* E;
#include <map>
struct K; template class std::map<K*, E>;
