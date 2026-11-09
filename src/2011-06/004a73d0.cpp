// from server: 100% by auto
// roc 2011-06 004a73d0  unit: RBX::Reflection::VDescribedBase::V?$shared_ptr::?$holder  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004a73d0
//
// 004a73d0  55                   push ebp
// 004a73d1  8bec                 mov ebp, esp
// 004a73d3  6aff                 push -1
// 004a73d5  68417e9d00           push 0x9d7e41
// 004a73da  64a100000000         mov eax, dword ptr fs:[0]
// 004a73e0  50                   push eax
// 004a73e1  64892500000000       mov dword ptr fs:[0], esp
// 004a73e8  83ec0c               sub esp, 0xc
// 004a73eb  53                   push ebx
// 004a73ec  56                   push esi
// 004a73ed  8b7510               mov esi, dword ptr [ebp + 0x10]
// 004a73f0  57                   push edi
// 004a73f1  8b7d08               mov edi, dword ptr [ebp + 8]
// 004a73f4  33db                 xor ebx, ebx
// 004a73f6  8965f0               mov dword ptr [ebp - 0x10], esp
// 004a73f9  8975ec               mov dword ptr [ebp - 0x14], esi
// 004a73fc  895dfc               mov dword ptr [ebp - 4], ebx
// 004a73ff  90                   nop 
// 004a7400  3b7d0c               cmp edi, dword ptr [ebp + 0xc]
// 004a7403  7447                 je 0x4a744c
// 004a7405  897508               mov dword ptr [ebp + 8], esi
// 004a7408  8975e8               mov dword ptr [ebp - 0x18], esi
// 004a740b  c645fc01             mov byte ptr [ebp - 4], 1
// 004a740f  3bf3                 cmp esi, ebx
// 004a7411  7409                 je 0x4a741c
// 004a7413  57                   push edi
// 004a7414  8bce                 mov ecx, esi
// 004a7416  ff15c804a400         call dword ptr [0xa404c8]
// 004a741c  83c61c               add esi, 0x1c
// 004a741f  885dfc               mov byte ptr [ebp - 4], bl
// 004a7422  897510               mov dword ptr [ebp + 0x10], esi
// 004a7425  83c71c               add edi, 0x1c
// 004a7428  ebd6                 jmp 0x4a7400
// standard library vector<string> (function ??$_Uninit_copy@PBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PBV10@0PAV10@AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
