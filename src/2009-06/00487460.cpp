// from server: 100% by auto
// roc 2009-06 00487460  unit: Ogre::RbxMeshPartAdapter  size: 180 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00487460
//
// 00487460  83ec08               sub esp, 8
// 00487463  53                   push ebx
// 00487464  55                   push ebp
// 00487465  56                   push esi
// 00487466  8bf1                 mov esi, ecx
// 00487468  8b4610               mov eax, dword ptr [esi + 0x10]
// 0048746b  57                   push edi
// 0048746c  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0048746f  8bc8                 mov ecx, eax
// 00487471  2bcf                 sub ecx, edi
// 00487473  f7c1f8ffffff         test ecx, 0xfffffff8
// 00487479  7504                 jne 0x48747f
// 0048747b  33db                 xor ebx, ebx
// 0048747d  eb27                 jmp 0x4874a6
// 0048747f  3bf8                 cmp edi, eax
// 00487481  7606                 jbe 0x487489
// 00487483  ff15ace98900         call dword ptr [0x89e9ac]
// 00487489  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0048748d  8b06                 mov eax, dword ptr [esi]
// 0048748f  85c9                 test ecx, ecx
// 00487491  7404                 je 0x487497
// 00487493  3bc8                 cmp ecx, eax
// 00487495  7406                 je 0x48749d
// 00487497  ff15ace98900         call dword ptr [0x89e9ac]
// 0048749d  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 004874a1  2bdf                 sub ebx, edi
// 004874a3  c1fb03               sar ebx, 3
// 004874a6  8b542428             mov edx, dword ptr [esp + 0x28]
// 004874aa  8b442424             mov eax, dword ptr [esp + 0x24]
// 004874ae  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004874b2  52                   push edx
// 004874b3  6a01                 push 1
// 004874b5  50                   push eax
// 004874b6  51                   push ecx
// 004874b7  8bce                 mov ecx, esi
// 004874b9  e882f6ffff           call 0x486b40
// 004874be  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 004874c1  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 004874c4  7606                 jbe 0x4874cc
// 004874c6  ff15ace98900         call dword ptr [0x89e9ac]
// 004874cc  8b36                 mov esi, dword ptr [esi]
// 004874ce  8bee                 mov ebp, esi
// 004874d0  897c2414             mov dword ptr [esp + 0x14], edi
// 004874d4  85f6                 test esi, esi
// 004874d6  7518                 jne 0x4874f0
// 004874d8  ff15ace98900         call dword ptr [0x89e9ac]
// 004874de  33c0                 xor eax, eax
// 004874e0  8d3cdf               lea edi, [edi + ebx*8]
// 004874e3  3b7810               cmp edi, dword ptr [eax + 0x10]
// 004874e6  7713                 ja 0x4874fb
// 004874e8  85f6                 test esi, esi
// 004874ea  7408                 je 0x4874f4
// 004874ec  8b36                 mov esi, dword ptr [esi]
// 004874ee  eb06                 jmp 0x4874f6
// 004874f0  8b06                 mov eax, dword ptr [esi]
// 004874f2  ebec                 jmp 0x4874e0
// 004874f4  33f6                 xor esi, esi
// 004874f6  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 004874f9  7306                 jae 0x487501
// 004874fb  ff15ace98900         call dword ptr [0x89e9ac]
// 00487501  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00487505  897804               mov dword ptr [eax + 4], edi
// 00487508  5f                   pop edi
// 00487509  5e                   pop esi
// 0048750a  8928                 mov dword ptr [eax], ebp
// 0048750c  5d                   pop ebp
// 0048750d  5b                   pop ebx
// 0048750e  83c408               add esp, 8
// 00487511  c21000               ret 0x10
// standard library vector<double> (function ?insert@?$vector@NV?$allocator@N@std@@@std@@QAE?AV?$_Vector_iterator@NV?$allocator@N@std@@@2@V?$_Vector_const_iterator@NV?$allocator@N@std@@@2@ABN@Z)

// stl: vector<double>
typedef double E;
#include <vector>
template class std::vector<E>;
