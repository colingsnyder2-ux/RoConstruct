// from server: 100% by auto
// roc 2009-06 00418380  unit: RBX::VTool::?$FactoryProduct::Creator  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00418380
//
// 00418380  6aff                 push -1
// 00418382  6878ef8600           push 0x86ef78
// 00418387  64a100000000         mov eax, dword ptr fs:[0]
// 0041838d  50                   push eax
// 0041838e  64892500000000       mov dword ptr fs:[0], esp
// 00418395  51                   push ecx
// 00418396  56                   push esi
// 00418397  8bf1                 mov esi, ecx
// 00418399  89742404             mov dword ptr [esp + 4], esi
// 0041839d  c744241000000000     mov dword ptr [esp + 0x10], 0
// 004183a5  e826feffff           call 0x4181d0
// 004183aa  8b06                 mov eax, dword ptr [esi]
// 004183ac  50                   push eax
// 004183ad  e880063000           call 0x718a32
// 004183b2  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004183b6  83c404               add esp, 4
// 004183b9  5e                   pop esi
// 004183ba  64890d00000000       mov dword ptr fs:[0], ecx
// 004183c1  83c410               add esp, 0x10
// 004183c4  c3                   ret 
// standard library vector<string> (function ??1?$vector@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAE@XZ)

// stl: vector<string>
#include <string>
typedef std::string E;
#include <vector>
template class std::vector<E>;
