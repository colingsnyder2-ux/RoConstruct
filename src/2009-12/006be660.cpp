// from server: 100% by auto
// roc 2009-12 006be660  unit: RBX::VInstance::?$NonFactoryProduct  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 006be660
//
// 006be660  56                   push esi
// 006be661  57                   push edi
// 006be662  8bf9                 mov edi, ecx
// 006be664  8b4714               mov eax, dword ptr [edi + 0x14]
// 006be667  8b30                 mov esi, dword ptr [eax]
// 006be669  8900                 mov dword ptr [eax], eax
// 006be66b  8b4714               mov eax, dword ptr [edi + 0x14]
// 006be66e  894004               mov dword ptr [eax + 4], eax
// 006be671  c7471800000000       mov dword ptr [edi + 0x18], 0
// 006be678  3b7714               cmp esi, dword ptr [edi + 0x14]
// 006be67b  741f                 je 0x6be69c
// 006be67d  53                   push ebx
// 006be67e  8bff                 mov edi, edi
// 006be680  8b1e                 mov ebx, dword ptr [esi]
// 006be682  8d4e08               lea ecx, [esi + 8]
// 006be685  ff15e4b69800         call dword ptr [0x98b6e4]
// 006be68b  56                   push esi
// 006be68c  e8c9511300           call 0x7f385a
// 006be691  83c404               add esp, 4
// 006be694  8bf3                 mov esi, ebx
// 006be696  3b5f14               cmp ebx, dword ptr [edi + 0x14]
// 006be699  75e5                 jne 0x6be680
// 006be69b  5b                   pop ebx
// 006be69c  5f                   pop edi
// 006be69d  5e                   pop esi
// 006be69e  c3                   ret 
// standard library list<string> (function ?clear@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXXZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
