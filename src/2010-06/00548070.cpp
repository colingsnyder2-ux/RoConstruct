// from server: 100% by auto
// roc 2010-06 00548070  unit: RBX::RbxG3D::Material  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00548070
//
// 00548070  8b442404             mov eax, dword ptr [esp + 4]
// 00548074  56                   push esi
// 00548075  50                   push eax
// 00548076  8bf1                 mov esi, ecx
// 00548078  e853feffff           call 0x547ed0
// 0054807d  c7061cf4a100         mov dword ptr [esi], 0xa1f41c
// 00548083  8bc6                 mov eax, esi
// 00548085  5e                   pop esi
// 00548086  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
