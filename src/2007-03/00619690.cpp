// from server: 100% by auto
// roc 2007-03 00619690  unit: seg_00610000  size: 709 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00619690
//
// 00619690  64a100000000         mov eax, dword ptr fs:[0]
// 00619696  6aff                 push -1
// 00619698  68926f7500           push 0x756f92
// 0061969d  50                   push eax
// 0061969e  64892500000000       mov dword ptr fs:[0], esp
// 006196a5  8b442418             mov eax, dword ptr [esp + 0x18]
// 006196a9  83ec48               sub esp, 0x48
// 006196ac  80782900             cmp byte ptr [eax + 0x29], 0
// 006196b0  55                   push ebp
// 006196b1  8be9                 mov ebp, ecx
// 006196b3  7459                 je 0x61970e
// 006196b5  68dc3e7800           push 0x783edc
// 006196ba  8d4c240c             lea ecx, [esp + 0xc]
// 006196be  ff1578e77700         call dword ptr [0x77e778]
// 006196c4  8d4c2424             lea ecx, [esp + 0x24]
// 006196c8  c744245400000000     mov dword ptr [esp + 0x54], 0
// 006196d0  ff1560e97700         call dword ptr [0x77e960]
// 006196d6  8d442408             lea eax, [esp + 8]
// 006196da  50                   push eax
// 006196db  8d4c2434             lea ecx, [esp + 0x34]
// 006196df  c644245801           mov byte ptr [esp + 0x58], 1
// 006196e4  c7442428383e7800     mov dword ptr [esp + 0x28], 0x783e38
// 006196ec  ff157ce77700         call dword ptr [0x77e77c]
// 006196f2  68ccf38300           push 0x83f3cc
// 006196f7  8d4c2428             lea ecx, [esp + 0x28]
// 006196fb  51                   push ecx
// 006196fc  c644245c00           mov byte ptr [esp + 0x5c], 0
// 00619701  c744242c503e7800     mov dword ptr [esp + 0x2c], 0x783e50
// 00619709  e820590000           call 0x61f02e
// 0061970e  53                   push ebx
// 0061970f  56                   push esi
// 00619710  8bd8                 mov ebx, eax
// 00619712  57                   push edi
// 00619713  8d4c246c             lea ecx, [esp + 0x6c]
// 00619717  895c2410             mov dword ptr [esp + 0x10], ebx
// 0061971b  e820b5eaff           call 0x4c4c40
// 00619720  8b03                 mov eax, dword ptr [ebx]
// 00619722  80782900             cmp byte ptr [eax + 0x29], 0
// 00619726  7405                 je 0x61972d
// 00619728  8b7b08               mov edi, dword ptr [ebx + 8]
// 0061972b  eb18                 jmp 0x619745
// 0061972d  8b5308               mov edx, dword ptr [ebx + 8]
// 00619730  807a2900             cmp byte ptr [edx + 0x29], 0
// 00619734  7404                 je 0x61973a
// 00619736  8bf8                 mov edi, eax
// 00619738  eb0b                 jmp 0x619745
// 0061973a  8b4c2470             mov ecx, dword ptr [esp + 0x70]
// 0061973e  3bcb                 cmp ecx, ebx
// 00619740  8b7908               mov edi, dword ptr [ecx + 8]
// 00619743  756b                 jne 0x6197b0
// 00619745  807f2900             cmp byte ptr [edi + 0x29], 0
// 00619749  8b7304               mov esi, dword ptr [ebx + 4]
// 0061974c  7503                 jne 0x619751
// 0061974e  897704               mov dword ptr [edi + 4], esi
// 00619751  8b4504               mov eax, dword ptr [ebp + 4]
// 00619754  395804               cmp dword ptr [eax + 4], ebx
// 00619757  7505                 jne 0x61975e
// 00619759  897804               mov dword ptr [eax + 4], edi
// 0061975c  eb0b                 jmp 0x619769
// 0061975e  391e                 cmp dword ptr [esi], ebx
// 00619760  7504                 jne 0x619766
// 00619762  893e                 mov dword ptr [esi], edi
// 00619764  eb03                 jmp 0x619769
// 00619766  897e08               mov dword ptr [esi + 8], edi
// 00619769  8b5d04               mov ebx, dword ptr [ebp + 4]
// 0061976c  8b03                 mov eax, dword ptr [ebx]
// 0061976e  3b442410             cmp eax, dword ptr [esp + 0x10]
// 00619772  7515                 jne 0x619789
// 00619774  807f2900             cmp byte ptr [edi + 0x29], 0
// 00619778  7404                 je 0x61977e
// 0061977a  8bc6                 mov eax, esi
// 0061977c  eb09                 jmp 0x619787
// 0061977e  57                   push edi
// 0061977f  e8ecedffff           call 0x618570
// 00619784  83c404               add esp, 4
// 00619787  8903                 mov dword ptr [ebx], eax
// 00619789  8b5d04               mov ebx, dword ptr [ebp + 4]
// 0061978c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00619790  394b08               cmp dword ptr [ebx + 8], ecx
// 00619793  7572                 jne 0x619807
// 00619795  807f2900             cmp byte ptr [edi + 0x29], 0
// 00619799  7407                 je 0x6197a2
// 0061979b  8bc6                 mov eax, esi
// 0061979d  894308               mov dword ptr [ebx + 8], eax
// 006197a0  eb65                 jmp 0x619807
// 006197a2  57                   push edi
// 006197a3  e838afeaff           call 0x4c46e0
// 006197a8  83c404               add esp, 4
// 006197ab  894308               mov dword ptr [ebx + 8], eax
// 006197ae  eb57                 jmp 0x619807
// 006197b0  894804               mov dword ptr [eax + 4], ecx
// 006197b3  8b13                 mov edx, dword ptr [ebx]
// 006197b5  8911                 mov dword ptr [ecx], edx
// 006197b7  3b4b08               cmp ecx, dword ptr [ebx + 8]
// 006197ba  7504                 jne 0x6197c0
// 006197bc  8bf1                 mov esi, ecx
// 006197be  eb1a                 jmp 0x6197da
// 006197c0  807f2900             cmp byte ptr [edi + 0x29], 0
// 006197c4  8b7104               mov esi, dword ptr [ecx + 4]
// 006197c7  7503                 jne 0x6197cc
// 006197c9  897704               mov dword ptr [edi + 4], esi
// 006197cc  893e                 mov dword ptr [esi], edi
// 006197ce  8b4308               mov eax, dword ptr [ebx + 8]
// 006197d1  894108               mov dword ptr [ecx + 8], eax
// 006197d4  8b5308               mov edx, dword ptr [ebx + 8]
// 006197d7  894a04               mov dword ptr [edx + 4], ecx
// 006197da  8b4504               mov eax, dword ptr [ebp + 4]
// 006197dd  395804               cmp dword ptr [eax + 4], ebx
// 006197e0  7505                 jne 0x6197e7
// 006197e2  894804               mov dword ptr [eax + 4], ecx
// 006197e5  eb0e                 jmp 0x6197f5
// 006197e7  8b4304               mov eax, dword ptr [ebx + 4]
// 006197ea  3918                 cmp dword ptr [eax], ebx
// 006197ec  7504                 jne 0x6197f2
// 006197ee  8908                 mov dword ptr [eax], ecx
// 006197f0  eb03                 jmp 0x6197f5
// 006197f2  894808               mov dword ptr [eax + 8], ecx
// 006197f5  8b4304               mov eax, dword ptr [ebx + 4]
// 006197f8  894104               mov dword ptr [ecx + 4], eax
// 006197fb  8a5328               mov dl, byte ptr [ebx + 0x28]
// 006197fe  8a4128               mov al, byte ptr [ecx + 0x28]
// 00619801  885128               mov byte ptr [ecx + 0x28], dl
// 00619804  884328               mov byte ptr [ebx + 0x28], al
// 00619807  8b442410             mov eax, dword ptr [esp + 0x10]
// 0061980b  b301                 mov bl, 1
// 0061980d  385828               cmp byte ptr [eax + 0x28], bl
// 00619810  0f85f2000000         jne 0x619908
// 00619816  8b4d04               mov ecx, dword ptr [ebp + 4]
// 00619819  3b7904               cmp edi, dword ptr [ecx + 4]
// 0061981c  0f84e3000000         je 0x619905
// 00619822  385f28               cmp byte ptr [edi + 0x28], bl
// 00619825  0f85da000000         jne 0x619905
// 0061982b  8b06                 mov eax, dword ptr [esi]
// 0061982d  3bf8                 cmp edi, eax
// 0061982f  7563                 jne 0x619894
// 00619831  8b4608               mov eax, dword ptr [esi + 8]
// 00619834  80782800             cmp byte ptr [eax + 0x28], 0
// 00619838  7512                 jne 0x61984c
// 0061983a  885828               mov byte ptr [eax + 0x28], bl
// 0061983d  56                   push esi
// 0061983e  8bcd                 mov ecx, ebp
// 00619840  c6462800             mov byte ptr [esi + 0x28], 0
// 00619844  e8a7b3eaff           call 0x4c4bf0
// 00619849  8b4608               mov eax, dword ptr [esi + 8]
// 0061984c  80782900             cmp byte ptr [eax + 0x29], 0
// 00619850  7572                 jne 0x6198c4
// 00619852  8b10                 mov edx, dword ptr [eax]
// 00619854  385a28               cmp byte ptr [edx + 0x28], bl
// 00619857  7508                 jne 0x619861
// 00619859  8b4808               mov ecx, dword ptr [eax + 8]
// 0061985c  385928               cmp byte ptr [ecx + 0x28], bl
// 0061985f  745f                 je 0x6198c0
// 00619861  8b4808               mov ecx, dword ptr [eax + 8]
// 00619864  385928               cmp byte ptr [ecx + 0x28], bl
// 00619867  7512                 jne 0x61987b
// 00619869  885a28               mov byte ptr [edx + 0x28], bl
// 0061986c  50                   push eax
// 0061986d  8bcd                 mov ecx, ebp
// 0061986f  c6402800             mov byte ptr [eax + 0x28], 0
// 00619873  e808aeeaff           call 0x4c4680
// 00619878  8b4608               mov eax, dword ptr [esi + 8]
// 0061987b  8a4e28               mov cl, byte ptr [esi + 0x28]
// 0061987e  884828               mov byte ptr [eax + 0x28], cl
// 00619881  885e28               mov byte ptr [esi + 0x28], bl
// 00619884  8b5008               mov edx, dword ptr [eax + 8]
// 00619887  56                   push esi
// 00619888  8bcd                 mov ecx, ebp
// 0061988a  885a28               mov byte ptr [edx + 0x28], bl
// 0061988d  e85eb3eaff           call 0x4c4bf0
// 00619892  eb71                 jmp 0x619905
// 00619894  80782800             cmp byte ptr [eax + 0x28], 0
// 00619898  7511                 jne 0x6198ab
// 0061989a  885828               mov byte ptr [eax + 0x28], bl
// 0061989d  56                   push esi
// 0061989e  8bcd                 mov ecx, ebp
// 006198a0  c6462800             mov byte ptr [esi + 0x28], 0
// 006198a4  e8d7adeaff           call 0x4c4680
// 006198a9  8b06                 mov eax, dword ptr [esi]
// 006198ab  80782900             cmp byte ptr [eax + 0x29], 0
// 006198af  7513                 jne 0x6198c4
// 006198b1  8b5008               mov edx, dword ptr [eax + 8]
// 006198b4  385a28               cmp byte ptr [edx + 0x28], bl
// 006198b7  751e                 jne 0x6198d7
// 006198b9  8b08                 mov ecx, dword ptr [eax]
// 006198bb  385928               cmp byte ptr [ecx + 0x28], bl
// 006198be  7517                 jne 0x6198d7
// 006198c0  c6402800             mov byte ptr [eax + 0x28], 0
// 006198c4  8b5504               mov edx, dword ptr [ebp + 4]
// 006198c7  8bfe                 mov edi, esi
// 006198c9  3b7a04               cmp edi, dword ptr [edx + 4]
// 006198cc  8b7604               mov esi, dword ptr [esi + 4]
// 006198cf  0f854dffffff         jne 0x619822
// 006198d5  eb2e                 jmp 0x619905
// 006198d7  8b08                 mov ecx, dword ptr [eax]
// 006198d9  385928               cmp byte ptr [ecx + 0x28], bl
// 006198dc  7511                 jne 0x6198ef
// 006198de  885a28               mov byte ptr [edx + 0x28], bl
// 006198e1  50                   push eax
// 006198e2  8bcd                 mov ecx, ebp
// 006198e4  c6402800             mov byte ptr [eax + 0x28], 0
// 006198e8  e803b3eaff           call 0x4c4bf0
// 006198ed  8b06                 mov eax, dword ptr [esi]
// 006198ef  8a4e28               mov cl, byte ptr [esi + 0x28]
// 006198f2  884828               mov byte ptr [eax + 0x28], cl
// 006198f5  885e28               mov byte ptr [esi + 0x28], bl
// 006198f8  8b10                 mov edx, dword ptr [eax]
// 006198fa  56                   push esi
// 006198fb  8bcd                 mov ecx, ebp
// 006198fd  885a28               mov byte ptr [edx + 0x28], bl
// 00619900  e87badeaff           call 0x4c4680
// 00619905  885f28               mov byte ptr [edi + 0x28], bl
// 00619908  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0061990c  83c10c               add ecx, 0xc
// 0061990f  ff158ce77700         call dword ptr [0x77e78c]
// 00619915  8b442410             mov eax, dword ptr [esp + 0x10]
// 00619919  50                   push eax
// 0061991a  e8d1470000           call 0x61e0f0
// 0061991f  8b4508               mov eax, dword ptr [ebp + 8]
// 00619922  83c404               add esp, 4
// 00619925  85c0                 test eax, eax
// 00619927  5f                   pop edi
// 00619928  5e                   pop esi
// 00619929  5b                   pop ebx
// 0061992a  7606                 jbe 0x619932
// 0061992c  83c0ff               add eax, -1
// 0061992f  894508               mov dword ptr [ebp + 8], eax
// 00619932  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 00619936  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0061993a  8b542464             mov edx, dword ptr [esp + 0x64]
// 0061993e  8908                 mov dword ptr [eax], ecx
// 00619940  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00619944  895004               mov dword ptr [eax + 4], edx
// 00619947  5d                   pop ebp
// 00619948  64890d00000000       mov dword ptr fs:[0], ecx
// 0061994f  83c454               add esp, 0x54
// 00619952  c20c00               ret 0xc
// standard library set<string> (function ?erase@?$_Tree@V?$_Tset_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@V312@@Z)

// stl: set<string>
#include <string>
typedef std::string E;
#include <set>
template class std::set<E>;
