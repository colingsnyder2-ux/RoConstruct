// from server: 100% by auto
// roc 2007-08 0050e7f0  unit: G3D::TextInput::WrongSymbol  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0050e7f0
//
// 0050e7f0  8b442404             mov eax, dword ptr [esp + 4]
// 0050e7f4  56                   push esi
// 0050e7f5  50                   push eax
// 0050e7f6  8bf1                 mov esi, ecx
// 0050e7f8  e873ffffff           call 0x50e770
// 0050e7fd  c706b40d7a00         mov dword ptr [esi], 0x7a0db4
// 0050e803  8bc6                 mov eax, esi
// 0050e805  5e                   pop esi
// 0050e806  c20400               ret 4
// standard library vector<ptr> (function ??0invalid_argument@std@@QAE@ABV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@@Z)

// stl: vector<ptr>
struct T; typedef T* E;
#include <vector>
template class std::vector<E>;
