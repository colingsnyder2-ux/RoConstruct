// from server: 100% by auto
// roc 2009-06 005dafc0  unit: RBX::VInstance::?$NonFactoryProduct  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005dafc0
//
// 005dafc0  56                   push esi
// 005dafc1  57                   push edi
// 005dafc2  8bf9                 mov edi, ecx
// 005dafc4  8b4714               mov eax, dword ptr [edi + 0x14]
// 005dafc7  8b30                 mov esi, dword ptr [eax]
// 005dafc9  8900                 mov dword ptr [eax], eax
// 005dafcb  8b4714               mov eax, dword ptr [edi + 0x14]
// 005dafce  894004               mov dword ptr [eax + 4], eax
// 005dafd1  c7471800000000       mov dword ptr [edi + 0x18], 0
// 005dafd8  3b7714               cmp esi, dword ptr [edi + 0x14]
// 005dafdb  741f                 je 0x5daffc
// 005dafdd  53                   push ebx
// 005dafde  8bff                 mov edi, edi
// 005dafe0  8b1e                 mov ebx, dword ptr [esi]
// 005dafe2  8d4e08               lea ecx, [esi + 8]
// 005dafe5  ff15c4e48900         call dword ptr [0x89e4c4]
// 005dafeb  56                   push esi
// 005dafec  e841da1300           call 0x718a32
// 005daff1  83c404               add esp, 4
// 005daff4  8bf3                 mov esi, ebx
// 005daff6  3b5f14               cmp ebx, dword ptr [edi + 0x14]
// 005daff9  75e5                 jne 0x5dafe0
// 005daffb  5b                   pop ebx
// 005daffc  5f                   pop edi
// 005daffd  5e                   pop esi
// 005daffe  c3                   ret 
// standard library list<string> (function ?clear@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXXZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
