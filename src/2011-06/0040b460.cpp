// from server: 100% by auto
// roc 2011-06 0040b460  unit: std::Vruntime_error::?$error_info_injector  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0040b460
//
// 0040b460  8b442404             mov eax, dword ptr [esp + 4]
// 0040b464  56                   push esi
// 0040b465  50                   push eax
// 0040b466  8bf1                 mov esi, ecx
// 0040b468  e8a365ffff           call 0x401a10
// 0040b46d  c7060cbfa500         mov dword ptr [esi], 0xa5bf0c
// 0040b473  8bc6                 mov eax, esi
// 0040b475  5e                   pop esi
// 0040b476  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
