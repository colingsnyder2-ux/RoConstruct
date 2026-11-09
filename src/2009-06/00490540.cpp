// from server: 100% by auto
// roc 2009-06 00490540  unit: RBX::MaterialBaseRefMaterialAdapter  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00490540
//
// 00490540  6aff                 push -1
// 00490542  6878ef8600           push 0x86ef78
// 00490547  64a100000000         mov eax, dword ptr fs:[0]
// 0049054d  50                   push eax
// 0049054e  64892500000000       mov dword ptr fs:[0], esp
// 00490555  51                   push ecx
// 00490556  56                   push esi
// 00490557  8bf1                 mov esi, ecx
// 00490559  89742404             mov dword ptr [esp + 4], esi
// 0049055d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00490565  e886ffffff           call 0x4904f0
// 0049056a  8b06                 mov eax, dword ptr [esi]
// 0049056c  50                   push eax
// 0049056d  e8c0842800           call 0x718a32
// 00490572  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00490576  83c404               add esp, 4
// 00490579  5e                   pop esi
// 0049057a  64890d00000000       mov dword ptr fs:[0], ecx
// 00490581  83c410               add esp, 0x10
// 00490584  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
