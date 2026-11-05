// from server: 100% by auto
// roc 2009-12 00768cd0  unit: RBX::VInstance::?$NonFactoryProduct  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00768cd0
//
// 00768cd0  83ec14               sub esp, 0x14
// 00768cd3  53                   push ebx
// 00768cd4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00768cd8  55                   push ebp
// 00768cd9  56                   push esi
// 00768cda  8be9                 mov ebp, ecx
// 00768cdc  57                   push edi
// 00768cdd  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 00768ce0  8b7704               mov esi, dword ptr [edi + 4]
// 00768ce3  807e3100             cmp byte ptr [esi + 0x31], 0
// 00768ce7  b001                 mov al, 1
// 00768ce9  88442410             mov byte ptr [esp + 0x10], al
// 00768ced  7526                 jne 0x768d15
// 00768cef  90                   nop 
// 00768cf0  8d460c               lea eax, [esi + 0xc]
// 00768cf3  50                   push eax
// 00768cf4  53                   push ebx
// 00768cf5  8bfe                 mov edi, esi
// 00768cf7  ff15d8b59800         call dword ptr [0x98b5d8]
// 00768cfd  83c408               add esp, 8
// 00768d00  88442410             mov byte ptr [esp + 0x10], al
// 00768d04  84c0                 test al, al
// 00768d06  7404                 je 0x768d0c
// 00768d08  8b36                 mov esi, dword ptr [esi]
// 00768d0a  eb03                 jmp 0x768d0f
// 00768d0c  8b7608               mov esi, dword ptr [esi + 8]
// 00768d0f  807e3100             cmp byte ptr [esi + 0x31], 0
// 00768d13  74db                 je 0x768cf0
// 00768d15  8b7500               mov esi, dword ptr [ebp]
// 00768d18  897c2418             mov dword ptr [esp + 0x18], edi
// 00768d1c  89742414             mov dword ptr [esp + 0x14], esi
// 00768d20  84c0                 test al, al
// 00768d22  7458                 je 0x768d7c
// 00768d24  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00768d27  8b11                 mov edx, dword ptr [ecx]
// 00768d29  89542420             mov dword ptr [esp + 0x20], edx
// 00768d2d  85f6                 test esi, esi
// 00768d2f  7404                 je 0x768d35
// 00768d31  3bf6                 cmp esi, esi
// 00768d33  7406                 je 0x768d3b
// 00768d35  ff1560b79800         call dword ptr [0x98b760]
// 00768d3b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 00768d3f  752e                 jne 0x768d6f
// 00768d41  53                   push ebx
// 00768d42  57                   push edi
// 00768d43  6a01                 push 1
// 00768d45  8d442428             lea eax, [esp + 0x28]
// 00768d49  50                   push eax
// 00768d4a  8bcd                 mov ecx, ebp
// 00768d4c  e83ffaffff           call 0x768790
// 00768d51  5f                   pop edi
// 00768d52  8bc8                 mov ecx, eax
// 00768d54  8b11                 mov edx, dword ptr [ecx]
// 00768d56  8b442424             mov eax, dword ptr [esp + 0x24]
// 00768d5a  8b4904               mov ecx, dword ptr [ecx + 4]
// 00768d5d  5e                   pop esi
// 00768d5e  5d                   pop ebp
// 00768d5f  8910                 mov dword ptr [eax], edx
// 00768d61  894804               mov dword ptr [eax + 4], ecx
// 00768d64  c6400801             mov byte ptr [eax + 8], 1
// 00768d68  5b                   pop ebx
// 00768d69  83c414               add esp, 0x14
// 00768d6c  c20800               ret 8
// 00768d6f  8d4c2414             lea ecx, [esp + 0x14]
// 00768d73  e8e8aadaff           call 0x513860
// 00768d78  8b742414             mov esi, dword ptr [esp + 0x14]
// 00768d7c  8b542418             mov edx, dword ptr [esp + 0x18]
// 00768d80  83c20c               add edx, 0xc
// 00768d83  53                   push ebx
// 00768d84  52                   push edx
// 00768d85  ff15d8b59800         call dword ptr [0x98b5d8]
// 00768d8b  83c408               add esp, 8
// 00768d8e  84c0                 test al, al
// 00768d90  740e                 je 0x768da0
// 00768d92  8b442410             mov eax, dword ptr [esp + 0x10]
// 00768d96  53                   push ebx
// 00768d97  57                   push edi
// 00768d98  50                   push eax
// 00768d99  8d4c2428             lea ecx, [esp + 0x28]
// 00768d9d  51                   push ecx
// 00768d9e  ebaa                 jmp 0x768d4a
// 00768da0  8b442428             mov eax, dword ptr [esp + 0x28]
// 00768da4  8b542418             mov edx, dword ptr [esp + 0x18]
// 00768da8  5f                   pop edi
// 00768da9  8930                 mov dword ptr [eax], esi
// 00768dab  5e                   pop esi
// 00768dac  5d                   pop ebp
// 00768dad  895004               mov dword ptr [eax + 4], edx
// 00768db0  c6400800             mov byte ptr [eax + 8], 0
// 00768db4  5b                   pop ebx
// 00768db5  83c414               add esp, 0x14
// 00768db8  c20800               ret 8
// standard library map_str<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
