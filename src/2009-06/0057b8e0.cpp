// from server: 100% by auto
// roc 2009-06 0057b8e0  unit: G3D::TextInput::WrongSymbol  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0057b8e0
//
// 0057b8e0  8b442404             mov eax, dword ptr [esp + 4]
// 0057b8e4  56                   push esi
// 0057b8e5  50                   push eax
// 0057b8e6  8bf1                 mov esi, ecx
// 0057b8e8  e883ffffff           call 0x57b870
// 0057b8ed  c70674bf8c00         mov dword ptr [esi], 0x8cbf74
// 0057b8f3  8bc6                 mov eax, esi
// 0057b8f5  5e                   pop esi
// 0057b8f6  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
