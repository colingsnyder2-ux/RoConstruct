// from server: 100% by auto
// roc 2008-06 0055e5f0  unit: RBX::MD5HasherImpl  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055e5f0
//
// 0055e5f0  6aff                 push -1
// 0055e5f2  68e8727d00           push 0x7d72e8
// 0055e5f7  64a100000000         mov eax, dword ptr fs:[0]
// 0055e5fd  50                   push eax
// 0055e5fe  64892500000000       mov dword ptr fs:[0], esp
// 0055e605  51                   push ecx
// 0055e606  56                   push esi
// 0055e607  8bf1                 mov esi, ecx
// 0055e609  89742404             mov dword ptr [esp + 4], esi
// 0055e60d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0055e615  e8b6f9ffff           call 0x55dfd0
// 0055e61a  8b4614               mov eax, dword ptr [esi + 0x14]
// 0055e61d  50                   push eax
// 0055e61e  e857201400           call 0x6a067a
// 0055e623  8b0e                 mov ecx, dword ptr [esi]
// 0055e625  51                   push ecx
// 0055e626  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0055e62d  e848201400           call 0x6a067a
// 0055e632  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0055e636  83c408               add esp, 8
// 0055e639  5e                   pop esi
// 0055e63a  64890d00000000       mov dword ptr fs:[0], ecx
// 0055e641  83c410               add esp, 0x10
// 0055e644  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
