// from server: 100% by auto
// roc 2008-06 0055eed0  unit: RBX::VContentProvider::?$DescribedNonCreatable  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055eed0
//
// 0055eed0  83ec14               sub esp, 0x14
// 0055eed3  53                   push ebx
// 0055eed4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0055eed8  55                   push ebp
// 0055eed9  56                   push esi
// 0055eeda  8be9                 mov ebp, ecx
// 0055eedc  57                   push edi
// 0055eedd  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 0055eee0  8b7704               mov esi, dword ptr [edi + 4]
// 0055eee3  807e3d00             cmp byte ptr [esi + 0x3d], 0
// 0055eee7  b001                 mov al, 1
// 0055eee9  88442410             mov byte ptr [esp + 0x10], al
// 0055eeed  7526                 jne 0x55ef15
// 0055eeef  90                   nop 
// 0055eef0  8d460c               lea eax, [esi + 0xc]
// 0055eef3  50                   push eax
// 0055eef4  53                   push ebx
// 0055eef5  8bfe                 mov edi, esi
// 0055eef7  ff155c238000         call dword ptr [0x80235c]
// 0055eefd  83c408               add esp, 8
// 0055ef00  88442410             mov byte ptr [esp + 0x10], al
// 0055ef04  84c0                 test al, al
// 0055ef06  7404                 je 0x55ef0c
// 0055ef08  8b36                 mov esi, dword ptr [esi]
// 0055ef0a  eb03                 jmp 0x55ef0f
// 0055ef0c  8b7608               mov esi, dword ptr [esi + 8]
// 0055ef0f  807e3d00             cmp byte ptr [esi + 0x3d], 0
// 0055ef13  74db                 je 0x55eef0
// 0055ef15  8b7500               mov esi, dword ptr [ebp]
// 0055ef18  897c2418             mov dword ptr [esp + 0x18], edi
// 0055ef1c  89742414             mov dword ptr [esp + 0x14], esi
// 0055ef20  84c0                 test al, al
// 0055ef22  7458                 je 0x55ef7c
// 0055ef24  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 0055ef27  8b11                 mov edx, dword ptr [ecx]
// 0055ef29  89542420             mov dword ptr [esp + 0x20], edx
// 0055ef2d  85f6                 test esi, esi
// 0055ef2f  7404                 je 0x55ef35
// 0055ef31  3bf6                 cmp esi, esi
// 0055ef33  7406                 je 0x55ef3b
// 0055ef35  ff1590288000         call dword ptr [0x802890]
// 0055ef3b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 0055ef3f  752e                 jne 0x55ef6f
// 0055ef41  53                   push ebx
// 0055ef42  57                   push edi
// 0055ef43  6a01                 push 1
// 0055ef45  8d442428             lea eax, [esp + 0x28]
// 0055ef49  50                   push eax
// 0055ef4a  8bcd                 mov ecx, ebp
// 0055ef4c  e87ff9ffff           call 0x55e8d0
// 0055ef51  5f                   pop edi
// 0055ef52  8bc8                 mov ecx, eax
// 0055ef54  8b11                 mov edx, dword ptr [ecx]
// 0055ef56  8b442424             mov eax, dword ptr [esp + 0x24]
// 0055ef5a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0055ef5d  5e                   pop esi
// 0055ef5e  5d                   pop ebp
// 0055ef5f  8910                 mov dword ptr [eax], edx
// 0055ef61  894804               mov dword ptr [eax + 4], ecx
// 0055ef64  c6400801             mov byte ptr [eax + 8], 1
// 0055ef68  5b                   pop ebx
// 0055ef69  83c414               add esp, 0x14
// 0055ef6c  c20800               ret 8
// 0055ef6f  8d4c2414             lea ecx, [esp + 0x14]
// 0055ef73  e8a8dbffff           call 0x55cb20
// 0055ef78  8b742414             mov esi, dword ptr [esp + 0x14]
// 0055ef7c  8b542418             mov edx, dword ptr [esp + 0x18]
// 0055ef80  83c20c               add edx, 0xc
// 0055ef83  53                   push ebx
// 0055ef84  52                   push edx
// 0055ef85  ff155c238000         call dword ptr [0x80235c]
// 0055ef8b  83c408               add esp, 8
// 0055ef8e  84c0                 test al, al
// 0055ef90  740e                 je 0x55efa0
// 0055ef92  8b442410             mov eax, dword ptr [esp + 0x10]
// 0055ef96  53                   push ebx
// 0055ef97  57                   push edi
// 0055ef98  50                   push eax
// 0055ef99  8d4c2428             lea ecx, [esp + 0x28]
// 0055ef9d  51                   push ecx
// 0055ef9e  ebaa                 jmp 0x55ef4a
// 0055efa0  8b442428             mov eax, dword ptr [esp + 0x28]
// 0055efa4  8b542418             mov edx, dword ptr [esp + 0x18]
// 0055efa8  5f                   pop edi
// 0055efa9  8930                 mov dword ptr [eax], esi
// 0055efab  5e                   pop esi
// 0055efac  5d                   pop ebp
// 0055efad  895004               mov dword ptr [eax + 4], edx
// 0055efb0  c6400800             mov byte ptr [eax + 8], 0
// 0055efb4  5b                   pop ebx
// 0055efb5  83c414               add esp, 0x14
// 0055efb8  c20800               ret 8
// standard library map_str<pod20> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod20>
struct E { int v[5]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
