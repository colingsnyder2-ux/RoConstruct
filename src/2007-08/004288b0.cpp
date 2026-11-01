// from server: 100% by auto
// roc 2007-08 004288b0  unit: COleException  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004288b0
//
// 004288b0  55                   push ebp
// 004288b1  8bec                 mov ebp, esp
// 004288b3  6aff                 push -1
// 004288b5  6871cb7300           push 0x73cb71
// 004288ba  64a100000000         mov eax, dword ptr fs:[0]
// 004288c0  50                   push eax
// 004288c1  83ec0c               sub esp, 0xc
// 004288c4  53                   push ebx
// 004288c5  56                   push esi
// 004288c6  57                   push edi
// 004288c7  a188518b00           mov eax, dword ptr [0x8b5188]
// 004288cc  33c5                 xor eax, ebp
// 004288ce  50                   push eax
// 004288cf  8d45f4               lea eax, [ebp - 0xc]
// 004288d2  64a300000000         mov dword ptr fs:[0], eax
// 004288d8  8965f0               mov dword ptr [ebp - 0x10], esp
// 004288db  8b7510               mov esi, dword ptr [ebp + 0x10]
// 004288de  8b7d08               mov edi, dword ptr [ebp + 8]
// 004288e1  33db                 xor ebx, ebx
// 004288e3  8975ec               mov dword ptr [ebp - 0x14], esi
// 004288e6  895dfc               mov dword ptr [ebp - 4], ebx
// 004288e9  8da42400000000       lea esp, [esp]
// 004288f0  3b7d0c               cmp edi, dword ptr [ebp + 0xc]
// 004288f3  7447                 je 0x42893c
// 004288f5  897508               mov dword ptr [ebp + 8], esi
// 004288f8  8975e8               mov dword ptr [ebp - 0x18], esi
// 004288fb  3bf3                 cmp esi, ebx
// 004288fd  c645fc01             mov byte ptr [ebp - 4], 1
// 00428901  7409                 je 0x42890c
// 00428903  57                   push edi
// 00428904  8bce                 mov ecx, esi
// 00428906  ff159ce67700         call dword ptr [0x77e69c]
// 0042890c  83c61c               add esi, 0x1c
// 0042890f  885dfc               mov byte ptr [ebp - 4], bl
// 00428912  897510               mov dword ptr [ebp + 0x10], esi
// 00428915  83c71c               add edi, 0x1c
// 00428918  ebd6                 jmp 0x4288f0
// standard library vector<string> (function ??$_Uninit_copy@PBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PBV10@0PAV10@AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Nonscalar_ptr_iterator_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
