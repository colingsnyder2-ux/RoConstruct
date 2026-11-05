// from server: 100% by auto
// roc 2010-06 008c8350  unit: RBX::AdornRbxGfx  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008c8350
//
// 008c8350  83ec14               sub esp, 0x14
// 008c8353  56                   push esi
// 008c8354  8bf1                 mov esi, ecx
// 008c8356  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 008c835a  57                   push edi
// 008c835b  7521                 jne 0x8c837e
// 008c835d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 008c8361  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 008c8364  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 008c8368  50                   push eax
// 008c8369  51                   push ecx
// 008c836a  6a01                 push 1
// 008c836c  57                   push edi
// 008c836d  8bce                 mov ecx, esi
// 008c836f  e89cf2ffff           call 0x8c7610
// 008c8374  8bc7                 mov eax, edi
// 008c8376  5f                   pop edi
// 008c8377  5e                   pop esi
// 008c8378  83c414               add esp, 0x14
// 008c837b  c21000               ret 0x10
// 008c837e  8b442424             mov eax, dword ptr [esp + 0x24]
// 008c8382  8b5618               mov edx, dword ptr [esi + 0x18]
// 008c8385  8b3a                 mov edi, dword ptr [edx]
// 008c8387  8b0e                 mov ecx, dword ptr [esi]
// 008c8389  53                   push ebx
// 008c838a  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 008c8390  85c0                 test eax, eax
// 008c8392  7404                 je 0x8c8398
// 008c8394  3bc1                 cmp eax, ecx
// 008c8396  7406                 je 0x8c839e
// 008c8398  ffd3                 call ebx
// 008c839a  8b442428             mov eax, dword ptr [esp + 0x28]
// 008c839e  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 008c83a2  55                   push ebp
// 008c83a3  3bd7                 cmp edx, edi
// 008c83a5  753a                 jne 0x8c83e1
// 008c83a7  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 008c83ab  83c20c               add edx, 0xc
// 008c83ae  52                   push edx
// 008c83af  57                   push edi
// 008c83b0  ff151ca59e00         call dword ptr [0x9ea51c]
// 008c83b6  83c408               add esp, 8
// 008c83b9  84c0                 test al, al
// 008c83bb  0f849a010000         je 0x8c855b
// 008c83c1  8b442430             mov eax, dword ptr [esp + 0x30]
// 008c83c5  57                   push edi
// 008c83c6  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 008c83ca  50                   push eax
// 008c83cb  6a01                 push 1
// 008c83cd  57                   push edi
// 008c83ce  8bce                 mov ecx, esi
// 008c83d0  e83bf2ffff           call 0x8c7610
// 008c83d5  5d                   pop ebp
// 008c83d6  5b                   pop ebx
// 008c83d7  8bc7                 mov eax, edi
// 008c83d9  5f                   pop edi
// 008c83da  5e                   pop esi
// 008c83db  83c414               add esp, 0x14
// 008c83de  c21000               ret 0x10
// 008c83e1  8b7e18               mov edi, dword ptr [esi + 0x18]
// 008c83e4  8b0e                 mov ecx, dword ptr [esi]
// 008c83e6  85c0                 test eax, eax
// 008c83e8  7404                 je 0x8c83ee
// 008c83ea  3bc1                 cmp eax, ecx
// 008c83ec  7406                 je 0x8c83f4
// 008c83ee  ffd3                 call ebx
// 008c83f0  8b542430             mov edx, dword ptr [esp + 0x30]
// 008c83f4  3bd7                 cmp edx, edi
// 008c83f6  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 008c83fa  753e                 jne 0x8c843a
// 008c83fc  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 008c83ff  8b4108               mov eax, dword ptr [ecx + 8]
// 008c8402  83c00c               add eax, 0xc
// 008c8405  57                   push edi
// 008c8406  50                   push eax
// 008c8407  ff151ca59e00         call dword ptr [0x9ea51c]
// 008c840d  83c408               add esp, 8
// 008c8410  84c0                 test al, al
// 008c8412  0f8443010000         je 0x8c855b
// 008c8418  8b5618               mov edx, dword ptr [esi + 0x18]
// 008c841b  8b4208               mov eax, dword ptr [edx + 8]
// 008c841e  57                   push edi
// 008c841f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 008c8423  50                   push eax
// 008c8424  6a00                 push 0
// 008c8426  57                   push edi
// 008c8427  8bce                 mov ecx, esi
// 008c8429  e8e2f1ffff           call 0x8c7610
// 008c842e  5d                   pop ebp
// 008c842f  5b                   pop ebx
// 008c8430  8bc7                 mov eax, edi
// 008c8432  5f                   pop edi
// 008c8433  5e                   pop esi
// 008c8434  83c414               add esp, 0x14
// 008c8437  c21000               ret 0x10
// 008c843a  8b2d1ca59e00         mov ebp, dword ptr [0x9ea51c]
// 008c8440  83c20c               add edx, 0xc
// 008c8443  52                   push edx
// 008c8444  57                   push edi
// 008c8445  ffd5                 call ebp
// 008c8447  83c408               add esp, 8
// 008c844a  84c0                 test al, al
// 008c844c  746c                 je 0x8c84ba
// 008c844e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 008c8452  8b542430             mov edx, dword ptr [esp + 0x30]
// 008c8456  894c2410             mov dword ptr [esp + 0x10], ecx
// 008c845a  8d4c2410             lea ecx, [esp + 0x10]
// 008c845e  89542414             mov dword ptr [esp + 0x14], edx
// 008c8462  e8f9e8ffff           call 0x8c6d60
// 008c8467  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 008c846b  57                   push edi
// 008c846c  8d430c               lea eax, [ebx + 0xc]
// 008c846f  50                   push eax
// 008c8470  8d4e08               lea ecx, [esi + 8]
// 008c8473  e8d8adbaff           call 0x473250
// 008c8478  84c0                 test al, al
// 008c847a  743e                 je 0x8c84ba
// 008c847c  8b4b08               mov ecx, dword ptr [ebx + 8]
// 008c847f  80793900             cmp byte ptr [ecx + 0x39], 0
// 008c8483  57                   push edi
// 008c8484  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 008c8488  8bce                 mov ecx, esi
// 008c848a  7415                 je 0x8c84a1
// 008c848c  53                   push ebx
// 008c848d  6a00                 push 0
// 008c848f  57                   push edi
// 008c8490  e87bf1ffff           call 0x8c7610
// 008c8495  5d                   pop ebp
// 008c8496  5b                   pop ebx
// 008c8497  8bc7                 mov eax, edi
// 008c8499  5f                   pop edi
// 008c849a  5e                   pop esi
// 008c849b  83c414               add esp, 0x14
// 008c849e  c21000               ret 0x10
// 008c84a1  8b542434             mov edx, dword ptr [esp + 0x34]
// 008c84a5  52                   push edx
// 008c84a6  6a01                 push 1
// 008c84a8  57                   push edi
// 008c84a9  e862f1ffff           call 0x8c7610
// 008c84ae  5d                   pop ebp
// 008c84af  5b                   pop ebx
// 008c84b0  8bc7                 mov eax, edi
// 008c84b2  5f                   pop edi
// 008c84b3  5e                   pop esi
// 008c84b4  83c414               add esp, 0x14
// 008c84b7  c21000               ret 0x10
// 008c84ba  8b442430             mov eax, dword ptr [esp + 0x30]
// 008c84be  83c00c               add eax, 0xc
// 008c84c1  57                   push edi
// 008c84c2  50                   push eax
// 008c84c3  ffd5                 call ebp
// 008c84c5  83c408               add esp, 8
// 008c84c8  84c0                 test al, al
// 008c84ca  0f848b000000         je 0x8c855b
// 008c84d0  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 008c84d4  8b542430             mov edx, dword ptr [esp + 0x30]
// 008c84d8  8b4618               mov eax, dword ptr [esi + 0x18]
// 008c84db  894c2410             mov dword ptr [esp + 0x10], ecx
// 008c84df  8b0e                 mov ecx, dword ptr [esi]
// 008c84e1  894c2418             mov dword ptr [esp + 0x18], ecx
// 008c84e5  8d4c2410             lea ecx, [esp + 0x10]
// 008c84e9  89542414             mov dword ptr [esp + 0x14], edx
// 008c84ed  8944241c             mov dword ptr [esp + 0x1c], eax
// 008c84f1  e8fae8ffff           call 0x8c6df0
// 008c84f6  8d542418             lea edx, [esp + 0x18]
// 008c84fa  52                   push edx
// 008c84fb  8d4c2414             lea ecx, [esp + 0x14]
// 008c84ff  e87ceab9ff           call 0x466f80
// 008c8504  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 008c8508  84c0                 test al, al
// 008c850a  7511                 jne 0x8c851d
// 008c850c  8d430c               lea eax, [ebx + 0xc]
// 008c850f  50                   push eax
// 008c8510  57                   push edi
// 008c8511  8d4e08               lea ecx, [esi + 8]
// 008c8514  e837adbaff           call 0x473250
// 008c8519  84c0                 test al, al
// 008c851b  743e                 je 0x8c855b
// 008c851d  8b442430             mov eax, dword ptr [esp + 0x30]
// 008c8521  8b4808               mov ecx, dword ptr [eax + 8]
// 008c8524  80793900             cmp byte ptr [ecx + 0x39], 0
// 008c8528  57                   push edi
// 008c8529  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 008c852d  8bce                 mov ecx, esi
// 008c852f  7415                 je 0x8c8546
// 008c8531  50                   push eax
// 008c8532  6a00                 push 0
// 008c8534  57                   push edi
// 008c8535  e8d6f0ffff           call 0x8c7610
// 008c853a  5d                   pop ebp
// 008c853b  5b                   pop ebx
// 008c853c  8bc7                 mov eax, edi
// 008c853e  5f                   pop edi
// 008c853f  5e                   pop esi
// 008c8540  83c414               add esp, 0x14
// 008c8543  c21000               ret 0x10
// 008c8546  53                   push ebx
// 008c8547  6a01                 push 1
// 008c8549  57                   push edi
// 008c854a  e8c1f0ffff           call 0x8c7610
// 008c854f  5d                   pop ebp
// 008c8550  5b                   pop ebx
// 008c8551  8bc7                 mov eax, edi
// 008c8553  5f                   pop edi
// 008c8554  5e                   pop esi
// 008c8555  83c414               add esp, 0x14
// 008c8558  c21000               ret 0x10
// 008c855b  57                   push edi
// 008c855c  8d54241c             lea edx, [esp + 0x1c]
// 008c8560  52                   push edx
// 008c8561  8bce                 mov ecx, esi
// 008c8563  e8f8fcffff           call 0x8c8260
// 008c8568  8b10                 mov edx, dword ptr [eax]
// 008c856a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008c856e  5d                   pop ebp
// 008c856f  5b                   pop ebx
// 008c8570  8911                 mov dword ptr [ecx], edx
// 008c8572  8b4004               mov eax, dword ptr [eax + 4]
// 008c8575  5f                   pop edi
// 008c8576  894104               mov dword ptr [ecx + 4], eax
// 008c8579  8bc1                 mov eax, ecx
// 008c857b  5e                   pop esi
// 008c857c  83c414               add esp, 0x14
// 008c857f  c21000               ret 0x10
// standard library map_str<pod16> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod16>
struct E { int v[4]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
