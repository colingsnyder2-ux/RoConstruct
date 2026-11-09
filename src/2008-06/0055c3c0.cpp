// from server: 100% by auto
// roc 2008-06 0055c3c0  unit: std::logic_error  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055c3c0
//
// 0055c3c0  8b442404             mov eax, dword ptr [esp + 4]
// 0055c3c4  56                   push esi
// 0055c3c5  50                   push eax
// 0055c3c6  8bf1                 mov esi, ecx
// 0055c3c8  e8638beaff           call 0x404f30
// 0055c3cd  c70678da8200         mov dword ptr [esi], 0x82da78
// 0055c3d3  8bc6                 mov eax, esi
// 0055c3d5  5e                   pop esi
// 0055c3d6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
