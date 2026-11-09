// from server: 100% by auto
// roc 2009-06 00484d40  unit: RBX::MeshGen  size: 28 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00484d40
//
// 00484d40  56                   push esi
// 00484d41  57                   push edi
// 00484d42  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00484d46  57                   push edi
// 00484d47  8bf1                 mov esi, ecx
// 00484d49  ff15b8e48900         call dword ptr [0x89e4b8]
// 00484d4f  8b471c               mov eax, dword ptr [edi + 0x1c]
// 00484d52  89461c               mov dword ptr [esi + 0x1c], eax
// 00484d55  5f                   pop edi
// 00484d56  8bc6                 mov eax, esi
// 00484d58  5e                   pop esi
// 00484d59  c20400               ret 4
// standard library map_str<ptr> (function ??0?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@QAE@ABU01@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
