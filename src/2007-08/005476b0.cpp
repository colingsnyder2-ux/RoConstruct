// from server: 100% by auto
// roc 2007-08 005476b0  unit: RBX::MD5HasherImpl  size: 518 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005476b0
//
// 005476b0  83ec0c               sub esp, 0xc
// 005476b3  56                   push esi
// 005476b4  8bf1                 mov esi, ecx
// 005476b6  837e0800             cmp dword ptr [esi + 8], 0
// 005476ba  57                   push edi
// 005476bb  7521                 jne 0x5476de
// 005476bd  8b442424             mov eax, dword ptr [esp + 0x24]
// 005476c1  8b4e04               mov ecx, dword ptr [esi + 4]
// 005476c4  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 005476c8  50                   push eax
// 005476c9  51                   push ecx
// 005476ca  6a01                 push 1
// 005476cc  57                   push edi
// 005476cd  8bce                 mov ecx, esi
// 005476cf  e86cf4ffff           call 0x546b40
// 005476d4  8bc7                 mov eax, edi
// 005476d6  5f                   pop edi
// 005476d7  5e                   pop esi
// 005476d8  83c40c               add esp, 0xc
// 005476db  c21000               ret 0x10
// 005476de  8b5604               mov edx, dword ptr [esi + 4]
// 005476e1  8b3a                 mov edi, dword ptr [edx]
// 005476e3  55                   push ebp
// 005476e4  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 005476e8  85ed                 test ebp, ebp
// 005476ea  7404                 je 0x5476f0
// 005476ec  3bee                 cmp ebp, esi
// 005476ee  7406                 je 0x5476f6
// 005476f0  ff15d8e67700         call dword ptr [0x77e6d8]
// 005476f6  53                   push ebx
// 005476f7  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 005476fb  3bdf                 cmp ebx, edi
// 005476fd  7536                 jne 0x547735
// 005476ff  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00547703  8d430c               lea eax, [ebx + 0xc]
// 00547706  50                   push eax
// 00547707  57                   push edi
// 00547708  ff1520e67700         call dword ptr [0x77e620]
// 0054770e  83c408               add esp, 8
// 00547711  84c0                 test al, al
// 00547713  0f8476010000         je 0x54788f
// 00547719  57                   push edi
// 0054771a  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0054771e  53                   push ebx
// 0054771f  6a01                 push 1
// 00547721  57                   push edi
// 00547722  8bce                 mov ecx, esi
// 00547724  e817f4ffff           call 0x546b40
// 00547729  5b                   pop ebx
// 0054772a  5d                   pop ebp
// 0054772b  8bc7                 mov eax, edi
// 0054772d  5f                   pop edi
// 0054772e  5e                   pop esi
// 0054772f  83c40c               add esp, 0xc
// 00547732  c21000               ret 0x10
// 00547735  85ed                 test ebp, ebp
// 00547737  8b7e04               mov edi, dword ptr [esi + 4]
// 0054773a  7404                 je 0x547740
// 0054773c  3bee                 cmp ebp, esi
// 0054773e  7406                 je 0x547746
// 00547740  ff15d8e67700         call dword ptr [0x77e6d8]
// 00547746  3bdf                 cmp ebx, edi
// 00547748  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0054774c  753e                 jne 0x54778c
// 0054774e  8b4e04               mov ecx, dword ptr [esi + 4]
// 00547751  8b4108               mov eax, dword ptr [ecx + 8]
// 00547754  83c00c               add eax, 0xc
// 00547757  57                   push edi
// 00547758  50                   push eax
// 00547759  ff1520e67700         call dword ptr [0x77e620]
// 0054775f  83c408               add esp, 8
// 00547762  84c0                 test al, al
// 00547764  0f8425010000         je 0x54788f
// 0054776a  8b5604               mov edx, dword ptr [esi + 4]
// 0054776d  8b4208               mov eax, dword ptr [edx + 8]
// 00547770  57                   push edi
// 00547771  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00547775  50                   push eax
// 00547776  6a00                 push 0
// 00547778  57                   push edi
// 00547779  8bce                 mov ecx, esi
// 0054777b  e8c0f3ffff           call 0x546b40
// 00547780  5b                   pop ebx
// 00547781  5d                   pop ebp
// 00547782  8bc7                 mov eax, edi
// 00547784  5f                   pop edi
// 00547785  5e                   pop esi
// 00547786  83c40c               add esp, 0xc
// 00547789  c21000               ret 0x10
// 0054778c  8d430c               lea eax, [ebx + 0xc]
// 0054778f  50                   push eax
// 00547790  57                   push edi
// 00547791  ff1520e67700         call dword ptr [0x77e620]
// 00547797  83c408               add esp, 8
// 0054779a  84c0                 test al, al
// 0054779c  7463                 je 0x547801
// 0054779e  8d4c2424             lea ecx, [esp + 0x24]
// 005477a2  896c2424             mov dword ptr [esp + 0x24], ebp
// 005477a6  895c2428             mov dword ptr [esp + 0x28], ebx
// 005477aa  e8f1dbffff           call 0x5453a0
// 005477af  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005477b3  83c10c               add ecx, 0xc
// 005477b6  57                   push edi
// 005477b7  51                   push ecx
// 005477b8  8bce                 mov ecx, esi
// 005477ba  e841d6efff           call 0x444e00
// 005477bf  84c0                 test al, al
// 005477c1  743e                 je 0x547801
// 005477c3  8b442428             mov eax, dword ptr [esp + 0x28]
// 005477c7  8b5008               mov edx, dword ptr [eax + 8]
// 005477ca  807a3d00             cmp byte ptr [edx + 0x3d], 0
// 005477ce  57                   push edi
// 005477cf  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 005477d3  8bce                 mov ecx, esi
// 005477d5  7415                 je 0x5477ec
// 005477d7  50                   push eax
// 005477d8  6a00                 push 0
// 005477da  57                   push edi
// 005477db  e860f3ffff           call 0x546b40
// 005477e0  5b                   pop ebx
// 005477e1  5d                   pop ebp
// 005477e2  8bc7                 mov eax, edi
// 005477e4  5f                   pop edi
// 005477e5  5e                   pop esi
// 005477e6  83c40c               add esp, 0xc
// 005477e9  c21000               ret 0x10
// 005477ec  53                   push ebx
// 005477ed  6a01                 push 1
// 005477ef  57                   push edi
// 005477f0  e84bf3ffff           call 0x546b40
// 005477f5  5b                   pop ebx
// 005477f6  5d                   pop ebp
// 005477f7  8bc7                 mov eax, edi
// 005477f9  5f                   pop edi
// 005477fa  5e                   pop esi
// 005477fb  83c40c               add esp, 0xc
// 005477fe  c21000               ret 0x10
// 00547801  8d430c               lea eax, [ebx + 0xc]
// 00547804  57                   push edi
// 00547805  50                   push eax
// 00547806  ff1520e67700         call dword ptr [0x77e620]
// 0054780c  83c408               add esp, 8
// 0054780f  84c0                 test al, al
// 00547811  747c                 je 0x54788f
// 00547813  8b4604               mov eax, dword ptr [esi + 4]
// 00547816  8d4c2424             lea ecx, [esp + 0x24]
// 0054781a  896c2424             mov dword ptr [esp + 0x24], ebp
// 0054781e  895c2428             mov dword ptr [esp + 0x28], ebx
// 00547822  89442414             mov dword ptr [esp + 0x14], eax
// 00547826  89742410             mov dword ptr [esp + 0x10], esi
// 0054782a  e801dcffff           call 0x545430
// 0054782f  8d4c2410             lea ecx, [esp + 0x10]
// 00547833  51                   push ecx
// 00547834  8d4c2428             lea ecx, [esp + 0x28]
// 00547838  e873f2f1ff           call 0x466ab0
// 0054783d  84c0                 test al, al
// 0054783f  8b6c2428             mov ebp, dword ptr [esp + 0x28]
// 00547843  7510                 jne 0x547855
// 00547845  8d550c               lea edx, [ebp + 0xc]
// 00547848  52                   push edx
// 00547849  57                   push edi
// 0054784a  8bce                 mov ecx, esi
// 0054784c  e8afd5efff           call 0x444e00
// 00547851  84c0                 test al, al
// 00547853  743a                 je 0x54788f
// 00547855  8b4308               mov eax, dword ptr [ebx + 8]
// 00547858  80783d00             cmp byte ptr [eax + 0x3d], 0
// 0054785c  57                   push edi
// 0054785d  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 00547861  8bce                 mov ecx, esi
// 00547863  7415                 je 0x54787a
// 00547865  53                   push ebx
// 00547866  6a00                 push 0
// 00547868  57                   push edi
// 00547869  e8d2f2ffff           call 0x546b40
// 0054786e  5b                   pop ebx
// 0054786f  5d                   pop ebp
// 00547870  8bc7                 mov eax, edi
// 00547872  5f                   pop edi
// 00547873  5e                   pop esi
// 00547874  83c40c               add esp, 0xc
// 00547877  c21000               ret 0x10
// 0054787a  55                   push ebp
// 0054787b  6a01                 push 1
// 0054787d  57                   push edi
// 0054787e  e8bdf2ffff           call 0x546b40
// 00547883  5b                   pop ebx
// 00547884  5d                   pop ebp
// 00547885  8bc7                 mov eax, edi
// 00547887  5f                   pop edi
// 00547888  5e                   pop esi
// 00547889  83c40c               add esp, 0xc
// 0054788c  c21000               ret 0x10
// 0054788f  57                   push edi
// 00547890  8d4c2414             lea ecx, [esp + 0x14]
// 00547894  51                   push ecx
// 00547895  8bce                 mov ecx, esi
// 00547897  e874f9ffff           call 0x547210
// 0054789c  8b10                 mov edx, dword ptr [eax]
// 0054789e  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 005478a2  5b                   pop ebx
// 005478a3  5d                   pop ebp
// 005478a4  8911                 mov dword ptr [ecx], edx
// 005478a6  8b4004               mov eax, dword ptr [eax + 4]
// 005478a9  5f                   pop edi
// 005478aa  894104               mov dword ptr [ecx + 4], eax
// 005478ad  8bc1                 mov eax, ecx
// 005478af  5e                   pop esi
// 005478b0  83c40c               add esp, 0xc
// 005478b3  c21000               ret 0x10
// standard library map_str<pod20> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@V312@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod20>
struct E { int v[5]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
