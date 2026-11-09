// from server: 100% by auto
// roc 2008-06 0058f5d0  unit: TextXmlWriterWithEmbeddedContent  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0058f5d0
//
// 0058f5d0  6aff                 push -1
// 0058f5d2  64a100000000         mov eax, dword ptr fs:[0]
// 0058f5d8  68111a7d00           push 0x7d1a11
// 0058f5dd  50                   push eax
// 0058f5de  64892500000000       mov dword ptr fs:[0], esp
// 0058f5e5  83ec5c               sub esp, 0x5c
// 0058f5e8  53                   push ebx
// 0058f5e9  8b5c2470             mov ebx, dword ptr [esp + 0x70]
// 0058f5ed  55                   push ebp
// 0058f5ee  56                   push esi
// 0058f5ef  57                   push edi
// 0058f5f0  53                   push ebx
// 0058f5f1  8bf9                 mov edi, ecx
// 0058f5f3  e8a8e0ffff           call 0x58d6a0
// 0058f5f8  8be8                 mov ebp, eax
// 0058f5fa  85ff                 test edi, edi
// 0058f5fc  7506                 jne 0x58f604
// 0058f5fe  ff1590288000         call dword ptr [0x802890]
// 0058f604  8b37                 mov esi, dword ptr [edi]
// 0058f606  8b4718               mov eax, dword ptr [edi + 0x18]
// 0058f609  89442414             mov dword ptr [esp + 0x14], eax
// 0058f60d  85f6                 test esi, esi
// 0058f60f  7404                 je 0x58f615
// 0058f611  3bf6                 cmp esi, esi
// 0058f613  7406                 je 0x58f61b
// 0058f615  ff1590288000         call dword ptr [0x802890]
// 0058f61b  3b6c2414             cmp ebp, dword ptr [esp + 0x14]
// 0058f61f  7412                 je 0x58f633
// 0058f621  8d4d0c               lea ecx, [ebp + 0xc]
// 0058f624  51                   push ecx
// 0058f625  53                   push ebx
// 0058f626  ff155c238000         call dword ptr [0x80235c]
// 0058f62c  83c408               add esp, 8
// 0058f62f  84c0                 test al, al
// 0058f631  7459                 je 0x58f68c
// 0058f633  8d4c2418             lea ecx, [esp + 0x18]
// 0058f637  ff1560248000         call dword ptr [0x802460]
// 0058f63d  50                   push eax
// 0058f63e  53                   push ebx
// 0058f63f  8d4c243c             lea ecx, [esp + 0x3c]
// 0058f643  c744247c00000000     mov dword ptr [esp + 0x7c], 0
// 0058f64b  e8a0ddffff           call 0x58d3f0
// 0058f650  50                   push eax
// 0058f651  55                   push ebp
// 0058f652  56                   push esi
// 0058f653  8d54241c             lea edx, [esp + 0x1c]
// 0058f657  52                   push edx
// 0058f658  8bcf                 mov ecx, edi
// 0058f65a  c684248400000001     mov byte ptr [esp + 0x84], 1
// 0058f662  e889f9ffff           call 0x58eff0
// 0058f667  8b30                 mov esi, dword ptr [eax]
// 0058f669  8b6804               mov ebp, dword ptr [eax + 4]
// 0058f66c  8d4c2434             lea ecx, [esp + 0x34]
// 0058f670  c644247400           mov byte ptr [esp + 0x74], 0
// 0058f675  e8a6ff0400           call 0x5df620
// 0058f67a  8d4c2418             lea ecx, [esp + 0x18]
// 0058f67e  c7442474ffffffff     mov dword ptr [esp + 0x74], 0xffffffff
// 0058f686  ff1568248000         call dword ptr [0x802468]
// 0058f68c  85f6                 test esi, esi
// 0058f68e  7529                 jne 0x58f6b9
// 0058f690  ff1590288000         call dword ptr [0x802890]
// 0058f696  3b6e18               cmp ebp, dword ptr [esi + 0x18]
// 0058f699  7506                 jne 0x58f6a1
// 0058f69b  ff1590288000         call dword ptr [0x802890]
// 0058f6a1  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 0058f6a5  5f                   pop edi
// 0058f6a6  5e                   pop esi
// 0058f6a7  8d4528               lea eax, [ebp + 0x28]
// 0058f6aa  5d                   pop ebp
// 0058f6ab  5b                   pop ebx
// 0058f6ac  64890d00000000       mov dword ptr fs:[0], ecx
// 0058f6b3  83c468               add esp, 0x68
// 0058f6b6  c20400               ret 4
// 0058f6b9  8b36                 mov esi, dword ptr [esi]
// 0058f6bb  ebd9                 jmp 0x58f696
// standard library map_str<string> (function ??A?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@std@@QAEAAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@ABV21@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
