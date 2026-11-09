// from server: 100% by auto
// roc 2011-06 0040b480  unit: std::Vruntime_error::?$error_info_injector  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0040b480
//
// 0040b480  8b442404             mov eax, dword ptr [esp + 4]
// 0040b484  56                   push esi
// 0040b485  50                   push eax
// 0040b486  8bf1                 mov esi, ecx
// 0040b488  e88365ffff           call 0x401a10
// 0040b48d  c70644bfa500         mov dword ptr [esi], 0xa5bf44
// 0040b493  8bc6                 mov eax, esi
// 0040b495  5e                   pop esi
// 0040b496  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
