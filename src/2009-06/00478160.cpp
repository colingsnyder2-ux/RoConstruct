// from server: 100% by auto
// roc 2009-06 00478160  unit: Ogre::RbxMeshLoader  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00478160
//
// 00478160  6aff                 push -1
// 00478162  64a100000000         mov eax, dword ptr fs:[0]
// 00478168  68e1448500           push 0x8544e1
// 0047816d  50                   push eax
// 0047816e  64892500000000       mov dword ptr fs:[0], esp
// 00478175  83ec5c               sub esp, 0x5c
// 00478178  53                   push ebx
// 00478179  8b5c2470             mov ebx, dword ptr [esp + 0x70]
// 0047817d  55                   push ebp
// 0047817e  56                   push esi
// 0047817f  57                   push edi
// 00478180  53                   push ebx
// 00478181  8bf9                 mov edi, ecx
// 00478183  e868ddffff           call 0x475ef0
// 00478188  8be8                 mov ebp, eax
// 0047818a  85ff                 test edi, edi
// 0047818c  7506                 jne 0x478194
// 0047818e  ff15ace98900         call dword ptr [0x89e9ac]
// 00478194  8b37                 mov esi, dword ptr [edi]
// 00478196  8b4718               mov eax, dword ptr [edi + 0x18]
// 00478199  89442414             mov dword ptr [esp + 0x14], eax
// 0047819d  85f6                 test esi, esi
// 0047819f  7404                 je 0x4781a5
// 004781a1  3bf6                 cmp esi, esi
// 004781a3  7406                 je 0x4781ab
// 004781a5  ff15ace98900         call dword ptr [0x89e9ac]
// 004781ab  3b6c2414             cmp ebp, dword ptr [esp + 0x14]
// 004781af  7412                 je 0x4781c3
// 004781b1  8d4d0c               lea ecx, [ebp + 0xc]
// 004781b4  51                   push ecx
// 004781b5  53                   push ebx
// 004781b6  ff15e0e48900         call dword ptr [0x89e4e0]
// 004781bc  83c408               add esp, 8
// 004781bf  84c0                 test al, al
// 004781c1  7459                 je 0x47821c
// 004781c3  8d4c2418             lea ecx, [esp + 0x18]
// 004781c7  ff15c0e48900         call dword ptr [0x89e4c0]
// 004781cd  50                   push eax
// 004781ce  53                   push ebx
// 004781cf  8d4c243c             lea ecx, [esp + 0x3c]
// 004781d3  c744247c00000000     mov dword ptr [esp + 0x7c], 0
// 004781db  e840dbffff           call 0x475d20
// 004781e0  50                   push eax
// 004781e1  55                   push ebp
// 004781e2  56                   push esi
// 004781e3  8d54241c             lea edx, [esp + 0x1c]
// 004781e7  52                   push edx
// 004781e8  8bcf                 mov ecx, edi
// 004781ea  c684248400000001     mov byte ptr [esp + 0x84], 1
// 004781f2  e8a9f3ffff           call 0x4775a0
// 004781f7  8b30                 mov esi, dword ptr [eax]
// 004781f9  8b6804               mov ebp, dword ptr [eax + 4]
// 004781fc  8d4c2434             lea ecx, [esp + 0x34]
// 00478200  c644247400           mov byte ptr [esp + 0x74], 0
// 00478205  e8f6b9f9ff           call 0x413c00
// 0047820a  8d4c2418             lea ecx, [esp + 0x18]
// 0047820e  c7442474ffffffff     mov dword ptr [esp + 0x74], 0xffffffff
// 00478216  ff15c4e48900         call dword ptr [0x89e4c4]
// 0047821c  85f6                 test esi, esi
// 0047821e  7529                 jne 0x478249
// 00478220  ff15ace98900         call dword ptr [0x89e9ac]
// 00478226  3b6e18               cmp ebp, dword ptr [esi + 0x18]
// 00478229  7506                 jne 0x478231
// 0047822b  ff15ace98900         call dword ptr [0x89e9ac]
// 00478231  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 00478235  5f                   pop edi
// 00478236  5e                   pop esi
// 00478237  8d4528               lea eax, [ebp + 0x28]
// 0047823a  5d                   pop ebp
// 0047823b  5b                   pop ebx
// 0047823c  64890d00000000       mov dword ptr fs:[0], ecx
// 00478243  83c468               add esp, 0x68
// 00478246  c20400               ret 4
// 00478249  8b36                 mov esi, dword ptr [esi]
// 0047824b  ebd9                 jmp 0x478226
// standard library map_str<string> (function ??A?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@std@@QAEAAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@ABV21@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
