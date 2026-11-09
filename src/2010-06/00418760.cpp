// from server: 100% by auto
// roc 2010-06 00418760  unit: RBX::VTool::?$FactoryProduct::Creator  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00418760
//
// 00418760  6aff                 push -1
// 00418762  6858a29900           push 0x99a258
// 00418767  64a100000000         mov eax, dword ptr fs:[0]
// 0041876d  50                   push eax
// 0041876e  64892500000000       mov dword ptr fs:[0], esp
// 00418775  51                   push ecx
// 00418776  56                   push esi
// 00418777  8bf1                 mov esi, ecx
// 00418779  89742404             mov dword ptr [esp + 4], esi
// 0041877d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00418785  e826feffff           call 0x4185b0
// 0041878a  8b06                 mov eax, dword ptr [esi]
// 0041878c  50                   push eax
// 0041878d  e808f23800           call 0x7a799a
// 00418792  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00418796  83c404               add esp, 4
// 00418799  5e                   pop esi
// 0041879a  64890d00000000       mov dword ptr fs:[0], ecx
// 004187a1  83c410               add esp, 0x10
// 004187a4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
