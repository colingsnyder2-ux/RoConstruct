// from server: 100% by auto
// roc 2009-12 00443690  unit: RBX::MergeBinder  size: 182 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00443690
//
// 00443690  83ec08               sub esp, 8
// 00443693  53                   push ebx
// 00443694  55                   push ebp
// 00443695  56                   push esi
// 00443696  8bf1                 mov esi, ecx
// 00443698  8b4610               mov eax, dword ptr [esi + 0x10]
// 0044369b  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 0044369e  8bc8                 mov ecx, eax
// 004436a0  2bcb                 sub ecx, ebx
// 004436a2  57                   push edi
// 004436a3  f7c1f0ffffff         test ecx, 0xfffffff0
// 004436a9  7504                 jne 0x4436af
// 004436ab  33ff                 xor edi, edi
// 004436ad  eb27                 jmp 0x4436d6
// 004436af  3bd8                 cmp ebx, eax
// 004436b1  7606                 jbe 0x4436b9
// 004436b3  ff1560b79800         call dword ptr [0x98b760]
// 004436b9  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004436bd  8b06                 mov eax, dword ptr [esi]
// 004436bf  85c9                 test ecx, ecx
// 004436c1  7404                 je 0x4436c7
// 004436c3  3bc8                 cmp ecx, eax
// 004436c5  7406                 je 0x4436cd
// 004436c7  ff1560b79800         call dword ptr [0x98b760]
// 004436cd  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004436d1  2bfb                 sub edi, ebx
// 004436d3  c1ff04               sar edi, 4
// 004436d6  8b542428             mov edx, dword ptr [esp + 0x28]
// 004436da  8b442424             mov eax, dword ptr [esp + 0x24]
// 004436de  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 004436e2  52                   push edx
// 004436e3  6a01                 push 1
// 004436e5  50                   push eax
// 004436e6  51                   push ecx
// 004436e7  8bce                 mov ecx, esi
// 004436e9  e8c2fcffff           call 0x4433b0
// 004436ee  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004436f1  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 004436f4  7606                 jbe 0x4436fc
// 004436f6  ff1560b79800         call dword ptr [0x98b760]
// 004436fc  8b36                 mov esi, dword ptr [esi]
// 004436fe  8bee                 mov ebp, esi
// 00443700  895c2414             mov dword ptr [esp + 0x14], ebx
// 00443704  85f6                 test esi, esi
// 00443706  751a                 jne 0x443722
// 00443708  ff1560b79800         call dword ptr [0x98b760]
// 0044370e  33c0                 xor eax, eax
// 00443710  c1e704               shl edi, 4
// 00443713  03fb                 add edi, ebx
// 00443715  3b7810               cmp edi, dword ptr [eax + 0x10]
// 00443718  7713                 ja 0x44372d
// 0044371a  85f6                 test esi, esi
// 0044371c  7408                 je 0x443726
// 0044371e  8b36                 mov esi, dword ptr [esi]
// 00443720  eb06                 jmp 0x443728
// 00443722  8b06                 mov eax, dword ptr [esi]
// 00443724  ebea                 jmp 0x443710
// 00443726  33f6                 xor esi, esi
// 00443728  3b7e0c               cmp edi, dword ptr [esi + 0xc]
// 0044372b  7306                 jae 0x443733
// 0044372d  ff1560b79800         call dword ptr [0x98b760]
// 00443733  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00443737  897804               mov dword ptr [eax + 4], edi
// 0044373a  5f                   pop edi
// 0044373b  5e                   pop esi
// 0044373c  8928                 mov dword ptr [eax], ebp
// 0044373e  5d                   pop ebp
// 0044373f  5b                   pop ebx
// 00443740  83c408               add esp, 8
// 00443743  c21000               ret 0x10
// standard library vector<pod16> (function ?insert@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE?AV?$_Vector_iterator@UE@@V?$allocator@UE@@@std@@@2@V?$_Vector_const_iterator@UE@@V?$allocator@UE@@@std@@@2@ABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
