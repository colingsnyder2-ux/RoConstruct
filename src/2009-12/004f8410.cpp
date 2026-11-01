// from server: 100% by auto
// roc 2009-12 004f8410  unit: RBX::VBrickColor::?$holder  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004f8410
//
// 004f8410  55                   push ebp
// 004f8411  8bec                 mov ebp, esp
// 004f8413  6aff                 push -1
// 004f8415  68015b9300           push 0x935b01
// 004f841a  64a100000000         mov eax, dword ptr fs:[0]
// 004f8420  50                   push eax
// 004f8421  64892500000000       mov dword ptr fs:[0], esp
// 004f8428  83ec0c               sub esp, 0xc
// 004f842b  53                   push ebx
// 004f842c  56                   push esi
// 004f842d  8b7510               mov esi, dword ptr [ebp + 0x10]
// 004f8430  57                   push edi
// 004f8431  8b7d08               mov edi, dword ptr [ebp + 8]
// 004f8434  33db                 xor ebx, ebx
// 004f8436  8965f0               mov dword ptr [ebp - 0x10], esp
// 004f8439  8975ec               mov dword ptr [ebp - 0x14], esi
// 004f843c  895dfc               mov dword ptr [ebp - 4], ebx
// 004f843f  90                   nop 
// 004f8440  3b7d0c               cmp edi, dword ptr [ebp + 0xc]
// 004f8443  7447                 je 0x4f848c
// 004f8445  897508               mov dword ptr [ebp + 8], esi
// 004f8448  8975e8               mov dword ptr [ebp - 0x18], esi
// 004f844b  c645fc01             mov byte ptr [ebp - 4], 1
// 004f844f  3bf3                 cmp esi, ebx
// 004f8451  7409                 je 0x4f845c
// 004f8453  57                   push edi
// 004f8454  8bce                 mov ecx, esi
// 004f8456  ff15f0b69800         call dword ptr [0x98b6f0]
// 004f845c  83c61c               add esi, 0x1c
// 004f845f  885dfc               mov byte ptr [ebp - 4], bl
// 004f8462  897510               mov dword ptr [ebp + 0x10], esi
// 004f8465  83c71c               add edi, 0x1c
// 004f8468  ebd6                 jmp 0x4f8440
// standard library vector<string> (function ??$_Uninit_copy@PBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PBV10@0PAV10@AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
