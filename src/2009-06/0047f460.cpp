// from server: 100% by auto
// roc 2009-06 0047f460  unit: Ogre::RbxPart  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0047f460
//
// 0047f460  83ec08               sub esp, 8
// 0047f463  53                   push ebx
// 0047f464  55                   push ebp
// 0047f465  56                   push esi
// 0047f466  8bf1                 mov esi, ecx
// 0047f468  8b4610               mov eax, dword ptr [esi + 0x10]
// 0047f46b  57                   push edi
// 0047f46c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0047f46f  8bc8                 mov ecx, eax
// 0047f471  2bcf                 sub ecx, edi
// 0047f473  f7c1f8ffffff         test ecx, 0xfffffff8
// 0047f479  7504                 jne 0x47f47f
// 0047f47b  33db                 xor ebx, ebx
// 0047f47d  eb27                 jmp 0x47f4a6
// 0047f47f  3bf8                 cmp edi, eax
// 0047f481  7606                 jbe 0x47f489
// 0047f483  ff15ace98900         call dword ptr [0x89e9ac]
// 0047f489  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0047f48d  8b06                 mov eax, dword ptr [esi]
// 0047f48f  85c9                 test ecx, ecx
// 0047f491  7404                 je 0x47f497
// 0047f493  3bc8                 cmp ecx, eax
// 0047f495  7406                 je 0x47f49d
// 0047f497  ff15ace98900         call dword ptr [0x89e9ac]
// 0047f49d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0047f4a1  2bdf                 sub ebx, edi
// 0047f4a3  c1fb03               sar ebx, 3
// 0047f4a6  8b542428             mov edx, dword ptr [esp + 0x28]
// 0047f4aa  8b442424             mov eax, dword ptr [esp + 0x24]
// 0047f4ae  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0047f4b2  52                   push edx
// 0047f4b3  6a01                 push 1
// 0047f4b5  50                   push eax
// 0047f4b6  51                   push ecx
// 0047f4b7  8bce                 mov ecx, esi
// 0047f4b9  e872f5ffff           call 0x47ea30
// 0047f4be  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0047f4c1  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0047f4c4  7606                 jbe 0x47f4cc
// 0047f4c6  ff15ace98900         call dword ptr [0x89e9ac]
// 0047f4cc  8b36                 mov esi, dword ptr [esi]
// 0047f4ce  8bee                 mov ebp, esi
// 0047f4d0  897c2414             mov dword ptr [esp + 0x14], edi
// 0047f4d4  85f6                 test esi, esi
// 0047f4d6  7518                 jne 0x47f4f0
// 0047f4d8  ff15ace98900         call dword ptr [0x89e9ac]
// 0047f4de  33c0                 xor eax, eax
// 0047f4e0  8d3cdf               lea edi, [edi + ebx*8]
// 0047f4e3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0047f4e6  7713                 ja 0x47f4fb
// 0047f4e8  85f6                 test esi, esi
// 0047f4ea  7408                 je 0x47f4f4
// 0047f4ec  8b36                 mov esi, dword ptr [esi]
// 0047f4ee  eb06                 jmp 0x47f4f6
// 0047f4f0  8b06                 mov eax, dword ptr [esi]
// 0047f4f2  ebec                 jmp 0x47f4e0
// 0047f4f4  33f6                 xor esi, esi
// 0047f4f6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0047f4f9  7306                 jae 0x47f501
// 0047f4fb  ff15ace98900         call dword ptr [0x89e9ac]
// 0047f501  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0047f505  897804               mov dword ptr [eax + 4], edi
// 0047f508  5f                   pop edi
// 0047f509  5e                   pop esi
// 0047f50a  8928                 mov dword ptr [eax], ebp
// 0047f50c  5d                   pop ebp
// 0047f50d  5b                   pop ebx
// 0047f50e  83c408               add esp, 8
// 0047f511  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
