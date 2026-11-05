// from server: 100% by auto
// roc 2008-06 0055cae0  unit: RBX::MD5HasherImpl  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055cae0
//
// 0055cae0  8b442404             mov eax, dword ptr [esp + 4]
// 0055cae4  56                   push esi
// 0055cae5  50                   push eax
// 0055cae6  8bf1                 mov esi, ecx
// 0055cae8  e84384eaff           call 0x404f30
// 0055caed  c706b0da8200         mov dword ptr [esi], 0x82dab0
// 0055caf3  8bc6                 mov eax, esi
// 0055caf5  5e                   pop esi
// 0055caf6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
