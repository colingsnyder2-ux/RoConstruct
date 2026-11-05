// from server: 100% by auto
// roc 2012-06 0044f400  unit: boost::gregorian::Ubad_day_of_year::U?$error_info_injector::?$clone_impl  size: 115 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0044f400
//
// 0044f400  53                   push ebx
// 0044f401  56                   push esi
// 0044f402  8bf1                 mov esi, ecx
// 0044f404  f646180f             test byte ptr [esi + 0x18], 0xf
// 0044f408  57                   push edi
// 0044f409  7515                 jne 0x44f420
// 0044f40b  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0044f40e  83c010               add eax, 0x10
// 0044f411  c1e804               shr eax, 4
// 0044f414  394614               cmp dword ptr [esi + 0x14], eax
// 0044f417  7707                 ja 0x44f420
// 0044f419  6a01                 push 1
// 0044f41b  e860feffff           call 0x44f280
// 0044f420  8b5e18               mov ebx, dword ptr [esi + 0x18]
// 0044f423  85db                 test ebx, ebx
// 0044f425  7506                 jne 0x44f42d
// 0044f427  8b5e14               mov ebx, dword ptr [esi + 0x14]
// 0044f42a  c1e304               shl ebx, 4
// 0044f42d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0044f430  4b                   dec ebx
// 0044f431  8bfb                 mov edi, ebx
// 0044f433  c1ef04               shr edi, 4
// 0044f436  833cb900             cmp dword ptr [ecx + edi*4], 0
// 0044f43a  7511                 jne 0x44f44d
// 0044f43c  6a10                 push 0x10
// 0044f43e  8d4e0c               lea ecx, [esi + 0xc]
// 0044f441  ff15dc25b200         call dword ptr [0xb225dc]
// 0044f447  8b5610               mov edx, dword ptr [esi + 0x10]
// 0044f44a  8904ba               mov dword ptr [edx + edi*4], eax
// 0044f44d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 0044f450  8b442410             mov eax, dword ptr [esp + 0x10]
// 0044f454  8bd3                 mov edx, ebx
// 0044f456  83e20f               and edx, 0xf
// 0044f459  0314b9               add edx, dword ptr [ecx + edi*4]
// 0044f45c  50                   push eax
// 0044f45d  52                   push edx
// 0044f45e  8d4e0c               lea ecx, [esi + 0xc]
// 0044f461  ff15e025b200         call dword ptr [0xb225e0]
// 0044f467  ff461c               inc dword ptr [esi + 0x1c]
// 0044f46a  5f                   pop edi
// 0044f46b  895e18               mov dword ptr [esi + 0x18], ebx
// 0044f46e  5e                   pop esi
// 0044f46f  5b                   pop ebx
// 0044f470  c20400               ret 4
// standard library deque<char> (function ?push_front@?$deque@DV?$allocator@D@std@@@std@@QAEXABD@Z)

// stl: deque<char>
typedef char E;
#include <deque>
template class std::deque<E>;
