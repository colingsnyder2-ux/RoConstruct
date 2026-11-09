// from server: 100% by auto
// roc 2008-06 0055ffc0  unit: RBX::VContentProvider::?$DescribedNonCreatable  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0055ffc0
//
// 0055ffc0  83ec14               sub esp, 0x14
// 0055ffc3  56                   push esi
// 0055ffc4  8bf1                 mov esi, ecx
// 0055ffc6  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0055ffca  57                   push edi
// 0055ffcb  7521                 jne 0x55ffee
// 0055ffcd  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0055ffd1  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0055ffd4  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 0055ffd8  50                   push eax
// 0055ffd9  51                   push ecx
// 0055ffda  6a01                 push 1
// 0055ffdc  57                   push edi
// 0055ffdd  8bce                 mov ecx, esi
// 0055ffdf  e8ece8ffff           call 0x55e8d0
// 0055ffe4  8bc7                 mov eax, edi
// 0055ffe6  5f                   pop edi
// 0055ffe7  5e                   pop esi
// 0055ffe8  83c414               add esp, 0x14
// 0055ffeb  c21000               ret 0x10
// 0055ffee  8b442424             mov eax, dword ptr [esp + 0x24]
// 0055fff2  8b5618               mov edx, dword ptr [esi + 0x18]
// 0055fff5  8b3a                 mov edi, dword ptr [edx]
// 0055fff7  8b0e                 mov ecx, dword ptr [esi]
// 0055fff9  53                   push ebx
// 0055fffa  8b1d90288000         mov ebx, dword ptr [0x802890]
// 00560000  85c0                 test eax, eax
// 00560002  7404                 je 0x560008
// 00560004  3bc1                 cmp eax, ecx
// 00560006  7406                 je 0x56000e
// 00560008  ffd3                 call ebx
// 0056000a  8b442428             mov eax, dword ptr [esp + 0x28]
// 0056000e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00560012  55                   push ebp
// 00560013  3bd7                 cmp edx, edi
// 00560015  753a                 jne 0x560051
// 00560017  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0056001b  83c20c               add edx, 0xc
// 0056001e  52                   push edx
// 0056001f  57                   push edi
// 00560020  ff155c238000         call dword ptr [0x80235c]
// 00560026  83c408               add esp, 8
// 00560029  84c0                 test al, al
// 0056002b  0f849a010000         je 0x5601cb
// 00560031  8b442430             mov eax, dword ptr [esp + 0x30]
// 00560035  57                   push edi
// 00560036  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0056003a  50                   push eax
// 0056003b  6a01                 push 1
// 0056003d  57                   push edi
// 0056003e  8bce                 mov ecx, esi
// 00560040  e88be8ffff           call 0x55e8d0
// 00560045  5d                   pop ebp
// 00560046  5b                   pop ebx
// 00560047  8bc7                 mov eax, edi
// 00560049  5f                   pop edi
// 0056004a  5e                   pop esi
// 0056004b  83c414               add esp, 0x14
// 0056004e  c21000               ret 0x10
// 00560051  8b7e18               mov edi, dword ptr [esi + 0x18]
// 00560054  8b0e                 mov ecx, dword ptr [esi]
// 00560056  85c0                 test eax, eax
// 00560058  7404                 je 0x56005e
// 0056005a  3bc1                 cmp eax, ecx
// 0056005c  7406                 je 0x560064
// 0056005e  ffd3                 call ebx
// 00560060  8b542430             mov edx, dword ptr [esp + 0x30]
// 00560064  3bd7                 cmp edx, edi
// 00560066  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0056006a  753e                 jne 0x5600aa
// 0056006c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 0056006f  8b4108               mov eax, dword ptr [ecx + 8]
// 00560072  83c00c               add eax, 0xc
// 00560075  57                   push edi
// 00560076  50                   push eax
// 00560077  ff155c238000         call dword ptr [0x80235c]
// 0056007d  83c408               add esp, 8
// 00560080  84c0                 test al, al
// 00560082  0f8443010000         je 0x5601cb
// 00560088  8b5618               mov edx, dword ptr [esi + 0x18]
// 0056008b  8b4208               mov eax, dword ptr [edx + 8]
// 0056008e  57                   push edi
// 0056008f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00560093  50                   push eax
// 00560094  6a00                 push 0
// 00560096  57                   push edi
// 00560097  8bce                 mov ecx, esi
// 00560099  e832e8ffff           call 0x55e8d0
// 0056009e  5d                   pop ebp
// 0056009f  5b                   pop ebx
// 005600a0  8bc7                 mov eax, edi
// 005600a2  5f                   pop edi
// 005600a3  5e                   pop esi
// 005600a4  83c414               add esp, 0x14
// 005600a7  c21000               ret 0x10
// 005600aa  8b2d5c238000         mov ebp, dword ptr [0x80235c]
// 005600b0  83c20c               add edx, 0xc
// 005600b3  52                   push edx
// 005600b4  57                   push edi
// 005600b5  ffd5                 call ebp
// 005600b7  83c408               add esp, 8
// 005600ba  84c0                 test al, al
// 005600bc  746c                 je 0x56012a
// 005600be  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 005600c2  8b542430             mov edx, dword ptr [esp + 0x30]
// 005600c6  894c2410             mov dword ptr [esp + 0x10], ecx
// 005600ca  8d4c2410             lea ecx, [esp + 0x10]
// 005600ce  89542414             mov dword ptr [esp + 0x14], edx
// 005600d2  e849caffff           call 0x55cb20
// 005600d7  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 005600db  57                   push edi
// 005600dc  8d430c               lea eax, [ebx + 0xc]
// 005600df  50                   push eax
// 005600e0  8d4e08               lea ecx, [esi + 8]
// 005600e3  e818bfffff           call 0x55c000
// 005600e8  84c0                 test al, al
// 005600ea  743e                 je 0x56012a
// 005600ec  8b4b08               mov ecx, dword ptr [ebx + 8]
// 005600ef  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 005600f3  57                   push edi
// 005600f4  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 005600f8  8bce                 mov ecx, esi
// 005600fa  7415                 je 0x560111
// 005600fc  53                   push ebx
// 005600fd  6a00                 push 0
// 005600ff  57                   push edi
// 00560100  e8cbe7ffff           call 0x55e8d0
// 00560105  5d                   pop ebp
// 00560106  5b                   pop ebx
// 00560107  8bc7                 mov eax, edi
// 00560109  5f                   pop edi
// 0056010a  5e                   pop esi
// 0056010b  83c414               add esp, 0x14
// 0056010e  c21000               ret 0x10
// 00560111  8b542434             mov edx, dword ptr [esp + 0x34]
// 00560115  52                   push edx
// 00560116  6a01                 push 1
// 00560118  57                   push edi
// 00560119  e8b2e7ffff           call 0x55e8d0
// 0056011e  5d                   pop ebp
// 0056011f  5b                   pop ebx
// 00560120  8bc7                 mov eax, edi
// 00560122  5f                   pop edi
// 00560123  5e                   pop esi
// 00560124  83c414               add esp, 0x14
// 00560127  c21000               ret 0x10
// 0056012a  8b442430             mov eax, dword ptr [esp + 0x30]
// 0056012e  83c00c               add eax, 0xc
// 00560131  57                   push edi
// 00560132  50                   push eax
// 00560133  ffd5                 call ebp
// 00560135  83c408               add esp, 8
// 00560138  84c0                 test al, al
// 0056013a  0f848b000000         je 0x5601cb
// 00560140  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00560144  8b542430             mov edx, dword ptr [esp + 0x30]
// 00560148  8b4618               mov eax, dword ptr [esi + 0x18]
// 0056014b  894c2410             mov dword ptr [esp + 0x10], ecx
// 0056014f  8b0e                 mov ecx, dword ptr [esi]
// 00560151  894c2418             mov dword ptr [esp + 0x18], ecx
// 00560155  8d4c2410             lea ecx, [esp + 0x10]
// 00560159  89542414             mov dword ptr [esp + 0x14], edx
// 0056015d  8944241c             mov dword ptr [esp + 0x1c], eax
// 00560161  e8bac8ffff           call 0x55ca20
// 00560166  8d542418             lea edx, [esp + 0x18]
// 0056016a  52                   push edx
// 0056016b  8d4c2414             lea ecx, [esp + 0x14]
// 0056016f  e82ccb0800           call 0x5ecca0
// 00560174  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 00560178  84c0                 test al, al
// 0056017a  7511                 jne 0x56018d
// 0056017c  8d430c               lea eax, [ebx + 0xc]
// 0056017f  50                   push eax
// 00560180  57                   push edi
// 00560181  8d4e08               lea ecx, [esi + 8]
// 00560184  e877beffff           call 0x55c000
// 00560189  84c0                 test al, al
// 0056018b  743e                 je 0x5601cb
// 0056018d  8b442430             mov eax, dword ptr [esp + 0x30]
// 00560191  8b4808               mov ecx, dword ptr [eax + 8]
// 00560194  80793d00             cmp byte ptr [ecx + 0x3d], 0
// 00560198  57                   push edi
// 00560199  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0056019d  8bce                 mov ecx, esi
// 0056019f  7415                 je 0x5601b6
// 005601a1  50                   push eax
// 005601a2  6a00                 push 0
// 005601a4  57                   push edi
// 005601a5  e826e7ffff           call 0x55e8d0
// 005601aa  5d                   pop ebp
// 005601ab  5b                   pop ebx
// 005601ac  8bc7                 mov eax, edi
// 005601ae  5f                   pop edi
// 005601af  5e                   pop esi
// 005601b0  83c414               add esp, 0x14
// 005601b3  c21000               ret 0x10
// 005601b6  53                   push ebx
// 005601b7  6a01                 push 1
// 005601b9  57                   push edi
// 005601ba  e811e7ffff           call 0x55e8d0
// 005601bf  5d                   pop ebp
// 005601c0  5b                   pop ebx
// 005601c1  8bc7                 mov eax, edi
// 005601c3  5f                   pop edi
// 005601c4  5e                   pop esi
// 005601c5  83c414               add esp, 0x14
// 005601c8  c21000               ret 0x10
// 005601cb  57                   push edi
// 005601cc  8d54241c             lea edx, [esp + 0x1c]
// 005601d0  52                   push edx
// 005601d1  8bce                 mov ecx, esi
// 005601d3  e8f8ecffff           call 0x55eed0
// 005601d8  8b10                 mov edx, dword ptr [eax]
// 005601da  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005601de  5d                   pop ebp
// 005601df  5b                   pop ebx
// 005601e0  8911                 mov dword ptr [ecx], edx
// 005601e2  8b4004               mov eax, dword ptr [eax + 4]
// 005601e5  5f                   pop edi
// 005601e6  894104               mov dword ptr [ecx + 4], eax
// 005601e9  8bc1                 mov eax, ecx
// 005601eb  5e                   pop esi
// 005601ec  83c414               add esp, 0x14
// 005601ef  c21000               ret 0x10
// standard library map_str<pod20> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod20>
struct E { int v[5]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
