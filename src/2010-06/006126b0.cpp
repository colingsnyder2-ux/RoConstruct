// from server: 100% by auto
// roc 2010-06 006126b0  unit: RBX::VScriptContext::?$FactoryProduct  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 006126b0
//
// 006126b0  6aff                 push -1
// 006126b2  6858a29900           push 0x99a258
// 006126b7  64a100000000         mov eax, dword ptr fs:[0]
// 006126bd  50                   push eax
// 006126be  64892500000000       mov dword ptr fs:[0], esp
// 006126c5  51                   push ecx
// 006126c6  56                   push esi
// 006126c7  8bf1                 mov esi, ecx
// 006126c9  89742404             mov dword ptr [esp + 4], esi
// 006126cd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 006126d5  e8f6f6ffff           call 0x611dd0
// 006126da  8b06                 mov eax, dword ptr [esi]
// 006126dc  50                   push eax
// 006126dd  e8b8521900           call 0x7a799a
// 006126e2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006126e6  83c404               add esp, 4
// 006126e9  5e                   pop esi
// 006126ea  64890d00000000       mov dword ptr fs:[0], ecx
// 006126f1  83c410               add esp, 0x10
// 006126f4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
