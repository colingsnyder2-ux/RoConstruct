// from server: 100% by auto
// roc 2007-08 00428950  unit: COleException  size: 134 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00428950
//
// 00428950  55                   push ebp
// 00428951  8bec                 mov ebp, esp
// 00428953  6aff                 push -1
// 00428955  68aacb7300           push 0x73cbaa
// 0042895a  64a100000000         mov eax, dword ptr fs:[0]
// 00428960  50                   push eax
// 00428961  83ec34               sub esp, 0x34
// 00428964  a188518b00           mov eax, dword ptr [0x8b5188]
// 00428969  33c5                 xor eax, ebp
// 0042896b  8945ec               mov dword ptr [ebp - 0x14], eax
// 0042896e  53                   push ebx
// 0042896f  56                   push esi
// 00428970  57                   push edi
// 00428971  50                   push eax
// 00428972  8d45f4               lea eax, [ebp - 0xc]
// 00428975  64a300000000         mov dword ptr fs:[0], eax
// 0042897b  8965f0               mov dword ptr [ebp - 0x10], esp
// 0042897e  8b7510               mov esi, dword ptr [ebp + 0x10]
// 00428981  8b7d08               mov edi, dword ptr [ebp + 8]
// 00428984  8d4dd0               lea ecx, [ebp - 0x30]
// 00428987  8975cc               mov dword ptr [ebp - 0x34], esi
// 0042898a  8975c8               mov dword ptr [ebp - 0x38], esi
// 0042898d  ff15a4e67700         call dword ptr [0x77e6a4]
// 00428993  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 00428996  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0042899d  8d4900               lea ecx, [ecx]
// 004289a0  3bfb                 cmp edi, ebx
// 004289a2  7454                 je 0x4289f8
// 004289a4  8975c4               mov dword ptr [ebp - 0x3c], esi
// 004289a7  8975c0               mov dword ptr [ebp - 0x40], esi
// 004289aa  85f6                 test esi, esi
// 004289ac  c645fc02             mov byte ptr [ebp - 4], 2
// 004289b0  740c                 je 0x4289be
// 004289b2  8d45d0               lea eax, [ebp - 0x30]
// 004289b5  50                   push eax
// 004289b6  8bce                 mov ecx, esi
// 004289b8  ff159ce67700         call dword ptr [0x77e69c]
// 004289be  57                   push edi
// 004289bf  8bce                 mov ecx, esi
// 004289c1  c645fc01             mov byte ptr [ebp - 4], 1
// 004289c5  ff1548e67700         call dword ptr [0x77e648]
// 004289cb  83c61c               add esi, 0x1c
// 004289ce  8975cc               mov dword ptr [ebp - 0x34], esi
// 004289d1  83c71c               add edi, 0x1c
// 004289d4  ebca                 jmp 0x4289a0
// standard library vector<string> (function ??$_Uninit_move@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PAV10@00AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Swap_move_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
