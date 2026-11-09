// from server: 100% by auto
// roc 2009-06 00561b70  unit: RBX::VBeveledBlockMesh::?$CustomizableMesh  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00561b70
//
// 00561b70  8b442404             mov eax, dword ptr [esp + 4]
// 00561b74  56                   push esi
// 00561b75  50                   push eax
// 00561b76  8bf1                 mov esi, ecx
// 00561b78  e853feffff           call 0x5619d0
// 00561b7d  c7061ca78c00         mov dword ptr [esi], 0x8ca71c
// 00561b83  8bc6                 mov eax, esi
// 00561b85  5e                   pop esi
// 00561b86  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
