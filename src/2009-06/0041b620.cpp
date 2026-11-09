// from server: 100% by auto
// roc 2009-06 0041b620  unit: RBX::VInstance::$$A6AXV?$shared_ptr::?$signal::slot  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0041b620
//
// 0041b620  6aff                 push -1
// 0041b622  6878ef8600           push 0x86ef78
// 0041b627  64a100000000         mov eax, dword ptr fs:[0]
// 0041b62d  50                   push eax
// 0041b62e  64892500000000       mov dword ptr fs:[0], esp
// 0041b635  51                   push ecx
// 0041b636  56                   push esi
// 0041b637  8bf1                 mov esi, ecx
// 0041b639  89742404             mov dword ptr [esp + 4], esi
// 0041b63d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 0041b645  e8e6fbffff           call 0x41b230
// 0041b64a  8b06                 mov eax, dword ptr [esi]
// 0041b64c  50                   push eax
// 0041b64d  e8e0d32f00           call 0x718a32
// 0041b652  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0041b656  83c404               add esp, 4
// 0041b659  5e                   pop esi
// 0041b65a  64890d00000000       mov dword ptr fs:[0], ecx
// 0041b661  83c410               add esp, 0x10
// 0041b664  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
