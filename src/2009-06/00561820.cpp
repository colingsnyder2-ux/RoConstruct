// from server: 100% by auto
// roc 2009-06 00561820  unit: RBX::Mesh::Level  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00561820
//
// 00561820  8b442404             mov eax, dword ptr [esp + 4]
// 00561824  56                   push esi
// 00561825  50                   push eax
// 00561826  8bf1                 mov esi, ecx
// 00561828  e853feffff           call 0x561680
// 0056182d  c70600a78c00         mov dword ptr [esi], 0x8ca700
// 00561833  8bc6                 mov eax, esi
// 00561835  5e                   pop esi
// 00561836  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
