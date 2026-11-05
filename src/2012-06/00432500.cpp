// from server: 100% by auto
// roc 2012-06 00432500  unit: ThreadLogManager  size: 118 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00432500
//
// 00432500  55                   push ebp
// 00432501  8bec                 mov ebp, esp
// 00432503  6aff                 push -1
// 00432505  68bacba900           push 0xa9cbba
// 0043250a  64a100000000         mov eax, dword ptr fs:[0]
// 00432510  50                   push eax
// 00432511  64892500000000       mov dword ptr fs:[0], esp
// 00432518  83ec24               sub esp, 0x24
// 0043251b  53                   push ebx
// 0043251c  56                   push esi
// 0043251d  8b7510               mov esi, dword ptr [ebp + 0x10]
// 00432520  57                   push edi
// 00432521  8d4dd0               lea ecx, [ebp - 0x30]
// 00432524  8965f0               mov dword ptr [ebp - 0x10], esp
// 00432527  8975ec               mov dword ptr [ebp - 0x14], esi
// 0043252a  ff155426b200         call dword ptr [0xb22654]
// 00432530  8b5d0c               mov ebx, dword ptr [ebp + 0xc]
// 00432533  8b7d08               mov edi, dword ptr [ebp + 8]
// 00432536  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0043253d  8d4900               lea ecx, [ecx]
// 00432540  3bfb                 cmp edi, ebx
// 00432542  7454                 je 0x432598
// 00432544  89750c               mov dword ptr [ebp + 0xc], esi
// 00432547  897508               mov dword ptr [ebp + 8], esi
// 0043254a  c645fc02             mov byte ptr [ebp - 4], 2
// 0043254e  85f6                 test esi, esi
// 00432550  740c                 je 0x43255e
// 00432552  8d45d0               lea eax, [ebp - 0x30]
// 00432555  50                   push eax
// 00432556  8bce                 mov ecx, esi
// 00432558  ff154426b200         call dword ptr [0xb22644]
// 0043255e  57                   push edi
// 0043255f  8bce                 mov ecx, esi
// 00432561  c645fc01             mov byte ptr [ebp - 4], 1
// 00432565  ff15fc26b200         call dword ptr [0xb226fc]
// 0043256b  83c61c               add esi, 0x1c
// 0043256e  897510               mov dword ptr [ebp + 0x10], esi
// 00432571  83c71c               add edi, 0x1c
// 00432574  ebca                 jmp 0x432540
// standard library vector<string> (function ??$_Uninit_move@PAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAV12@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@YAPAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@0@PAV10@00AAV?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@0@U_Swap_move_tag@0@U_Range_checked_iterator_tag@0@@Z)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
