// from server: 100% by auto
// roc 2008-06 005179b0  unit: G3D::TextInput::WrongSymbol  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005179b0
//
// 005179b0  8b442404             mov eax, dword ptr [esp + 4]
// 005179b4  56                   push esi
// 005179b5  50                   push eax
// 005179b6  8bf1                 mov esi, ecx
// 005179b8  e883ffffff           call 0x517940
// 005179bd  c706848a8200         mov dword ptr [esi], 0x828a84
// 005179c3  8bc6                 mov eax, esi
// 005179c5  5e                   pop esi
// 005179c6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
