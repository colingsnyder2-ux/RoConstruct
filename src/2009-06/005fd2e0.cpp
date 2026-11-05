// from server: 100% by auto
// roc 2009-06 005fd2e0  unit: RBX::VInstance::?$NonFactoryProduct  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005fd2e0
//
// 005fd2e0  83ec14               sub esp, 0x14
// 005fd2e3  53                   push ebx
// 005fd2e4  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 005fd2e8  55                   push ebp
// 005fd2e9  56                   push esi
// 005fd2ea  8be9                 mov ebp, ecx
// 005fd2ec  57                   push edi
// 005fd2ed  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 005fd2f0  8b7704               mov esi, dword ptr [edi + 4]
// 005fd2f3  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 005fd2f7  b001                 mov al, 1
// 005fd2f9  88442410             mov byte ptr [esp + 0x10], al
// 005fd2fd  7526                 jne 0x5fd325
// 005fd2ff  90                   nop 
// 005fd300  8d460c               lea eax, [esi + 0xc]
// 005fd303  50                   push eax
// 005fd304  53                   push ebx
// 005fd305  8bfe                 mov edi, esi
// 005fd307  ff15e0e48900         call dword ptr [0x89e4e0]
// 005fd30d  83c408               add esp, 8
// 005fd310  88442410             mov byte ptr [esp + 0x10], al
// 005fd314  84c0                 test al, al
// 005fd316  7404                 je 0x5fd31c
// 005fd318  8b36                 mov esi, dword ptr [esi]
// 005fd31a  eb03                 jmp 0x5fd31f
// 005fd31c  8b7608               mov esi, dword ptr [esi + 8]
// 005fd31f  807e2d00             cmp byte ptr [esi + 0x2d], 0
// 005fd323  74db                 je 0x5fd300
// 005fd325  8b7500               mov esi, dword ptr [ebp]
// 005fd328  897c2418             mov dword ptr [esp + 0x18], edi
// 005fd32c  89742414             mov dword ptr [esp + 0x14], esi
// 005fd330  84c0                 test al, al
// 005fd332  7458                 je 0x5fd38c
// 005fd334  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 005fd337  8b11                 mov edx, dword ptr [ecx]
// 005fd339  89542420             mov dword ptr [esp + 0x20], edx
// 005fd33d  85f6                 test esi, esi
// 005fd33f  7404                 je 0x5fd345
// 005fd341  3bf6                 cmp esi, esi
// 005fd343  7406                 je 0x5fd34b
// 005fd345  ff15ace98900         call dword ptr [0x89e9ac]
// 005fd34b  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 005fd34f  752e                 jne 0x5fd37f
// 005fd351  53                   push ebx
// 005fd352  57                   push edi
// 005fd353  6a01                 push 1
// 005fd355  8d442428             lea eax, [esp + 0x28]
// 005fd359  50                   push eax
// 005fd35a  8bcd                 mov ecx, ebp
// 005fd35c  e8cff4ffff           call 0x5fc830
// 005fd361  5f                   pop edi
// 005fd362  8bc8                 mov ecx, eax
// 005fd364  8b11                 mov edx, dword ptr [ecx]
// 005fd366  8b442424             mov eax, dword ptr [esp + 0x24]
// 005fd36a  8b4904               mov ecx, dword ptr [ecx + 4]
// 005fd36d  5e                   pop esi
// 005fd36e  5d                   pop ebp
// 005fd36f  8910                 mov dword ptr [eax], edx
// 005fd371  894804               mov dword ptr [eax + 4], ecx
// 005fd374  c6400801             mov byte ptr [eax + 8], 1
// 005fd378  5b                   pop ebx
// 005fd379  83c414               add esp, 0x14
// 005fd37c  c20800               ret 8
// 005fd37f  8d4c2414             lea ecx, [esp + 0x14]
// 005fd383  e8c8e1ffff           call 0x5fb550
// 005fd388  8b742414             mov esi, dword ptr [esp + 0x14]
// 005fd38c  8b542418             mov edx, dword ptr [esp + 0x18]
// 005fd390  83c20c               add edx, 0xc
// 005fd393  53                   push ebx
// 005fd394  52                   push edx
// 005fd395  ff15e0e48900         call dword ptr [0x89e4e0]
// 005fd39b  83c408               add esp, 8
// 005fd39e  84c0                 test al, al
// 005fd3a0  740e                 je 0x5fd3b0
// 005fd3a2  8b442410             mov eax, dword ptr [esp + 0x10]
// 005fd3a6  53                   push ebx
// 005fd3a7  57                   push edi
// 005fd3a8  50                   push eax
// 005fd3a9  8d4c2428             lea ecx, [esp + 0x28]
// 005fd3ad  51                   push ecx
// 005fd3ae  ebaa                 jmp 0x5fd35a
// 005fd3b0  8b442428             mov eax, dword ptr [esp + 0x28]
// 005fd3b4  8b542418             mov edx, dword ptr [esp + 0x18]
// 005fd3b8  5f                   pop edi
// 005fd3b9  8930                 mov dword ptr [eax], esi
// 005fd3bb  5e                   pop esi
// 005fd3bc  5d                   pop ebp
// 005fd3bd  895004               mov dword ptr [eax + 4], edx
// 005fd3c0  c6400800             mov byte ptr [eax + 8], 0
// 005fd3c4  5b                   pop ebx
// 005fd3c5  83c414               add esp, 0x14
// 005fd3c8  c20800               ret 8
// standard library map_str<ptr> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@PAUT@@@2@@Z)

// stl: map_str<ptr>
struct T; typedef T* E;
#include <map>
#include <string>
template class std::map<std::string, E>;
