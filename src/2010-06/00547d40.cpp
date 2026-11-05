// from server: 100% by auto
// roc 2010-06 00547d40  unit: RBX::RbxG3D::Material  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00547d40
//
// 00547d40  8b442404             mov eax, dword ptr [esp + 4]
// 00547d44  56                   push esi
// 00547d45  50                   push eax
// 00547d46  8bf1                 mov esi, ecx
// 00547d48  e853feffff           call 0x547ba0
// 00547d4d  c70604f4a100         mov dword ptr [esi], 0xa1f404
// 00547d53  8bc6                 mov eax, esi
// 00547d55  5e                   pop esi
// 00547d56  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
