// from server: 100% by auto
// roc 2008-06 0055dfd0  unit: RBX::VInstance::?$NonFactoryProduct  size: 63 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055dfd0
//
// 0055dfd0  56                   push esi
// 0055dfd1  57                   push edi
// 0055dfd2  8bf9                 mov edi, ecx
// 0055dfd4  8b4714               mov eax, dword ptr [edi + 0x14]
// 0055dfd7  8b30                 mov esi, dword ptr [eax]
// 0055dfd9  8900                 mov dword ptr [eax], eax
// 0055dfdb  8b4714               mov eax, dword ptr [edi + 0x14]
// 0055dfde  894004               mov dword ptr [eax + 4], eax
// 0055dfe1  c7471800000000       mov dword ptr [edi + 0x18], 0
// 0055dfe8  3b7714               cmp esi, dword ptr [edi + 0x14]
// 0055dfeb  741f                 je 0x55e00c
// 0055dfed  53                   push ebx
// 0055dfee  8bff                 mov edi, edi
// 0055dff0  8b1e                 mov ebx, dword ptr [esi]
// 0055dff2  8d4e08               lea ecx, [esi + 8]
// 0055dff5  ff1568248000         call dword ptr [0x802468]
// 0055dffb  56                   push esi
// 0055dffc  e879261400           call 0x6a067a
// 0055e001  83c404               add esp, 4
// 0055e004  8bf3                 mov esi, ebx
// 0055e006  3b5f14               cmp ebx, dword ptr [edi + 0x14]
// 0055e009  75e5                 jne 0x55dff0
// 0055e00b  5b                   pop ebx
// 0055e00c  5f                   pop edi
// 0055e00d  5e                   pop esi
// 0055e00e  c3                   ret 
// standard library list<string> (function ?clear@?$list@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@@std@@QAEXXZ)

// stl: list<string>
#include <string>
typedef std::string E;
#include <list>
template class std::list<E>;
