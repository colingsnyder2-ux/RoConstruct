// from server: 100% by auto
// roc 2009-06 004b5e00  unit: RBX::Reflection::_N::?$TypedPropertyDescriptor  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004b5e00
//
// 004b5e00  55                   push ebp
// 004b5e01  8bec                 mov ebp, esp
// 004b5e03  6aff                 push -1
// 004b5e05  68118c8500           push 0x858c11
// 004b5e0a  64a100000000         mov eax, dword ptr fs:[0]
// 004b5e10  50                   push eax
// 004b5e11  64892500000000       mov dword ptr fs:[0], esp
// 004b5e18  83ec0c               sub esp, 0xc
// 004b5e1b  53                   push ebx
// 004b5e1c  56                   push esi
// 004b5e1d  8b7510               mov esi, dword ptr [ebp + 0x10]
// 004b5e20  57                   push edi
// 004b5e21  8b7d08               mov edi, dword ptr [ebp + 8]
// 004b5e24  33db                 xor ebx, ebx
// 004b5e26  8965f0               mov dword ptr [ebp - 0x10], esp
// 004b5e29  8975ec               mov dword ptr [ebp - 0x14], esi
// 004b5e2c  895dfc               mov dword ptr [ebp - 4], ebx
// 004b5e2f  90                   nop 
// 004b5e30  3b7d0c               cmp edi, dword ptr [ebp + 0xc]
// 004b5e33  7447                 je 0x4b5e7c
// 004b5e35  897508               mov dword ptr [ebp + 8], esi
// 004b5e38  8975e8               mov dword ptr [ebp - 0x18], esi
// 004b5e3b  c645fc01             mov byte ptr [ebp - 4], 1
// 004b5e3f  3bf3                 cmp esi, ebx
// 004b5e41  7409                 je 0x4b5e4c
// 004b5e43  57                   push edi
// 004b5e44  8bce                 mov ecx, esi
// 004b5e46  ff15b8e48900         call dword ptr [0x89e4b8]
// 004b5e4c  83c61c               add esi, 0x1c
// 004b5e4f  885dfc               mov byte ptr [ebp - 4], bl
// 004b5e52  897510               mov dword ptr [ebp + 0x10], esi
// 004b5e55  83c71c               add edi, 0x1c
// 004b5e58  ebd6                 jmp 0x4b5e30
// standard library vector<string> (function ??$_Uninit_copy@PBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PBV10@0PAV10@AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
