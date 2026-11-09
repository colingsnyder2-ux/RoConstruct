// from server: 100% by auto
// roc 2008-06 0055cb00  unit: RBX::MD5HasherImpl  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055cb00
//
// 0055cb00  8b442404             mov eax, dword ptr [esp + 4]
// 0055cb04  56                   push esi
// 0055cb05  50                   push eax
// 0055cb06  8bf1                 mov esi, ecx
// 0055cb08  e82384eaff           call 0x404f30
// 0055cb0d  c706e4da8200         mov dword ptr [esi], 0x82dae4
// 0055cb13  8bc6                 mov eax, esi
// 0055cb15  5e                   pop esi
// 0055cb16  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
