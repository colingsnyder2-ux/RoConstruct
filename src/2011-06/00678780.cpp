// from server: 100% by auto
// roc 2011-06 00678780  unit: RBX::Animation  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00678780
//
// 00678780  56                   push esi
// 00678781  57                   push edi
// 00678782  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00678786  57                   push edi
// 00678787  8bf1                 mov esi, ecx
// 00678789  ff15a804a400         call dword ptr [0xa404a8]
// 0067878f  8b471c               mov eax, dword ptr [edi + 0x1c]
// 00678792  89461c               mov dword ptr [esi + 0x1c], eax
// 00678795  5f                   pop edi
// 00678796  8bc6                 mov eax, esi
// 00678798  5e                   pop esi
// 00678799  c20400               ret 4
// standard library map_str<ptr> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@QAE@ABU01@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
