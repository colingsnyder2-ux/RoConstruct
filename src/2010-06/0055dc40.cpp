// from server: 100% by auto
// roc 2010-06 0055dc40  unit: G3D::TextInput::WrongSymbol  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0055dc40
//
// 0055dc40  8b442404             mov eax, dword ptr [esp + 4]
// 0055dc44  56                   push esi
// 0055dc45  50                   push eax
// 0055dc46  8bf1                 mov esi, ecx
// 0055dc48  e883ffffff           call 0x55dbd0
// 0055dc4d  c7060c0ba200         mov dword ptr [esi], 0xa20b0c
// 0055dc53  8bc6                 mov eax, esi
// 0055dc55  5e                   pop esi
// 0055dc56  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
