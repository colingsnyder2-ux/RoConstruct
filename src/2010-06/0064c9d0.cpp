// from server: 100% by auto
// roc 2010-06 0064c9d0  unit: RBX::VWidget::?$NonFactoryProduct  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0064c9d0
//
// 0064c9d0  6aff                 push -1
// 0064c9d2  6858a29900           push 0x99a258
// 0064c9d7  64a100000000         mov eax, dword ptr fs:[0]
// 0064c9dd  50                   push eax
// 0064c9de  64892500000000       mov dword ptr fs:[0], esp
// 0064c9e5  51                   push ecx
// 0064c9e6  56                   push esi
// 0064c9e7  8bf1                 mov esi, ecx
// 0064c9e9  89742404             mov dword ptr [esp + 4], esi
// 0064c9ed  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0064c9f5  e8c6f8ffff           call 0x64c2c0
// 0064c9fa  8b4614               mov eax, dword ptr [esi + 0x14]
// 0064c9fd  50                   push eax
// 0064c9fe  e897af1500           call 0x7a799a
// 0064ca03  8b0e                 mov ecx, dword ptr [esi]
// 0064ca05  51                   push ecx
// 0064ca06  c7461400000000       mov dword ptr [esi + 0x14], 0
// 0064ca0d  e888af1500           call 0x7a799a
// 0064ca12  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0064ca16  83c408               add esp, 8
// 0064ca19  5e                   pop esi
// 0064ca1a  64890d00000000       mov dword ptr fs:[0], ecx
// 0064ca21  83c410               add esp, 0x10
// 0064ca24  c3                   ret 
// standard library list<string> (function ??1?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
