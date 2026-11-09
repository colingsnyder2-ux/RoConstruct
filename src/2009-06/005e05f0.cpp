// from server: 100% by auto
// roc 2009-06 005e05f0  unit: std::D::DU?$char_traits::?$basic_istringstream  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005e05f0
//
// 005e05f0  6aff                 push -1
// 005e05f2  6878ef8600           push 0x86ef78
// 005e05f7  64a100000000         mov eax, dword ptr fs:[0]
// 005e05fd  50                   push eax
// 005e05fe  64892500000000       mov dword ptr fs:[0], esp
// 005e0605  51                   push ecx
// 005e0606  56                   push esi
// 005e0607  8bf1                 mov esi, ecx
// 005e0609  89742404             mov dword ptr [esp + 4], esi
// 005e060d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 005e0615  e806eeffff           call 0x5df420
// 005e061a  8b4614               mov eax, dword ptr [esi + 0x14]
// 005e061d  50                   push eax
// 005e061e  e80f841300           call 0x718a32
// 005e0623  8b0e                 mov ecx, dword ptr [esi]
// 005e0625  51                   push ecx
// 005e0626  c7461400000000       mov dword ptr [esi + 0x14], 0
// 005e062d  e800841300           call 0x718a32
// 005e0632  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005e0636  83c408               add esp, 8
// 005e0639  5e                   pop esi
// 005e063a  64890d00000000       mov dword ptr fs:[0], ecx
// 005e0641  83c410               add esp, 0x10
// 005e0644  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
