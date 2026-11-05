// from server: 100% by auto
// roc 2010-06 0079ca80  unit: std::Vlength_error::U?$error_info_injector::?$clone_impl  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0079ca80
//
// 0079ca80  83ec08               sub esp, 8
// 0079ca83  56                   push esi
// 0079ca84  8bf1                 mov esi, ecx
// 0079ca86  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 0079ca89  57                   push edi
// 0079ca8a  85c9                 test ecx, ecx
// 0079ca8c  7504                 jne 0x79ca92
// 0079ca8e  33c0                 xor eax, eax
// 0079ca90  eb08                 jmp 0x79ca9a
// 0079ca92  8b4614               mov eax, dword ptr [esi + 0x14]
// 0079ca95  2bc1                 sub eax, ecx
// 0079ca97  c1f803               sar eax, 3
// 0079ca9a  8b7e10               mov edi, dword ptr [esi + 0x10]
// 0079ca9d  8bd7                 mov edx, edi
// 0079ca9f  2bd1                 sub edx, ecx
// 0079caa1  c1fa03               sar edx, 3
// 0079caa4  3bd0                 cmp edx, eax
// 0079caa6  7331                 jae 0x79cad9
// 0079caa8  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0079caac  c644240800           mov byte ptr [esp + 8], 0
// 0079cab1  8b442408             mov eax, dword ptr [esp + 8]
// 0079cab5  50                   push eax
// 0079cab6  8b442418             mov eax, dword ptr [esp + 0x18]
// 0079caba  51                   push ecx
// 0079cabb  8d5608               lea edx, [esi + 8]
// 0079cabe  52                   push edx
// 0079cabf  50                   push eax
// 0079cac0  6a01                 push 1
// 0079cac2  57                   push edi
// 0079cac3  e858150000           call 0x79e020
// 0079cac8  83c418               add esp, 0x18
// 0079cacb  83c708               add edi, 8
// 0079cace  897e10               mov dword ptr [esi + 0x10], edi
// 0079cad1  5f                   pop edi
// 0079cad2  5e                   pop esi
// 0079cad3  83c408               add esp, 8
// 0079cad6  c20400               ret 4
// 0079cad9  3bcf                 cmp ecx, edi
// 0079cadb  7606                 jbe 0x79cae3
// 0079cadd  ff150ca99e00         call dword ptr [0x9ea90c]
// 0079cae3  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0079cae7  8b06                 mov eax, dword ptr [esi]
// 0079cae9  51                   push ecx
// 0079caea  57                   push edi
// 0079caeb  50                   push eax
// 0079caec  8d542414             lea edx, [esp + 0x14]
// 0079caf0  52                   push edx
// 0079caf1  8bce                 mov ecx, esi
// 0079caf3  e8e8fdffff           call 0x79c8e0
// 0079caf8  5f                   pop edi
// 0079caf9  5e                   pop esi
// 0079cafa  83c408               add esp, 8
// 0079cafd  c20400               ret 4
// standard library vector<pod8> (function ?push_back@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXABUE@@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
