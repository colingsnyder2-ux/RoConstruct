// from server: 100% by auto
// roc 2009-06 0053b060  unit: RBX::VerticalCylinderBuilder  size: 44 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0053b060
//
// 0053b060  56                   push esi
// 0053b061  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0053b065  57                   push edi
// 0053b066  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 0053b06a  8bc6                 mov eax, esi
// 0053b06c  8bcf                 mov ecx, edi
// 0053b06e  85f6                 test esi, esi
// 0053b070  7612                 jbe 0x53b084
// 0053b072  8b542414             mov edx, dword ptr [esp + 0x14]
// 0053b076  53                   push ebx
// 0053b077  8b1a                 mov ebx, dword ptr [edx]
// 0053b079  8919                 mov dword ptr [ecx], ebx
// 0053b07b  48                   dec eax
// 0053b07c  83c104               add ecx, 4
// 0053b07f  85c0                 test eax, eax
// 0053b081  77f4                 ja 0x53b077
// 0053b083  5b                   pop ebx
// 0053b084  8d04b7               lea eax, [edi + esi*4]
// 0053b087  5f                   pop edi
// 0053b088  5e                   pop esi
// 0053b089  c20c00               ret 0xc
// standard library vector<ptr> (function ?_Ufill@?$vector@PAUT@@V?$allocator@PAUT@@@std@@@std@@IAEPAPAUT@@PAPAU3@IABQAU3@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
