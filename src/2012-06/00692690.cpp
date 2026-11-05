// from server: 100% by auto
// roc 2012-06 00692690  unit: RBX::VModelInstance::?$BoundFuncDesc  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00692690
//
// 00692690  56                   push esi
// 00692691  57                   push edi
// 00692692  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00692696  57                   push edi
// 00692697  8bf1                 mov esi, ecx
// 00692699  ff154426b200         call dword ptr [0xb22644]
// 0069269f  8b471c               mov eax, dword ptr [edi + 0x1c]
// 006926a2  89461c               mov dword ptr [esi + 0x1c], eax
// 006926a5  5f                   pop edi
// 006926a6  8bc6                 mov eax, esi
// 006926a8  5e                   pop esi
// 006926a9  c20400               ret 4
// standard library map_str<ptr> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@QAE@ABU01@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
