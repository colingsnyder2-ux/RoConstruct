// from server: 100% by auto
// roc 2010-06 005f17f0  unit: TextXmlWriterWithEmbeddedContent  size: 237 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005f17f0
//
// 005f17f0  6aff                 push -1
// 005f17f2  64a100000000         mov eax, dword ptr fs:[0]
// 005f17f8  6881859900           push 0x998581
// 005f17fd  50                   push eax
// 005f17fe  64892500000000       mov dword ptr fs:[0], esp
// 005f1805  83ec5c               sub esp, 0x5c
// 005f1808  53                   push ebx
// 005f1809  8b5c2470             mov ebx, dword ptr [esp + 0x70]
// 005f180d  55                   push ebp
// 005f180e  56                   push esi
// 005f180f  57                   push edi
// 005f1810  53                   push ebx
// 005f1811  8bf9                 mov edi, ecx
// 005f1813  e838e3ffff           call 0x5efb50
// 005f1818  8be8                 mov ebp, eax
// 005f181a  85ff                 test edi, edi
// 005f181c  7506                 jne 0x5f1824
// 005f181e  ff150ca99e00         call dword ptr [0x9ea90c]
// 005f1824  8b37                 mov esi, dword ptr [edi]
// 005f1826  8b4718               mov eax, dword ptr [edi + 0x18]
// 005f1829  89442414             mov dword ptr [esp + 0x14], eax
// 005f182d  85f6                 test esi, esi
// 005f182f  7404                 je 0x5f1835
// 005f1831  3bf6                 cmp esi, esi
// 005f1833  7406                 je 0x5f183b
// 005f1835  ff150ca99e00         call dword ptr [0x9ea90c]
// 005f183b  3b6c2414             cmp ebp, dword ptr [esp + 0x14]
// 005f183f  7412                 je 0x5f1853
// 005f1841  8d4d0c               lea ecx, [ebp + 0xc]
// 005f1844  51                   push ecx
// 005f1845  53                   push ebx
// 005f1846  ff151ca59e00         call dword ptr [0x9ea51c]
// 005f184c  83c408               add esp, 8
// 005f184f  84c0                 test al, al
// 005f1851  7459                 je 0x5f18ac
// 005f1853  8d4c2418             lea ecx, [esp + 0x18]
// 005f1857  ff1504a49e00         call dword ptr [0x9ea404]
// 005f185d  50                   push eax
// 005f185e  53                   push ebx
// 005f185f  8d4c243c             lea ecx, [esp + 0x3c]
// 005f1863  c744247c00000000     mov dword ptr [esp + 0x7c], 0
// 005f186b  e830e0ffff           call 0x5ef8a0
// 005f1870  50                   push eax
// 005f1871  55                   push ebp
// 005f1872  56                   push esi
// 005f1873  8d54241c             lea edx, [esp + 0x1c]
// 005f1877  52                   push edx
// 005f1878  8bcf                 mov ecx, edi
// 005f187a  c684248400000001     mov byte ptr [esp + 0x84], 1
// 005f1882  e889f9ffff           call 0x5f1210
// 005f1887  8b30                 mov esi, dword ptr [eax]
// 005f1889  8b6804               mov ebp, dword ptr [eax + 4]
// 005f188c  8d4c2434             lea ecx, [esp + 0x34]
// 005f1890  c644247400           mov byte ptr [esp + 0x74], 0
// 005f1895  e8a620e2ff           call 0x413940
// 005f189a  8d4c2418             lea ecx, [esp + 0x18]
// 005f189e  c7442474ffffffff     mov dword ptr [esp + 0x74], 0xffffffff
// 005f18a6  ff1500a49e00         call dword ptr [0x9ea400]
// 005f18ac  85f6                 test esi, esi
// 005f18ae  7529                 jne 0x5f18d9
// 005f18b0  ff150ca99e00         call dword ptr [0x9ea90c]
// 005f18b6  3b6e18               cmp ebp, dword ptr [esi + 0x18]
// 005f18b9  7506                 jne 0x5f18c1
// 005f18bb  ff150ca99e00         call dword ptr [0x9ea90c]
// 005f18c1  8b4c246c             mov ecx, dword ptr [esp + 0x6c]
// 005f18c5  5f                   pop edi
// 005f18c6  5e                   pop esi
// 005f18c7  8d4528               lea eax, [ebp + 0x28]
// 005f18ca  5d                   pop ebp
// 005f18cb  5b                   pop ebx
// 005f18cc  64890d00000000       mov dword ptr fs:[0], ecx
// 005f18d3  83c468               add esp, 0x68
// 005f18d6  c20400               ret 4
// 005f18d9  8b36                 mov esi, dword ptr [esi]
// 005f18db  ebd9                 jmp 0x5f18b6
// standard library map_str<string> (function ??A?$map@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@@std@@QAEAAV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@1@ABV21@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
