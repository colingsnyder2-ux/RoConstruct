// from server: 100% by auto
// roc 2007-08 0043a9f0  unit: CSelectionPropGrid  size: 213 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0043a9f0
//
// 0043a9f0  55                   push ebp
// 0043a9f1  8bec                 mov ebp, esp
// 0043a9f3  6aff                 push -1
// 0043a9f5  6860e87300           push 0x73e860
// 0043a9fa  64a100000000         mov eax, dword ptr fs:[0]
// 0043aa00  50                   push eax
// 0043aa01  83ec0c               sub esp, 0xc
// 0043aa04  53                   push ebx
// 0043aa05  56                   push esi
// 0043aa06  57                   push edi
// 0043aa07  a188518b00           mov eax, dword ptr [0x8b5188]
// 0043aa0c  33c5                 xor eax, ebp
// 0043aa0e  50                   push eax
// 0043aa0f  8d45f4               lea eax, [ebp - 0xc]
// 0043aa12  64a300000000         mov dword ptr fs:[0], eax
// 0043aa18  8965f0               mov dword ptr [ebp - 0x10], esp
// 0043aa1b  8bf1                 mov esi, ecx
// 0043aa1d  8975e8               mov dword ptr [ebp - 0x18], esi
// 0043aa20  8b5d08               mov ebx, dword ptr [ebp + 8]
// 0043aa23  8b4304               mov eax, dword ptr [ebx + 4]
// 0043aa26  33c9                 xor ecx, ecx
// 0043aa28  3bc1                 cmp eax, ecx
// 0043aa2a  7504                 jne 0x43aa30
// 0043aa2c  33ff                 xor edi, edi
// 0043aa2e  eb08                 jmp 0x43aa38
// 0043aa30  8b7b08               mov edi, dword ptr [ebx + 8]
// 0043aa33  2bf8                 sub edi, eax
// 0043aa35  c1ff03               sar edi, 3
// 0043aa38  3bf9                 cmp edi, ecx
// 0043aa3a  894e04               mov dword ptr [esi + 4], ecx
// 0043aa3d  894e08               mov dword ptr [esi + 8], ecx
// 0043aa40  894e0c               mov dword ptr [esi + 0xc], ecx
// 0043aa43  746a                 je 0x43aaaf
// 0043aa45  81ffffffff1f         cmp edi, 0x1fffffff
// 0043aa4b  7605                 jbe 0x43aa52
// 0043aa4d  e8aecdfdff           call 0x417800
// 0043aa52  51                   push ecx
// 0043aa53  57                   push edi
// 0043aa54  e867d01200           call 0x567ac0
// 0043aa59  894604               mov dword ptr [esi + 4], eax
// 0043aa5c  894608               mov dword ptr [esi + 8], eax
// 0043aa5f  8d04f8               lea eax, [eax + edi*8]
// 0043aa62  89460c               mov dword ptr [esi + 0xc], eax
// 0043aa65  8b4308               mov eax, dword ptr [ebx + 8]
// 0043aa68  83c408               add esp, 8
// 0043aa6b  394304               cmp dword ptr [ebx + 4], eax
// 0043aa6e  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0043aa75  8945ec               mov dword ptr [ebp - 0x14], eax
// 0043aa78  7606                 jbe 0x43aa80
// 0043aa7a  ff15d8e67700         call dword ptr [0x77e6d8]
// 0043aa80  8b7b04               mov edi, dword ptr [ebx + 4]
// 0043aa83  3b7b08               cmp edi, dword ptr [ebx + 8]
// 0043aa86  7606                 jbe 0x43aa8e
// 0043aa88  ff15d8e67700         call dword ptr [0x77e6d8]
// 0043aa8e  8b4604               mov eax, dword ptr [esi + 4]
// 0043aa91  c6450800             mov byte ptr [ebp + 8], 0
// 0043aa95  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0043aa98  8b5508               mov edx, dword ptr [ebp + 8]
// 0043aa9b  51                   push ecx
// 0043aa9c  52                   push edx
// 0043aa9d  56                   push esi
// 0043aa9e  50                   push eax
// 0043aa9f  8b45ec               mov eax, dword ptr [ebp - 0x14]
// 0043aaa2  50                   push eax
// 0043aaa3  57                   push edi
// 0043aaa4  e85730fdff           call 0x40db00
// 0043aaa9  83c418               add esp, 0x18
// 0043aaac  894608               mov dword ptr [esi + 8], eax
// 0043aaaf  8bc6                 mov eax, esi
// 0043aab1  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0043aab4  64890d00000000       mov dword ptr fs:[0], ecx
// 0043aabb  59                   pop ecx
// 0043aabc  5f                   pop edi
// 0043aabd  5e                   pop esi
// 0043aabe  5b                   pop ebx
// 0043aabf  8be5                 mov esp, ebp
// 0043aac1  5d                   pop ebp
// 0043aac2  c20400               ret 4
// standard library vector<pod8> (function ??0?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAE@ABV01@@Z)

// stl: vector<pod8>
struct E { int v[2]; };
#include <vector>
template class std::vector<E>;
