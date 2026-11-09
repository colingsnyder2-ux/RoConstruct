// from server: 100% by auto
// roc 2010-06 005f0c50  unit: TextXmlWriter  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005f0c50
//
// 005f0c50  83ec14               sub esp, 0x14
// 005f0c53  53                   push ebx
// 005f0c54  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 005f0c58  55                   push ebp
// 005f0c59  56                   push esi
// 005f0c5a  8be9                 mov ebp, ecx
// 005f0c5c  57                   push edi
// 005f0c5d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005f0c60  8b7704               mov esi, dword ptr [edi + 4]
// 005f0c63  807e4500             cmp byte ptr [esi + 0x45], 0
// 005f0c67  b001                 mov al, 1
// 005f0c69  88442410             mov byte ptr [esp + 0x10], al
// 005f0c6d  7526                 jne 0x5f0c95
// 005f0c6f  90                   nop 
// 005f0c70  8d460c               lea eax, [esi + 0xc]
// 005f0c73  50                   push eax
// 005f0c74  53                   push ebx
// 005f0c75  8bfe                 mov edi, esi
// 005f0c77  ff151ca59e00         call dword ptr [0x9ea51c]
// 005f0c7d  83c408               add esp, 8
// 005f0c80  88442410             mov byte ptr [esp + 0x10], al
// 005f0c84  84c0                 test al, al
// 005f0c86  7404                 je 0x5f0c8c
// 005f0c88  8b36                 mov esi, dword ptr [esi]
// 005f0c8a  eb03                 jmp 0x5f0c8f
// 005f0c8c  8b7608               mov esi, dword ptr [esi + 8]
// 005f0c8f  807e4500             cmp byte ptr [esi + 0x45], 0
// 005f0c93  74db                 je 0x5f0c70
// 005f0c95  8b7500               mov esi, dword ptr [ebp]
// 005f0c98  897c2418             mov dword ptr [esp + 0x18], edi
// 005f0c9c  89742414             mov dword ptr [esp + 0x14], esi
// 005f0ca0  84c0                 test al, al
// 005f0ca2  7458                 je 0x5f0cfc
// 005f0ca4  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 005f0ca7  8b11                 mov edx, dword ptr [ecx]
// 005f0ca9  89542420             mov dword ptr [esp + 0x20], edx
// 005f0cad  85f6                 test esi, esi
// 005f0caf  7404                 je 0x5f0cb5
// 005f0cb1  3bf6                 cmp esi, esi
// 005f0cb3  7406                 je 0x5f0cbb
// 005f0cb5  ff150ca99e00         call dword ptr [0x9ea90c]
// 005f0cbb  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 005f0cbf  752e                 jne 0x5f0cef
// 005f0cc1  53                   push ebx
// 005f0cc2  57                   push edi
// 005f0cc3  6a01                 push 1
// 005f0cc5  8d442428             lea eax, [esp + 0x28]
// 005f0cc9  50                   push eax
// 005f0cca  8bcd                 mov ecx, ebp
// 005f0ccc  e87ffdffff           call 0x5f0a50
// 005f0cd1  5f                   pop edi
// 005f0cd2  8bc8                 mov ecx, eax
// 005f0cd4  8b11                 mov edx, dword ptr [ecx]
// 005f0cd6  8b442424             mov eax, dword ptr [esp + 0x24]
// 005f0cda  8b4904               mov ecx, dword ptr [ecx + 4]
// 005f0cdd  5e                   pop esi
// 005f0cde  5d                   pop ebp
// 005f0cdf  8910                 mov dword ptr [eax], edx
// 005f0ce1  894804               mov dword ptr [eax + 4], ecx
// 005f0ce4  c6400801             mov byte ptr [eax + 8], 1
// 005f0ce8  5b                   pop ebx
// 005f0ce9  83c414               add esp, 0x14
// 005f0cec  c20800               ret 8
// 005f0cef  8d4c2414             lea ecx, [esp + 0x14]
// 005f0cf3  e8a8eeffff           call 0x5efba0
// 005f0cf8  8b742414             mov esi, dword ptr [esp + 0x14]
// 005f0cfc  8b542418             mov edx, dword ptr [esp + 0x18]
// 005f0d00  83c20c               add edx, 0xc
// 005f0d03  53                   push ebx
// 005f0d04  52                   push edx
// 005f0d05  ff151ca59e00         call dword ptr [0x9ea51c]
// 005f0d0b  83c408               add esp, 8
// 005f0d0e  84c0                 test al, al
// 005f0d10  740e                 je 0x5f0d20
// 005f0d12  8b442410             mov eax, dword ptr [esp + 0x10]
// 005f0d16  53                   push ebx
// 005f0d17  57                   push edi
// 005f0d18  50                   push eax
// 005f0d19  8d4c2428             lea ecx, [esp + 0x28]
// 005f0d1d  51                   push ecx
// 005f0d1e  ebaa                 jmp 0x5f0cca
// 005f0d20  8b442428             mov eax, dword ptr [esp + 0x28]
// 005f0d24  8b542418             mov edx, dword ptr [esp + 0x18]
// 005f0d28  5f                   pop edi
// 005f0d29  8930                 mov dword ptr [eax], esi
// 005f0d2b  5e                   pop esi
// 005f0d2c  5d                   pop ebp
// 005f0d2d  895004               mov dword ptr [eax + 4], edx
// 005f0d30  c6400800             mov byte ptr [eax + 8], 0
// 005f0d34  5b                   pop ebx
// 005f0d35  83c414               add esp, 0x14
// 005f0d38  c20800               ret 8
// standard library map_str<string> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
