// from server: 100% by auto
// roc 2012-06 0077eae0  unit: RBX::N$E?sDoubleConstrainedValue::V?$ConstrainedValue::?$FactoryProduct  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0077eae0
//
// 0077eae0  6aff                 push -1
// 0077eae2  681890ad00           push 0xad9018
// 0077eae7  64a100000000         mov eax, dword ptr fs:[0]
// 0077eaed  50                   push eax
// 0077eaee  64892500000000       mov dword ptr fs:[0], esp
// 0077eaf5  51                   push ecx
// 0077eaf6  56                   push esi
// 0077eaf7  8bf1                 mov esi, ecx
// 0077eaf9  89742404             mov dword ptr [esp + 4], esi
// 0077eafd  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0077eb05  e826c2ffff           call 0x77ad30
// 0077eb0a  8b06                 mov eax, dword ptr [esi]
// 0077eb0c  50                   push eax
// 0077eb0d  e802362000           call 0x982114
// 0077eb12  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0077eb16  83c404               add esp, 4
// 0077eb19  5e                   pop esi
// 0077eb1a  64890d00000000       mov dword ptr fs:[0], ecx
// 0077eb21  83c410               add esp, 0x10
// 0077eb24  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
