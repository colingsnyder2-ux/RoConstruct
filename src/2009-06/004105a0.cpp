// from server: 100% by auto
// roc 2009-06 004105a0  unit: boost::Vbad_weak_ptr::U?$error_info_injector::?$clone_impl  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004105a0
//
// 004105a0  53                   push ebx
// 004105a1  56                   push esi
// 004105a2  8bf1                 mov esi, ecx
// 004105a4  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 004105a7  57                   push edi
// 004105a8  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 004105ac  c70700000000         mov dword ptr [edi], 0
// 004105b2  395e0c               cmp dword ptr [esi + 0xc], ebx
// 004105b5  7606                 jbe 0x4105bd
// 004105b7  ff15ace98900         call dword ptr [0x89e9ac]
// 004105bd  8b06                 mov eax, dword ptr [esi]
// 004105bf  8907                 mov dword ptr [edi], eax
// 004105c1  895f04               mov dword ptr [edi + 4], ebx
// 004105c4  8bc7                 mov eax, edi
// 004105c6  5f                   pop edi
// 004105c7  5e                   pop esi
// 004105c8  5b                   pop ebx
// 004105c9  c20400               ret 4
// standard library vector<ptr> (function ?end@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@QAE?AV?$_Vector_iterator@PAUT@@V?$allocator@PAUT@@@std@@@2@XZ)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
