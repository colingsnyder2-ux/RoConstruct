// from server: 100% by auto
// roc 2009-06 004769b0  unit: Ogre::RbxMeshLoader  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004769b0
//
// 004769b0  83ec14               sub esp, 0x14
// 004769b3  53                   push ebx
// 004769b4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 004769b8  55                   push ebp
// 004769b9  56                   push esi
// 004769ba  8be9                 mov ebp, ecx
// 004769bc  57                   push edi
// 004769bd  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 004769c0  8b7704               mov esi, dword ptr [edi + 4]
// 004769c3  807e4500             cmp byte ptr [esi + 0x45], 0
// 004769c7  b001                 mov al, 1
// 004769c9  88442410             mov byte ptr [esp + 0x10], al
// 004769cd  7526                 jne 0x4769f5
// 004769cf  90                   nop 
// 004769d0  8d460c               lea eax, [esi + 0xc]
// 004769d3  50                   push eax
// 004769d4  53                   push ebx
// 004769d5  8bfe                 mov edi, esi
// 004769d7  ff15e0e48900         call dword ptr [0x89e4e0]
// 004769dd  83c408               add esp, 8
// 004769e0  88442410             mov byte ptr [esp + 0x10], al
// 004769e4  84c0                 test al, al
// 004769e6  7404                 je 0x4769ec
// 004769e8  8b36                 mov esi, dword ptr [esi]
// 004769ea  eb03                 jmp 0x4769ef
// 004769ec  8b7608               mov esi, dword ptr [esi + 8]
// 004769ef  807e4500             cmp byte ptr [esi + 0x45], 0
// 004769f3  74db                 je 0x4769d0
// 004769f5  8b7500               mov esi, dword ptr [ebp]
// 004769f8  897c2418             mov dword ptr [esp + 0x18], edi
// 004769fc  89742414             mov dword ptr [esp + 0x14], esi
// 00476a00  84c0                 test al, al
// 00476a02  7458                 je 0x476a5c
// 00476a04  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00476a07  8b11                 mov edx, dword ptr [ecx]
// 00476a09  89542420             mov dword ptr [esp + 0x20], edx
// 00476a0d  85f6                 test esi, esi
// 00476a0f  7404                 je 0x476a15
// 00476a11  3bf6                 cmp esi, esi
// 00476a13  7406                 je 0x476a1b
// 00476a15  ff15ace98900         call dword ptr [0x89e9ac]
// 00476a1b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 00476a1f  752e                 jne 0x476a4f
// 00476a21  53                   push ebx
// 00476a22  57                   push edi
// 00476a23  6a01                 push 1
// 00476a25  8d442428             lea eax, [esp + 0x28]
// 00476a29  50                   push eax
// 00476a2a  8bcd                 mov ecx, ebp
// 00476a2c  e8bffcffff           call 0x4766f0
// 00476a31  5f                   pop edi
// 00476a32  8bc8                 mov ecx, eax
// 00476a34  8b11                 mov edx, dword ptr [ecx]
// 00476a36  8b442424             mov eax, dword ptr [esp + 0x24]
// 00476a3a  8b4904               mov ecx, dword ptr [ecx + 4]
// 00476a3d  5e                   pop esi
// 00476a3e  5d                   pop ebp
// 00476a3f  8910                 mov dword ptr [eax], edx
// 00476a41  894804               mov dword ptr [eax + 4], ecx
// 00476a44  c6400801             mov byte ptr [eax + 8], 1
// 00476a48  5b                   pop ebx
// 00476a49  83c414               add esp, 0x14
// 00476a4c  c20800               ret 8
// 00476a4f  8d4c2414             lea ecx, [esp + 0x14]
// 00476a53  e8e8f4ffff           call 0x475f40
// 00476a58  8b742414             mov esi, dword ptr [esp + 0x14]
// 00476a5c  8b542418             mov edx, dword ptr [esp + 0x18]
// 00476a60  83c20c               add edx, 0xc
// 00476a63  53                   push ebx
// 00476a64  52                   push edx
// 00476a65  ff15e0e48900         call dword ptr [0x89e4e0]
// 00476a6b  83c408               add esp, 8
// 00476a6e  84c0                 test al, al
// 00476a70  740e                 je 0x476a80
// 00476a72  8b442410             mov eax, dword ptr [esp + 0x10]
// 00476a76  53                   push ebx
// 00476a77  57                   push edi
// 00476a78  50                   push eax
// 00476a79  8d4c2428             lea ecx, [esp + 0x28]
// 00476a7d  51                   push ecx
// 00476a7e  ebaa                 jmp 0x476a2a
// 00476a80  8b442428             mov eax, dword ptr [esp + 0x28]
// 00476a84  8b542418             mov edx, dword ptr [esp + 0x18]
// 00476a88  5f                   pop edi
// 00476a89  8930                 mov dword ptr [eax], esi
// 00476a8b  5e                   pop esi
// 00476a8c  5d                   pop ebp
// 00476a8d  895004               mov dword ptr [eax + 4], edx
// 00476a90  c6400800             mov byte ptr [eax + 8], 0
// 00476a94  5b                   pop ebx
// 00476a95  83c414               add esp, 0x14
// 00476a98  c20800               ret 8
// standard library map_str<string> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@V12@@2@@Z)

// stl: map_str<string>
#include <string>
typedef std::string E;
#include <map>
#include <string>
template class std::map<std::string, E>;
