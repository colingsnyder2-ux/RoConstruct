// from server: 100% by auto
// roc 2009-06 00486a90  unit: Ogre::RbxMeshPartAdapter  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00486a90
//
// 00486a90  55                   push ebp
// 00486a91  8bec                 mov ebp, esp
// 00486a93  6aff                 push -1
// 00486a95  68a0548500           push 0x8554a0
// 00486a9a  64a100000000         mov eax, dword ptr fs:[0]
// 00486aa0  50                   push eax
// 00486aa1  64892500000000       mov dword ptr fs:[0], esp
// 00486aa8  83ec0c               sub esp, 0xc
// 00486aab  53                   push ebx
// 00486aac  8b5d08               mov ebx, dword ptr [ebp + 8]
// 00486aaf  33c0                 xor eax, eax
// 00486ab1  56                   push esi
// 00486ab2  8bf1                 mov esi, ecx
// 00486ab4  57                   push edi
// 00486ab5  8965f0               mov dword ptr [ebp - 0x10], esp
// 00486ab8  8975e8               mov dword ptr [ebp - 0x18], esi
// 00486abb  89460c               mov dword ptr [esi + 0xc], eax
// 00486abe  894610               mov dword ptr [esi + 0x10], eax
// 00486ac1  894614               mov dword ptr [esi + 0x14], eax
// 00486ac4  3bd8                 cmp ebx, eax
// 00486ac6  7452                 je 0x486b1a
// 00486ac8  81fbffffff0f         cmp ebx, 0xfffffff
// 00486ace  7605                 jbe 0x486ad5
// 00486ad0  e88b980000           call 0x490360
// 00486ad5  50                   push eax
// 00486ad6  53                   push ebx
// 00486ad7  e874baffff           call 0x482550
// 00486adc  8b5508               mov edx, dword ptr [ebp + 8]
// 00486adf  8bf8                 mov edi, eax
// 00486ae1  c1e304               shl ebx, 4
// 00486ae4  c645ec00             mov byte ptr [ebp - 0x14], 0
// 00486ae8  8b4dec               mov ecx, dword ptr [ebp - 0x14]
// 00486aeb  51                   push ecx
// 00486aec  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00486aef  52                   push edx
// 00486af0  8b5508               mov edx, dword ptr [ebp + 8]
// 00486af3  8d043b               lea eax, [ebx + edi]
// 00486af6  894614               mov dword ptr [esi + 0x14], eax
// 00486af9  8d4608               lea eax, [esi + 8]
// 00486afc  50                   push eax
// 00486afd  51                   push ecx
// 00486afe  52                   push edx
// 00486aff  57                   push edi
// 00486b00  897e0c               mov dword ptr [esi + 0xc], edi
// 00486b03  897e10               mov dword ptr [esi + 0x10], edi
// 00486b06  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00486b0d  e84ef9ffff           call 0x486460
// 00486b12  83c420               add esp, 0x20
// 00486b15  03df                 add ebx, edi
// 00486b17  895e10               mov dword ptr [esi + 0x10], ebx
// 00486b1a  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00486b1d  5f                   pop edi
// 00486b1e  5e                   pop esi
// 00486b1f  64890d00000000       mov dword ptr fs:[0], ecx
// 00486b26  5b                   pop ebx
// 00486b27  8be5                 mov esp, ebp
// 00486b29  5d                   pop ebp
// 00486b2a  c20800               ret 8
// standard library vector<pod16> (function ?_Construct_n@?$vector@UE@@V?$allocator@UE@@@std@@@std@@QAEXIABUE@@@Z)

// stl: vector<pod16>
struct E { int v[4]; };
#include <vector>
template class std::vector<E>;
