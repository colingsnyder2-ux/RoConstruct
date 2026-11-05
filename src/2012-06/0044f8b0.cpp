// from server: 100% by auto
// roc 2012-06 0044f8b0  unit: boost::gregorian::Ubad_day_of_year::U?$error_info_injector::?$clone_impl  size: 117 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044f8b0
//
// 0044f8b0  53                   push ebx
// 0044f8b1  56                   push esi
// 0044f8b2  8bf1                 mov esi, ecx
// 0044f8b4  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0044f8b7  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0044f8ba  03c8                 add ecx, eax
// 0044f8bc  57                   push edi
// 0044f8bd  f6c10f               test cl, 0xf
// 0044f8c0  7514                 jne 0x44f8d6
// 0044f8c2  83c010               add eax, 0x10
// 0044f8c5  c1e804               shr eax, 4
// 0044f8c8  394614               cmp dword ptr [esi + 0x14], eax
// 0044f8cb  7709                 ja 0x44f8d6
// 0044f8cd  6a01                 push 1
// 0044f8cf  8bce                 mov ecx, esi
// 0044f8d1  e8aaf9ffff           call 0x44f280
// 0044f8d6  8b7e18               mov edi, dword ptr [esi + 0x18]
// 0044f8d9  037e1c               add edi, dword ptr [esi + 0x1c]
// 0044f8dc  8b4614               mov eax, dword ptr [esi + 0x14]
// 0044f8df  8bdf                 mov ebx, edi
// 0044f8e1  c1eb04               shr ebx, 4
// 0044f8e4  3bc3                 cmp eax, ebx
// 0044f8e6  7702                 ja 0x44f8ea
// 0044f8e8  2bd8                 sub ebx, eax
// 0044f8ea  8b5610               mov edx, dword ptr [esi + 0x10]
// 0044f8ed  833c9a00             cmp dword ptr [edx + ebx*4], 0
// 0044f8f1  7511                 jne 0x44f904
// 0044f8f3  6a10                 push 0x10
// 0044f8f5  8d4e0c               lea ecx, [esi + 0xc]
// 0044f8f8  ff15dc25b200         call dword ptr [0xb225dc]
// 0044f8fe  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0044f901  890499               mov dword ptr [ecx + ebx*4], eax
// 0044f904  8b4610               mov eax, dword ptr [esi + 0x10]
// 0044f907  8b542410             mov edx, dword ptr [esp + 0x10]
// 0044f90b  83e70f               and edi, 0xf
// 0044f90e  033c98               add edi, dword ptr [eax + ebx*4]
// 0044f911  52                   push edx
// 0044f912  57                   push edi
// 0044f913  8d4e0c               lea ecx, [esi + 0xc]
// 0044f916  ff15e025b200         call dword ptr [0xb225e0]
// 0044f91c  ff461c               inc dword ptr [esi + 0x1c]
// 0044f91f  5f                   pop edi
// 0044f920  5e                   pop esi
// 0044f921  5b                   pop ebx
// 0044f922  c20400               ret 4
// standard library deque<char> (function ?push_back@?$deque@DV?$allocator@D@std@@@std@@QAEXABD@Z)

// stl: deque<char>
typedef char E;
#include <deque>
template class std::deque<E>;
