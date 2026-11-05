// from server: 100% by auto
// roc 2010-06 00424890  unit: ThreadLogManager  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00424890
//
// 00424890  55                   push ebp
// 00424891  8bec                 mov ebp, esp
// 00424893  6aff                 push -1
// 00424895  68daf99700           push 0x97f9da
// 0042489a  64a100000000         mov eax, dword ptr fs:[0]
// 004248a0  50                   push eax
// 004248a1  64892500000000       mov dword ptr fs:[0], esp
// 004248a8  83ec24               sub esp, 0x24
// 004248ab  53                   push ebx
// 004248ac  56                   push esi
// 004248ad  8b7510               mov esi, dword ptr [ebp + 0x10]
// 004248b0  57                   push edi
// 004248b1  8d4dd0               lea ecx, [ebp - 0x30]
// 004248b4  8965f0               mov dword ptr [ebp - 0x10], esp
// 004248b7  8975ec               mov dword ptr [ebp - 0x14], esi
// 004248ba  ff1504a49e00         call dword ptr [0x9ea404]
// 004248c0  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 004248c3  8b7d08               mov edi, dword ptr [ebp + 8]
// 004248c6  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004248cd  8d4900               lea ecx, [ecx]
// 004248d0  3bfb                 cmp edi, ebx
// 004248d2  7454                 je 0x424928
// 004248d4  89750c               mov dword ptr [ebp + 0xc], esi
// 004248d7  897508               mov dword ptr [ebp + 8], esi
// 004248da  c645fc02             mov byte ptr [ebp - 4], 2
// 004248de  85f6                 test esi, esi
// 004248e0  740c                 je 0x4248ee
// 004248e2  8d45d0               lea eax, [ebp - 0x30]
// 004248e5  50                   push eax
// 004248e6  8bce                 mov ecx, esi
// 004248e8  ff150ca49e00         call dword ptr [0x9ea40c]
// 004248ee  57                   push edi
// 004248ef  8bce                 mov ecx, esi
// 004248f1  c645fc01             mov byte ptr [ebp - 4], 1
// 004248f5  ff1580a49e00         call dword ptr [0x9ea480]
// 004248fb  83c61c               add esi, 0x1c
// 004248fe  897510               mov dword ptr [ebp + 0x10], esi
// 00424901  83c71c               add edi, 0x1c
// 00424904  ebca                 jmp 0x4248d0
// standard library vector<string> (function ??$_Uninit_move@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PAV10@00AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Swap_move_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
