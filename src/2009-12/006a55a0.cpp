// from server: 100% by auto
// roc 2009-12 006a55a0  unit: RBX::VScriptContext::?$FactoryProduct  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006a55a0
//
// 006a55a0  6aff                 push -1
// 006a55a2  68d8c59300           push 0x93c5d8
// 006a55a7  64a100000000         mov eax, dword ptr fs:[0]
// 006a55ad  50                   push eax
// 006a55ae  64892500000000       mov dword ptr fs:[0], esp
// 006a55b5  51                   push ecx
// 006a55b6  56                   push esi
// 006a55b7  8bf1                 mov esi, ecx
// 006a55b9  89742404             mov dword ptr [esp + 4], esi
// 006a55bd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006a55c5  e8c6faffff           call 0x6a5090
// 006a55ca  8b06                 mov eax, dword ptr [esi]
// 006a55cc  50                   push eax
// 006a55cd  e888e21400           call 0x7f385a
// 006a55d2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006a55d6  83c404               add esp, 4
// 006a55d9  5e                   pop esi
// 006a55da  64890d00000000       mov dword ptr fs:[0], ecx
// 006a55e1  83c410               add esp, 0x10
// 006a55e4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
