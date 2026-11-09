// from server: 100% by auto
// roc 2008-06 00693cd0  unit: Ogre::RbxSceneManager  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00693cd0
//
// 00693cd0  83ec14               sub esp, 0x14
// 00693cd3  53                   push ebx
// 00693cd4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00693cd8  55                   push ebp
// 00693cd9  56                   push esi
// 00693cda  8be9                 mov ebp, ecx
// 00693cdc  57                   push edi
// 00693cdd  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 00693ce0  8b7704               mov esi, dword ptr [edi + 4]
// 00693ce3  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 00693ce7  b001                 mov al, 1
// 00693ce9  88442410             mov byte ptr [esp + 0x10], al
// 00693ced  7526                 jne 0x693d15
// 00693cef  90                   nop 
// 00693cf0  8d460c               lea eax, [esi + 0xc]
// 00693cf3  50                   push eax
// 00693cf4  53                   push ebx
// 00693cf5  8bfe                 mov edi, esi
// 00693cf7  ff155c238000         call dword ptr [0x80235c]
// 00693cfd  83c408               add esp, 8
// 00693d00  88442410             mov byte ptr [esp + 0x10], al
// 00693d04  84c0                 test al, al
// 00693d06  7404                 je 0x693d0c
// 00693d08  8b36                 mov esi, dword ptr [esi]
// 00693d0a  eb03                 jmp 0x693d0f
// 00693d0c  8b7608               mov esi, dword ptr [esi + 8]
// 00693d0f  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 00693d13  74db                 je 0x693cf0
// 00693d15  8b7500               mov esi, dword ptr [ebp]
// 00693d18  897c2418             mov dword ptr [esp + 0x18], edi
// 00693d1c  89742414             mov dword ptr [esp + 0x14], esi
// 00693d20  84c0                 test al, al
// 00693d22  7458                 je 0x693d7c
// 00693d24  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 00693d27  8b11                 mov edx, dword ptr [ecx]
// 00693d29  89542420             mov dword ptr [esp + 0x20], edx
// 00693d2d  85f6                 test esi, esi
// 00693d2f  7404                 je 0x693d35
// 00693d31  3bf6                 cmp esi, esi
// 00693d33  7406                 je 0x693d3b
// 00693d35  ff1590288000         call dword ptr [0x802890]
// 00693d3b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 00693d3f  752e                 jne 0x693d6f
// 00693d41  53                   push ebx
// 00693d42  57                   push edi
// 00693d43  6a01                 push 1
// 00693d45  8d442428             lea eax, [esp + 0x28]
// 00693d49  50                   push eax
// 00693d4a  8bcd                 mov ecx, ebp
// 00693d4c  e83fe0ffff           call 0x691d90
// 00693d51  5f                   pop edi
// 00693d52  8bc8                 mov ecx, eax
// 00693d54  8b11                 mov edx, dword ptr [ecx]
// 00693d56  8b442424             mov eax, dword ptr [esp + 0x24]
// 00693d5a  8b4904               mov ecx, dword ptr [ecx + 4]
// 00693d5d  5e                   pop esi
// 00693d5e  5d                   pop ebp
// 00693d5f  8910                 mov dword ptr [eax], edx
// 00693d61  894804               mov dword ptr [eax + 4], ecx
// 00693d64  c6400801             mov byte ptr [eax + 8], 1
// 00693d68  5b                   pop ebx
// 00693d69  83c414               add esp, 0x14
// 00693d6c  c20800               ret 8
// 00693d6f  8d4c2414             lea ecx, [esp + 0x14]
// 00693d73  e8d895ffff           call 0x68d350
// 00693d78  8b742414             mov esi, dword ptr [esp + 0x14]
// 00693d7c  8b542418             mov edx, dword ptr [esp + 0x18]
// 00693d80  83c20c               add edx, 0xc
// 00693d83  53                   push ebx
// 00693d84  52                   push edx
// 00693d85  ff155c238000         call dword ptr [0x80235c]
// 00693d8b  83c408               add esp, 8
// 00693d8e  84c0                 test al, al
// 00693d90  740e                 je 0x693da0
// 00693d92  8b442410             mov eax, dword ptr [esp + 0x10]
// 00693d96  53                   push ebx
// 00693d97  57                   push edi
// 00693d98  50                   push eax
// 00693d99  8d4c2428             lea ecx, [esp + 0x28]
// 00693d9d  51                   push ecx
// 00693d9e  ebaa                 jmp 0x693d4a
// 00693da0  8b442428             mov eax, dword ptr [esp + 0x28]
// 00693da4  8b542418             mov edx, dword ptr [esp + 0x18]
// 00693da8  5f                   pop edi
// 00693da9  8930                 mov dword ptr [eax], esi
// 00693dab  5e                   pop esi
// 00693dac  5d                   pop ebp
// 00693dad  895004               mov dword ptr [eax + 4], edx
// 00693db0  c6400800             mov byte ptr [eax + 8], 0
// 00693db4  5b                   pop ebx
// 00693db5  83c414               add esp, 0x14
// 00693db8  c20800               ret 8
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
