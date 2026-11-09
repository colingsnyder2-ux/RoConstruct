// from server: 100% by auto
// roc 2010-06 00772220  unit: RBX::ScoreHud  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00772220
//
// 00772220  83ec14               sub esp, 0x14
// 00772223  56                   push esi
// 00772224  8bf1                 mov esi, ecx
// 00772226  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 0077222a  57                   push edi
// 0077222b  7521                 jne 0x77224e
// 0077222d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00772231  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 00772234  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00772238  50                   push eax
// 00772239  51                   push ecx
// 0077223a  6a01                 push 1
// 0077223c  57                   push edi
// 0077223d  8bce                 mov ecx, esi
// 0077223f  e8bce9ffff           call 0x770c00
// 00772244  8bc7                 mov eax, edi
// 00772246  5f                   pop edi
// 00772247  5e                   pop esi
// 00772248  83c414               add esp, 0x14
// 0077224b  c21000               ret 0x10
// 0077224e  8b442424             mov eax, dword ptr [esp + 0x24]
// 00772252  8b5618               mov edx, dword ptr [esi + 0x18]
// 00772255  8b3a                 mov edi, dword ptr [edx]
// 00772257  8b0e                 mov ecx, dword ptr [esi]
// 00772259  53                   push ebx
// 0077225a  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 00772260  85c0                 test eax, eax
// 00772262  7404                 je 0x772268
// 00772264  3bc1                 cmp eax, ecx
// 00772266  7406                 je 0x77226e
// 00772268  ffd3                 call ebx
// 0077226a  8b442428             mov eax, dword ptr [esp + 0x28]
// 0077226e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 00772272  55                   push ebp
// 00772273  3bd7                 cmp edx, edi
// 00772275  753a                 jne 0x7722b1
// 00772277  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 0077227b  83c20c               add edx, 0xc
// 0077227e  52                   push edx
// 0077227f  57                   push edi
// 00772280  ff151ca59e00         call dword ptr [0x9ea51c]
// 00772286  83c408               add esp, 8
// 00772289  84c0                 test al, al
// 0077228b  0f849a010000         je 0x77242b
// 00772291  8b442430             mov eax, dword ptr [esp + 0x30]
// 00772295  57                   push edi
// 00772296  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0077229a  50                   push eax
// 0077229b  6a01                 push 1
// 0077229d  57                   push edi
// 0077229e  8bce                 mov ecx, esi
// 007722a0  e85be9ffff           call 0x770c00
// 007722a5  5d                   pop ebp
// 007722a6  5b                   pop ebx
// 007722a7  8bc7                 mov eax, edi
// 007722a9  5f                   pop edi
// 007722aa  5e                   pop esi
// 007722ab  83c414               add esp, 0x14
// 007722ae  c21000               ret 0x10
// 007722b1  8b7e18               mov edi, dword ptr [esi + 0x18]
// 007722b4  8b0e                 mov ecx, dword ptr [esi]
// 007722b6  85c0                 test eax, eax
// 007722b8  7404                 je 0x7722be
// 007722ba  3bc1                 cmp eax, ecx
// 007722bc  7406                 je 0x7722c4
// 007722be  ffd3                 call ebx
// 007722c0  8b542430             mov edx, dword ptr [esp + 0x30]
// 007722c4  3bd7                 cmp edx, edi
// 007722c6  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 007722ca  753e                 jne 0x77230a
// 007722cc  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007722cf  8b4108               mov eax, dword ptr [ecx + 8]
// 007722d2  83c00c               add eax, 0xc
// 007722d5  57                   push edi
// 007722d6  50                   push eax
// 007722d7  ff151ca59e00         call dword ptr [0x9ea51c]
// 007722dd  83c408               add esp, 8
// 007722e0  84c0                 test al, al
// 007722e2  0f8443010000         je 0x77242b
// 007722e8  8b5618               mov edx, dword ptr [esi + 0x18]
// 007722eb  8b4208               mov eax, dword ptr [edx + 8]
// 007722ee  57                   push edi
// 007722ef  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 007722f3  50                   push eax
// 007722f4  6a00                 push 0
// 007722f6  57                   push edi
// 007722f7  8bce                 mov ecx, esi
// 007722f9  e802e9ffff           call 0x770c00
// 007722fe  5d                   pop ebp
// 007722ff  5b                   pop ebx
// 00772300  8bc7                 mov eax, edi
// 00772302  5f                   pop edi
// 00772303  5e                   pop esi
// 00772304  83c414               add esp, 0x14
// 00772307  c21000               ret 0x10
// 0077230a  8b2d1ca59e00         mov ebp, dword ptr [0x9ea51c]
// 00772310  83c20c               add edx, 0xc
// 00772313  52                   push edx
// 00772314  57                   push edi
// 00772315  ffd5                 call ebp
// 00772317  83c408               add esp, 8
// 0077231a  84c0                 test al, al
// 0077231c  746c                 je 0x77238a
// 0077231e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 00772322  8b542430             mov edx, dword ptr [esp + 0x30]
// 00772326  894c2410             mov dword ptr [esp + 0x10], ecx
// 0077232a  8d4c2410             lea ecx, [esp + 0x10]
// 0077232e  89542414             mov dword ptr [esp + 0x14], edx
// 00772332  e8f975e7ff           call 0x5e9930
// 00772337  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0077233b  57                   push edi
// 0077233c  8d430c               lea eax, [ebx + 0xc]
// 0077233f  50                   push eax
// 00772340  8d4e08               lea ecx, [esi + 8]
// 00772343  e8080fd0ff           call 0x473250
// 00772348  84c0                 test al, al
// 0077234a  743e                 je 0x77238a
// 0077234c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 0077234f  80794900             cmp byte ptr [ecx + 0x49], 0
// 00772353  57                   push edi
// 00772354  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00772358  8bce                 mov ecx, esi
// 0077235a  7415                 je 0x772371
// 0077235c  53                   push ebx
// 0077235d  6a00                 push 0
// 0077235f  57                   push edi
// 00772360  e89be8ffff           call 0x770c00
// 00772365  5d                   pop ebp
// 00772366  5b                   pop ebx
// 00772367  8bc7                 mov eax, edi
// 00772369  5f                   pop edi
// 0077236a  5e                   pop esi
// 0077236b  83c414               add esp, 0x14
// 0077236e  c21000               ret 0x10
// 00772371  8b542434             mov edx, dword ptr [esp + 0x34]
// 00772375  52                   push edx
// 00772376  6a01                 push 1
// 00772378  57                   push edi
// 00772379  e882e8ffff           call 0x770c00
// 0077237e  5d                   pop ebp
// 0077237f  5b                   pop ebx
// 00772380  8bc7                 mov eax, edi
// 00772382  5f                   pop edi
// 00772383  5e                   pop esi
// 00772384  83c414               add esp, 0x14
// 00772387  c21000               ret 0x10
// 0077238a  8b442430             mov eax, dword ptr [esp + 0x30]
// 0077238e  83c00c               add eax, 0xc
// 00772391  57                   push edi
// 00772392  50                   push eax
// 00772393  ffd5                 call ebp
// 00772395  83c408               add esp, 8
// 00772398  84c0                 test al, al
// 0077239a  0f848b000000         je 0x77242b
// 007723a0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007723a4  8b542430             mov edx, dword ptr [esp + 0x30]
// 007723a8  8b4618               mov eax, dword ptr [esi + 0x18]
// 007723ab  894c2410             mov dword ptr [esp + 0x10], ecx
// 007723af  8b0e                 mov ecx, dword ptr [esi]
// 007723b1  894c2418             mov dword ptr [esp + 0x18], ecx
// 007723b5  8d4c2410             lea ecx, [esp + 0x10]
// 007723b9  89542414             mov dword ptr [esp + 0x14], edx
// 007723bd  8944241c             mov dword ptr [esp + 0x1c], eax
// 007723c1  e87a92e9ff           call 0x60b640
// 007723c6  8d542418             lea edx, [esp + 0x18]
// 007723ca  52                   push edx
// 007723cb  8d4c2414             lea ecx, [esp + 0x14]
// 007723cf  e8ac4bcfff           call 0x466f80
// 007723d4  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 007723d8  84c0                 test al, al
// 007723da  7511                 jne 0x7723ed
// 007723dc  8d430c               lea eax, [ebx + 0xc]
// 007723df  50                   push eax
// 007723e0  57                   push edi
// 007723e1  8d4e08               lea ecx, [esi + 8]
// 007723e4  e8670ed0ff           call 0x473250
// 007723e9  84c0                 test al, al
// 007723eb  743e                 je 0x77242b
// 007723ed  8b442430             mov eax, dword ptr [esp + 0x30]
// 007723f1  8b4808               mov ecx, dword ptr [eax + 8]
// 007723f4  80794900             cmp byte ptr [ecx + 0x49], 0
// 007723f8  57                   push edi
// 007723f9  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 007723fd  8bce                 mov ecx, esi
// 007723ff  7415                 je 0x772416
// 00772401  50                   push eax
// 00772402  6a00                 push 0
// 00772404  57                   push edi
// 00772405  e8f6e7ffff           call 0x770c00
// 0077240a  5d                   pop ebp
// 0077240b  5b                   pop ebx
// 0077240c  8bc7                 mov eax, edi
// 0077240e  5f                   pop edi
// 0077240f  5e                   pop esi
// 00772410  83c414               add esp, 0x14
// 00772413  c21000               ret 0x10
// 00772416  53                   push ebx
// 00772417  6a01                 push 1
// 00772419  57                   push edi
// 0077241a  e8e1e7ffff           call 0x770c00
// 0077241f  5d                   pop ebp
// 00772420  5b                   pop ebx
// 00772421  8bc7                 mov eax, edi
// 00772423  5f                   pop edi
// 00772424  5e                   pop esi
// 00772425  83c414               add esp, 0x14
// 00772428  c21000               ret 0x10
// 0077242b  57                   push edi
// 0077242c  8d54241c             lea edx, [esp + 0x1c]
// 00772430  52                   push edx
// 00772431  8bce                 mov ecx, esi
// 00772433  e8d8f3ffff           call 0x771810
// 00772438  8b10                 mov edx, dword ptr [eax]
// 0077243a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0077243e  5d                   pop ebp
// 0077243f  5b                   pop ebx
// 00772440  8911                 mov dword ptr [ecx], edx
// 00772442  8b4004               mov eax, dword ptr [eax + 4]
// 00772445  5f                   pop edi
// 00772446  894104               mov dword ptr [ecx + 4], eax
// 00772449  8bc1                 mov eax, ecx
// 0077244b  5e                   pop esi
// 0077244c  83c414               add esp, 0x14
// 0077244f  c21000               ret 0x10
// standard library map_str<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
