// from server: 100% by auto
// roc 2009-12 00487fe0  unit: Ogre::GfxClustererPart  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00487fe0
//
// 00487fe0  6aff                 push -1
// 00487fe2  64a100000000         mov eax, dword ptr fs:[0]
// 00487fe8  68b1f69200           push 0x92f6b1
// 00487fed  50                   push eax
// 00487fee  64892500000000       mov dword ptr fs:[0], esp
// 00487ff5  83ec5c               sub esp, 0x5c
// 00487ff8  53                   push ebx
// 00487ff9  8b5c2470             mov ebx, dword ptr [esp + 0x70]
// 00487ffd  55                   push ebp
// 00487ffe  56                   push esi
// 00487fff  57                   push edi
// 00488000  53                   push ebx
// 00488001  8bf9                 mov edi, ecx
// 00488003  e818d6ffff           call 0x485620
// 00488008  8be8                 mov ebp, eax
// 0048800a  85ff                 test edi, edi
// 0048800c  7506                 jne 0x488014
// 0048800e  ff1560b79800         call dword ptr [0x98b760]
// 00488014  8b37                 mov esi, dword ptr [edi]
// 00488016  8b4718               mov eax, dword ptr [edi + 0x18]
// 00488019  89442414             mov dword ptr [esp + 0x14], eax
// 0048801d  85f6                 test esi, esi
// 0048801f  7404                 je 0x488025
// 00488021  3bf6                 cmp esi, esi
// 00488023  7406                 je 0x48802b
// 00488025  ff1560b79800         call dword ptr [0x98b760]
// 0048802b  3b6c2414             cmp ebp, dword ptr [esp + 0x14]
// 0048802f  7412                 je 0x488043
// 00488031  8d4d0c               lea ecx, [ebp + 0xc]
// 00488034  51                   push ecx
// 00488035  53                   push ebx
// 00488036  ff15d8b59800         call dword ptr [0x98b5d8]
// 0048803c  83c408               add esp, 8
// 0048803f  84c0                 test al, al
// 00488041  7459                 je 0x48809c
// 00488043  8d4c2418             lea ecx, [esp + 0x18]
// 00488047  ff15e8b69800         call dword ptr [0x98b6e8]
// 0048804d  50                   push eax
// 0048804e  53                   push ebx
// 0048804f  8d4c243c             lea ecx, [esp + 0x3c]
// 00488053  c744247c00000000     mov dword ptr [esp + 0x7c], 0
// 0048805b  e840ceffff           call 0x484ea0
// 00488060  50                   push eax
// 00488061  55                   push ebp
// 00488062  56                   push esi
// 00488063  8d54241c             lea edx, [esp + 0x1c]
// 00488067  52                   push edx
// 00488068  8bcf                 mov ecx, edi
// 0048806a  c684248400000001     mov byte ptr [esp + 0x84], 1
// 00488072  e8a9f4ffff           call 0x487520
// 00488077  8b30                 mov esi, dword ptr [eax]
// 00488079  8b6804               mov ebp, dword ptr [eax + 4]
// 0048807c  8d4c2434             lea ecx, [esp + 0x34]
// 00488080  c644247400           mov byte ptr [esp + 0x74], 0
// 00488085  e8e6b5f8ff           call 0x413670
// 0048808a  8d4c2418             lea ecx, [esp + 0x18]
// 0048808e  c7442474ffffffff     mov dword ptr [esp + 0x74], 0xffffffff
// 00488096  ff15e4b69800         call dword ptr [0x98b6e4]
// 0048809c  85f6                 test esi, esi
// 0048809e  7529                 jne 0x4880c9
// 004880a0  ff1560b79800         call dword ptr [0x98b760]
// 004880a6  3b6e18               cmp ebp, dword ptr [esi + 0x18]
// 004880a9  7506                 jne 0x4880b1
// 004880ab  ff1560b79800         call dword ptr [0x98b760]
// 004880b1  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 004880b5  5f                   pop edi
// 004880b6  5e                   pop esi
// 004880b7  8d4528               lea eax, [ebp + 0x28]
// 004880ba  5d                   pop ebp
// 004880bb  5b                   pop ebx
// 004880bc  64890d00000000       mov dword ptr fs:[0], ecx
// 004880c3  83c468               add esp, 0x68
// 004880c6  c20400               ret 4
// 004880c9  8b36                 mov esi, dword ptr [esi]
// 004880cb  ebd9                 jmp 0x4880a6
// standard library map_str<string> (function ??A?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@std@@QAEAAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@ABV21@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
