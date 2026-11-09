// from server: 100% by auto
// roc 2009-12 00704780  unit: RBX::VInstance::?$NonFactoryProduct  size: 235 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00704780
//
// 00704780  83ec14               sub esp, 0x14
// 00704783  53                   push ebx
// 00704784  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00704788  55                   push ebp
// 00704789  56                   push esi
// 0070478a  8be9                 mov ebp, ecx
// 0070478c  57                   push edi
// 0070478d  8b7d18               mov edi, dword ptr [ebp + 0x18]
// 00704790  8b7704               mov esi, dword ptr [edi + 4]
// 00704793  807e3100             cmp byte ptr [esi + 0x31], 0
// 00704797  b001                 mov al, 1
// 00704799  88442410             mov byte ptr [esp + 0x10], al
// 0070479d  7526                 jne 0x7047c5
// 0070479f  90                   nop 
// 007047a0  8d460c               lea eax, [esi + 0xc]
// 007047a3  50                   push eax
// 007047a4  53                   push ebx
// 007047a5  8bfe                 mov edi, esi
// 007047a7  ff15d8b59800         call dword ptr [0x98b5d8]
// 007047ad  83c408               add esp, 8
// 007047b0  88442410             mov byte ptr [esp + 0x10], al
// 007047b4  84c0                 test al, al
// 007047b6  7404                 je 0x7047bc
// 007047b8  8b36                 mov esi, dword ptr [esi]
// 007047ba  eb03                 jmp 0x7047bf
// 007047bc  8b7608               mov esi, dword ptr [esi + 8]
// 007047bf  807e3100             cmp byte ptr [esi + 0x31], 0
// 007047c3  74db                 je 0x7047a0
// 007047c5  8b7500               mov esi, dword ptr [ebp]
// 007047c8  897c2418             mov dword ptr [esp + 0x18], edi
// 007047cc  89742414             mov dword ptr [esp + 0x14], esi
// 007047d0  84c0                 test al, al
// 007047d2  7458                 je 0x70482c
// 007047d4  8b4d18               mov ecx, dword ptr [ebp + 0x18]
// 007047d7  8b11                 mov edx, dword ptr [ecx]
// 007047d9  89542420             mov dword ptr [esp + 0x20], edx
// 007047dd  85f6                 test esi, esi
// 007047df  7404                 je 0x7047e5
// 007047e1  3bf6                 cmp esi, esi
// 007047e3  7406                 je 0x7047eb
// 007047e5  ff1560b79800         call dword ptr [0x98b760]
// 007047eb  3b7c2420             cmp edi, dword ptr [esp + 0x20]
// 007047ef  752e                 jne 0x70481f
// 007047f1  53                   push ebx
// 007047f2  57                   push edi
// 007047f3  6a01                 push 1
// 007047f5  8d442428             lea eax, [esp + 0x28]
// 007047f9  50                   push eax
// 007047fa  8bcd                 mov ecx, ebp
// 007047fc  e87ff4ffff           call 0x703c80
// 00704801  5f                   pop edi
// 00704802  8bc8                 mov ecx, eax
// 00704804  8b11                 mov edx, dword ptr [ecx]
// 00704806  8b442424             mov eax, dword ptr [esp + 0x24]
// 0070480a  8b4904               mov ecx, dword ptr [ecx + 4]
// 0070480d  5e                   pop esi
// 0070480e  5d                   pop ebp
// 0070480f  8910                 mov dword ptr [eax], edx
// 00704811  894804               mov dword ptr [eax + 4], ecx
// 00704814  c6400801             mov byte ptr [eax + 8], 1
// 00704818  5b                   pop ebx
// 00704819  83c414               add esp, 0x14
// 0070481c  c20800               ret 8
// 0070481f  8d4c2414             lea ecx, [esp + 0x14]
// 00704823  e838f0e0ff           call 0x513860
// 00704828  8b742414             mov esi, dword ptr [esp + 0x14]
// 0070482c  8b542418             mov edx, dword ptr [esp + 0x18]
// 00704830  83c20c               add edx, 0xc
// 00704833  53                   push ebx
// 00704834  52                   push edx
// 00704835  ff15d8b59800         call dword ptr [0x98b5d8]
// 0070483b  83c408               add esp, 8
// 0070483e  84c0                 test al, al
// 00704840  740e                 je 0x704850
// 00704842  8b442410             mov eax, dword ptr [esp + 0x10]
// 00704846  53                   push ebx
// 00704847  57                   push edi
// 00704848  50                   push eax
// 00704849  8d4c2428             lea ecx, [esp + 0x28]
// 0070484d  51                   push ecx
// 0070484e  ebaa                 jmp 0x7047fa
// 00704850  8b442428             mov eax, dword ptr [esp + 0x28]
// 00704854  8b542418             mov edx, dword ptr [esp + 0x18]
// 00704858  5f                   pop edi
// 00704859  8930                 mov dword ptr [eax], esi
// 0070485b  5e                   pop esi
// 0070485c  5d                   pop ebp
// 0070485d  895004               mov dword ptr [eax + 4], edx
// 00704860  c6400800             mov byte ptr [eax + 8], 0
// 00704864  5b                   pop ebx
// 00704865  83c414               add esp, 0x14
// 00704868  c20800               ret 8
// standard library map_str<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AU?$pair@Viterator@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@_N@2@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod8>
struct E { int v[2]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
