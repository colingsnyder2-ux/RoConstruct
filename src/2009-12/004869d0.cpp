// from server: 100% by auto
// roc 2009-12 004869d0  unit: Ogre::GfxClustererPart  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004869d0
//
// 004869d0  83ec14               sub esp, 0x14
// 004869d3  53                   push ebx
// 004869d4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 004869d8  55                   push ebp
// 004869d9  56                   push esi
// 004869da  8be9                 mov ebp, ecx
// 004869dc  57                   push edi
// 004869dd  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 004869e0  8b7704               mov esi, dword ptr [edi + 4]
// 004869e3  807e4500             cmp byte ptr [esi + 0x45], 0
// 004869e7  b001                 mov al, 1
// 004869e9  88442410             mov byte ptr [esp + 0x10], al
// 004869ed  7526                 jne 0x486a15
// 004869ef  90                   nop 
// 004869f0  8d460c               lea eax, [esi + 0xc]
// 004869f3  50                   push eax
// 004869f4  53                   push ebx
// 004869f5  8bfe                 mov edi, esi
// 004869f7  ff15d8b59800         call dword ptr [0x98b5d8]
// 004869fd  83c408               add esp, 8
// 00486a00  88442410             mov byte ptr [esp + 0x10], al
// 00486a04  84c0                 test al, al
// 00486a06  7404                 je 0x486a0c
// 00486a08  8b36                 mov esi, dword ptr [esi]
// 00486a0a  eb03                 jmp 0x486a0f
// 00486a0c  8b7608               mov esi, dword ptr [esi + 8]
// 00486a0f  807e4500             cmp byte ptr [esi + 0x45], 0
// 00486a13  74db                 je 0x4869f0
// 00486a15  8b7500               mov esi, dword ptr [ebp]
// 00486a18  897c2418             mov dword ptr [esp + 0x18], edi
// 00486a1c  89742414             mov dword ptr [esp + 0x14], esi
// 00486a20  84c0                 test al, al
// 00486a22  7458                 je 0x486a7c
// 00486a24  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00486a27  8b11                 mov edx, dword ptr [ecx]
// 00486a29  89542420             mov dword ptr [esp + 0x20], edx
// 00486a2d  85f6                 test esi, esi
// 00486a2f  7404                 je 0x486a35
// 00486a31  3bf6                 cmp esi, esi
// 00486a33  7406                 je 0x486a3b
// 00486a35  ff1560b79800         call dword ptr [0x98b760]
// 00486a3b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 00486a3f  752e                 jne 0x486a6f
// 00486a41  53                   push ebx
// 00486a42  57                   push edi
// 00486a43  6a01                 push 1
// 00486a45  8d442428             lea eax, [esp + 0x28]
// 00486a49  50                   push eax
// 00486a4a  8bcd                 mov ecx, ebp
// 00486a4c  e86ffaffff           call 0x4864c0
// 00486a51  5f                   pop edi
// 00486a52  8bc8                 mov ecx, eax
// 00486a54  8b11                 mov edx, dword ptr [ecx]
// 00486a56  8b442424             mov eax, dword ptr [esp + 0x24]
// 00486a5a  8b4904               mov ecx, dword ptr [ecx + 4]
// 00486a5d  5e                   pop esi
// 00486a5e  5d                   pop ebp
// 00486a5f  8910                 mov dword ptr [eax], edx
// 00486a61  894804               mov dword ptr [eax + 4], ecx
// 00486a64  c6400801             mov byte ptr [eax + 8], 1
// 00486a68  5b                   pop ebx
// 00486a69  83c414               add esp, 0x14
// 00486a6c  c20800               ret 8
// 00486a6f  8d4c2414             lea ecx, [esp + 0x14]
// 00486a73  e808edffff           call 0x485780
// 00486a78  8b742414             mov esi, dword ptr [esp + 0x14]
// 00486a7c  8b542418             mov edx, dword ptr [esp + 0x18]
// 00486a80  83c20c               add edx, 0xc
// 00486a83  53                   push ebx
// 00486a84  52                   push edx
// 00486a85  ff15d8b59800         call dword ptr [0x98b5d8]
// 00486a8b  83c408               add esp, 8
// 00486a8e  84c0                 test al, al
// 00486a90  740e                 je 0x486aa0
// 00486a92  8b442410             mov eax, dword ptr [esp + 0x10]
// 00486a96  53                   push ebx
// 00486a97  57                   push edi
// 00486a98  50                   push eax
// 00486a99  8d4c2428             lea ecx, [esp + 0x28]
// 00486a9d  51                   push ecx
// 00486a9e  ebaa                 jmp 0x486a4a
// 00486aa0  8b442428             mov eax, dword ptr [esp + 0x28]
// 00486aa4  8b542418             mov edx, dword ptr [esp + 0x18]
// 00486aa8  5f                   pop edi
// 00486aa9  8930                 mov dword ptr [eax], esi
// 00486aab  5e                   pop esi
// 00486aac  5d                   pop ebp
// 00486aad  895004               mov dword ptr [eax + 4], edx
// 00486ab0  c6400800             mov byte ptr [eax + 8], 0
// 00486ab4  5b                   pop ebx
// 00486ab5  83c414               add esp, 0x14
// 00486ab8  c20800               ret 8
// standard library map_str<string> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
