// from server: 100% by auto
// roc 2009-12 007c9180  unit: RBX::ScoreHud  size: 562 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007c9180
//
// 007c9180  83ec14               sub esp, 0x14
// 007c9183  56                   push esi
// 007c9184  8bf1                 mov esi, ecx
// 007c9186  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 007c918a  57                   push edi
// 007c918b  7521                 jne 0x7c91ae
// 007c918d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007c9191  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007c9194  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 007c9198  50                   push eax
// 007c9199  51                   push ecx
// 007c919a  6a01                 push 1
// 007c919c  57                   push edi
// 007c919d  8bce                 mov ecx, esi
// 007c919f  e8bce9ffff           call 0x7c7b60
// 007c91a4  8bc7                 mov eax, edi
// 007c91a6  5f                   pop edi
// 007c91a7  5e                   pop esi
// 007c91a8  83c414               add esp, 0x14
// 007c91ab  c21000               ret 0x10
// 007c91ae  8b442424             mov eax, dword ptr [esp + 0x24]
// 007c91b2  8b5618               mov edx, dword ptr [esi + 0x18]
// 007c91b5  8b3a                 mov edi, dword ptr [edx]
// 007c91b7  8b0e                 mov ecx, dword ptr [esi]
// 007c91b9  53                   push ebx
// 007c91ba  8b1d60b79800         mov ebx, dword ptr [0x98b760]
// 007c91c0  85c0                 test eax, eax
// 007c91c2  7404                 je 0x7c91c8
// 007c91c4  3bc1                 cmp eax, ecx
// 007c91c6  7406                 je 0x7c91ce
// 007c91c8  ffd3                 call ebx
// 007c91ca  8b442428             mov eax, dword ptr [esp + 0x28]
// 007c91ce  8b54242c             mov edx, dword ptr [esp + 0x2c]
// 007c91d2  55                   push ebp
// 007c91d3  3bd7                 cmp edx, edi
// 007c91d5  753a                 jne 0x7c9211
// 007c91d7  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 007c91db  83c20c               add edx, 0xc
// 007c91de  52                   push edx
// 007c91df  57                   push edi
// 007c91e0  ff15d8b59800         call dword ptr [0x98b5d8]
// 007c91e6  83c408               add esp, 8
// 007c91e9  84c0                 test al, al
// 007c91eb  0f849a010000         je 0x7c938b
// 007c91f1  8b442430             mov eax, dword ptr [esp + 0x30]
// 007c91f5  57                   push edi
// 007c91f6  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 007c91fa  50                   push eax
// 007c91fb  6a01                 push 1
// 007c91fd  57                   push edi
// 007c91fe  8bce                 mov ecx, esi
// 007c9200  e85be9ffff           call 0x7c7b60
// 007c9205  5d                   pop ebp
// 007c9206  5b                   pop ebx
// 007c9207  8bc7                 mov eax, edi
// 007c9209  5f                   pop edi
// 007c920a  5e                   pop esi
// 007c920b  83c414               add esp, 0x14
// 007c920e  c21000               ret 0x10
// 007c9211  8b7e18               mov edi, dword ptr [esi + 0x18]
// 007c9214  8b0e                 mov ecx, dword ptr [esi]
// 007c9216  85c0                 test eax, eax
// 007c9218  7404                 je 0x7c921e
// 007c921a  3bc1                 cmp eax, ecx
// 007c921c  7406                 je 0x7c9224
// 007c921e  ffd3                 call ebx
// 007c9220  8b542430             mov edx, dword ptr [esp + 0x30]
// 007c9224  3bd7                 cmp edx, edi
// 007c9226  8b7c2434             mov edi, dword ptr [esp + 0x34]
// 007c922a  753e                 jne 0x7c926a
// 007c922c  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 007c922f  8b4108               mov eax, dword ptr [ecx + 8]
// 007c9232  83c00c               add eax, 0xc
// 007c9235  57                   push edi
// 007c9236  50                   push eax
// 007c9237  ff15d8b59800         call dword ptr [0x98b5d8]
// 007c923d  83c408               add esp, 8
// 007c9240  84c0                 test al, al
// 007c9242  0f8443010000         je 0x7c938b
// 007c9248  8b5618               mov edx, dword ptr [esi + 0x18]
// 007c924b  8b4208               mov eax, dword ptr [edx + 8]
// 007c924e  57                   push edi
// 007c924f  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 007c9253  50                   push eax
// 007c9254  6a00                 push 0
// 007c9256  57                   push edi
// 007c9257  8bce                 mov ecx, esi
// 007c9259  e802e9ffff           call 0x7c7b60
// 007c925e  5d                   pop ebp
// 007c925f  5b                   pop ebx
// 007c9260  8bc7                 mov eax, edi
// 007c9262  5f                   pop edi
// 007c9263  5e                   pop esi
// 007c9264  83c414               add esp, 0x14
// 007c9267  c21000               ret 0x10
// 007c926a  8b2dd8b59800         mov ebp, dword ptr [0x98b5d8]
// 007c9270  83c20c               add edx, 0xc
// 007c9273  52                   push edx
// 007c9274  57                   push edi
// 007c9275  ffd5                 call ebp
// 007c9277  83c408               add esp, 8
// 007c927a  84c0                 test al, al
// 007c927c  746c                 je 0x7c92ea
// 007c927e  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007c9282  8b542430             mov edx, dword ptr [esp + 0x30]
// 007c9286  894c2410             mov dword ptr [esp + 0x10], ecx
// 007c928a  8d4c2410             lea ecx, [esp + 0x10]
// 007c928e  89542414             mov dword ptr [esp + 0x14], edx
// 007c9292  e8e995ebff           call 0x682880
// 007c9297  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 007c929b  57                   push edi
// 007c929c  8d430c               lea eax, [ebx + 0xc]
// 007c929f  50                   push eax
// 007c92a0  8d4e08               lea ecx, [esi + 8]
// 007c92a3  e8a815cbff           call 0x47a850
// 007c92a8  84c0                 test al, al
// 007c92aa  743e                 je 0x7c92ea
// 007c92ac  8b4b08               mov ecx, dword ptr [ebx + 8]
// 007c92af  80794900             cmp byte ptr [ecx + 0x49], 0
// 007c92b3  57                   push edi
// 007c92b4  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 007c92b8  8bce                 mov ecx, esi
// 007c92ba  7415                 je 0x7c92d1
// 007c92bc  53                   push ebx
// 007c92bd  6a00                 push 0
// 007c92bf  57                   push edi
// 007c92c0  e89be8ffff           call 0x7c7b60
// 007c92c5  5d                   pop ebp
// 007c92c6  5b                   pop ebx
// 007c92c7  8bc7                 mov eax, edi
// 007c92c9  5f                   pop edi
// 007c92ca  5e                   pop esi
// 007c92cb  83c414               add esp, 0x14
// 007c92ce  c21000               ret 0x10
// 007c92d1  8b542434             mov edx, dword ptr [esp + 0x34]
// 007c92d5  52                   push edx
// 007c92d6  6a01                 push 1
// 007c92d8  57                   push edi
// 007c92d9  e882e8ffff           call 0x7c7b60
// 007c92de  5d                   pop ebp
// 007c92df  5b                   pop ebx
// 007c92e0  8bc7                 mov eax, edi
// 007c92e2  5f                   pop edi
// 007c92e3  5e                   pop esi
// 007c92e4  83c414               add esp, 0x14
// 007c92e7  c21000               ret 0x10
// 007c92ea  8b442430             mov eax, dword ptr [esp + 0x30]
// 007c92ee  83c00c               add eax, 0xc
// 007c92f1  57                   push edi
// 007c92f2  50                   push eax
// 007c92f3  ffd5                 call ebp
// 007c92f5  83c408               add esp, 8
// 007c92f8  84c0                 test al, al
// 007c92fa  0f848b000000         je 0x7c938b
// 007c9300  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007c9304  8b542430             mov edx, dword ptr [esp + 0x30]
// 007c9308  8b4618               mov eax, dword ptr [esi + 0x18]
// 007c930b  894c2410             mov dword ptr [esp + 0x10], ecx
// 007c930f  8b0e                 mov ecx, dword ptr [esi]
// 007c9311  894c2418             mov dword ptr [esp + 0x18], ecx
// 007c9315  8d4c2410             lea ecx, [esp + 0x10]
// 007c9319  89542414             mov dword ptr [esp + 0x14], edx
// 007c931d  8944241c             mov dword ptr [esp + 0x1c], eax
// 007c9321  e84ad3ffff           call 0x7c6670
// 007c9326  8d542418             lea edx, [esp + 0x18]
// 007c932a  52                   push edx
// 007c932b  8d4c2414             lea ecx, [esp + 0x14]
// 007c932f  e82c30e0ff           call 0x5cc360
// 007c9334  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 007c9338  84c0                 test al, al
// 007c933a  7511                 jne 0x7c934d
// 007c933c  8d430c               lea eax, [ebx + 0xc]
// 007c933f  50                   push eax
// 007c9340  57                   push edi
// 007c9341  8d4e08               lea ecx, [esi + 8]
// 007c9344  e80715cbff           call 0x47a850
// 007c9349  84c0                 test al, al
// 007c934b  743e                 je 0x7c938b
// 007c934d  8b442430             mov eax, dword ptr [esp + 0x30]
// 007c9351  8b4808               mov ecx, dword ptr [eax + 8]
// 007c9354  80794900             cmp byte ptr [ecx + 0x49], 0
// 007c9358  57                   push edi
// 007c9359  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 007c935d  8bce                 mov ecx, esi
// 007c935f  7415                 je 0x7c9376
// 007c9361  50                   push eax
// 007c9362  6a00                 push 0
// 007c9364  57                   push edi
// 007c9365  e8f6e7ffff           call 0x7c7b60
// 007c936a  5d                   pop ebp
// 007c936b  5b                   pop ebx
// 007c936c  8bc7                 mov eax, edi
// 007c936e  5f                   pop edi
// 007c936f  5e                   pop esi
// 007c9370  83c414               add esp, 0x14
// 007c9373  c21000               ret 0x10
// 007c9376  53                   push ebx
// 007c9377  6a01                 push 1
// 007c9379  57                   push edi
// 007c937a  e8e1e7ffff           call 0x7c7b60
// 007c937f  5d                   pop ebp
// 007c9380  5b                   pop ebx
// 007c9381  8bc7                 mov eax, edi
// 007c9383  5f                   pop edi
// 007c9384  5e                   pop esi
// 007c9385  83c414               add esp, 0x14
// 007c9388  c21000               ret 0x10
// 007c938b  57                   push edi
// 007c938c  8d54241c             lea edx, [esp + 0x1c]
// 007c9390  52                   push edx
// 007c9391  8bce                 mov ecx, esi
// 007c9393  e8d8f3ffff           call 0x7c8770
// 007c9398  8b10                 mov edx, dword ptr [eax]
// 007c939a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007c939e  5d                   pop ebp
// 007c939f  5b                   pop ebx
// 007c93a0  8911                 mov dword ptr [ecx], edx
// 007c93a2  8b4004               mov eax, dword ptr [eax + 4]
// 007c93a5  5f                   pop edi
// 007c93a6  894104               mov dword ptr [ecx + 4], eax
// 007c93a9  8bc1                 mov eax, ecx
// 007c93ab  5e                   pop esi
// 007c93ac  83c414               add esp, 0x14
// 007c93af  c21000               ret 0x10
// standard library map_str<pod32> (function ?insert@?$_Tree@V?$_Tmap_traits@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@U?$less@V?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@@2@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@std@@@2@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@UE@@@2@@Z)

// stl: map_str<pod32>
struct E { int v[8]; };
#include <map>
#include <string>
template class std::map<std::string, E>;
