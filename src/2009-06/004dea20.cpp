// from server: 100% by auto
// roc 2009-06 004dea20  unit: RBX::Network::IdSerializer  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004dea20
//
// 004dea20  83ec14               sub esp, 0x14
// 004dea23  53                   push ebx
// 004dea24  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 004dea28  55                   push ebp
// 004dea29  56                   push esi
// 004dea2a  8be9                 mov ebp, ecx
// 004dea2c  57                   push edi
// 004dea2d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 004dea30  8b7704               mov esi, dword ptr [edi + 4]
// 004dea33  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 004dea37  b001                 mov al, 1
// 004dea39  88442410             mov byte ptr [esp + 0x10], al
// 004dea3d  7526                 jne 0x4dea65
// 004dea3f  90                   nop 
// 004dea40  8d460c               lea eax, [esi + 0xc]
// 004dea43  50                   push eax
// 004dea44  53                   push ebx
// 004dea45  8bfe                 mov edi, esi
// 004dea47  ff15e0e48900         call dword ptr [0x89e4e0]
// 004dea4d  83c408               add esp, 8
// 004dea50  88442410             mov byte ptr [esp + 0x10], al
// 004dea54  84c0                 test al, al
// 004dea56  7404                 je 0x4dea5c
// 004dea58  8b36                 mov esi, dword ptr [esi]
// 004dea5a  eb03                 jmp 0x4dea5f
// 004dea5c  8b7608               mov esi, dword ptr [esi + 8]
// 004dea5f  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 004dea63  74db                 je 0x4dea40
// 004dea65  8b7500               mov esi, dword ptr [ebp]
// 004dea68  897c2418             mov dword ptr [esp + 0x18], edi
// 004dea6c  89742414             mov dword ptr [esp + 0x14], esi
// 004dea70  84c0                 test al, al
// 004dea72  7458                 je 0x4deacc
// 004dea74  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 004dea77  8b11                 mov edx, dword ptr [ecx]
// 004dea79  89542420             mov dword ptr [esp + 0x20], edx
// 004dea7d  85f6                 test esi, esi
// 004dea7f  7404                 je 0x4dea85
// 004dea81  3bf6                 cmp esi, esi
// 004dea83  7406                 je 0x4dea8b
// 004dea85  ff15ace98900         call dword ptr [0x89e9ac]
// 004dea8b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 004dea8f  752e                 jne 0x4deabf
// 004dea91  53                   push ebx
// 004dea92  57                   push edi
// 004dea93  6a01                 push 1
// 004dea95  8d442428             lea eax, [esp + 0x28]
// 004dea99  50                   push eax
// 004dea9a  8bcd                 mov ecx, ebp
// 004dea9c  e85ffcffff           call 0x4de700
// 004deaa1  5f                   pop edi
// 004deaa2  8bc8                 mov ecx, eax
// 004deaa4  8b11                 mov edx, dword ptr [ecx]
// 004deaa6  8b442424             mov eax, dword ptr [esp + 0x24]
// 004deaaa  8b4904               mov ecx, dword ptr [ecx + 4]
// 004deaad  5e                   pop esi
// 004deaae  5d                   pop ebp
// 004deaaf  8910                 mov dword ptr [eax], edx
// 004deab1  894804               mov dword ptr [eax + 4], ecx
// 004deab4  c6400801             mov byte ptr [eax + 8], 1
// 004deab8  5b                   pop ebx
// 004deab9  83c414               add esp, 0x14
// 004deabc  c20800               ret 8
// 004deabf  8d4c2414             lea ecx, [esp + 0x14]
// 004deac3  e888ca1100           call 0x5fb550
// 004deac8  8b742414             mov esi, dword ptr [esp + 0x14]
// 004deacc  8b542418             mov edx, dword ptr [esp + 0x18]
// 004dead0  83c20c               add edx, 0xc
// 004dead3  53                   push ebx
// 004dead4  52                   push edx
// 004dead5  ff15e0e48900         call dword ptr [0x89e4e0]
// 004deadb  83c408               add esp, 8
// 004deade  84c0                 test al, al
// 004deae0  740e                 je 0x4deaf0
// 004deae2  8b442410             mov eax, dword ptr [esp + 0x10]
// 004deae6  53                   push ebx
// 004deae7  57                   push edi
// 004deae8  50                   push eax
// 004deae9  8d4c2428             lea ecx, [esp + 0x28]
// 004deaed  51                   push ecx
// 004deaee  ebaa                 jmp 0x4dea9a
// 004deaf0  8b442428             mov eax, dword ptr [esp + 0x28]
// 004deaf4  8b542418             mov edx, dword ptr [esp + 0x18]
// 004deaf8  5f                   pop edi
// 004deaf9  8930                 mov dword ptr [eax], esi
// 004deafb  5e                   pop esi
// 004deafc  5d                   pop ebp
// 004deafd  895004               mov dword ptr [eax + 4], edx
// 004deb00  c6400800             mov byte ptr [eax + 8], 0
// 004deb04  5b                   pop ebx
// 004deb05  83c414               add esp, 0x14
// 004deb08  c20800               ret 8
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
