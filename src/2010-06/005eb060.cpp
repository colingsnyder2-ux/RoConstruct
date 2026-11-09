// from server: 100% by auto
// roc 2010-06 005eb060  unit: RBX::VChangeHistoryService::?$FactoryProduct  size: 470 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005eb060
//
// 005eb060  83ec14               sub esp, 0x14
// 005eb063  56                   push esi
// 005eb064  8bf1                 mov esi, ecx
// 005eb066  837e1c00             cmp dword ptr [esi + 0x1c], 0
// 005eb06a  57                   push edi
// 005eb06b  7521                 jne 0x5eb08e
// 005eb06d  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005eb071  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005eb074  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 005eb078  50                   push eax
// 005eb079  51                   push ecx
// 005eb07a  6a01                 push 1
// 005eb07c  57                   push edi
// 005eb07d  8bce                 mov ecx, esi
// 005eb07f  e84cedffff           call 0x5e9dd0
// 005eb084  8bc7                 mov eax, edi
// 005eb086  5f                   pop edi
// 005eb087  5e                   pop esi
// 005eb088  83c414               add esp, 0x14
// 005eb08b  c21000               ret 0x10
// 005eb08e  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005eb092  8b5618               mov edx, dword ptr [esi + 0x18]
// 005eb095  8b3a                 mov edi, dword ptr [edx]
// 005eb097  8b06                 mov eax, dword ptr [esi]
// 005eb099  53                   push ebx
// 005eb09a  8b1d0ca99e00         mov ebx, dword ptr [0x9ea90c]
// 005eb0a0  85c9                 test ecx, ecx
// 005eb0a2  7404                 je 0x5eb0a8
// 005eb0a4  3bc8                 cmp ecx, eax
// 005eb0a6  7406                 je 0x5eb0ae
// 005eb0a8  ffd3                 call ebx
// 005eb0aa  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005eb0ae  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005eb0b2  3bc7                 cmp eax, edi
// 005eb0b4  752a                 jne 0x5eb0e0
// 005eb0b6  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 005eb0ba  8b0f                 mov ecx, dword ptr [edi]
// 005eb0bc  3b480c               cmp ecx, dword ptr [eax + 0xc]
// 005eb0bf  0f834b010000         jae 0x5eb210
// 005eb0c5  57                   push edi
// 005eb0c6  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005eb0ca  50                   push eax
// 005eb0cb  6a01                 push 1
// 005eb0cd  57                   push edi
// 005eb0ce  8bce                 mov ecx, esi
// 005eb0d0  e8fbecffff           call 0x5e9dd0
// 005eb0d5  5b                   pop ebx
// 005eb0d6  8bc7                 mov eax, edi
// 005eb0d8  5f                   pop edi
// 005eb0d9  5e                   pop esi
// 005eb0da  83c414               add esp, 0x14
// 005eb0dd  c21000               ret 0x10
// 005eb0e0  8b7e18               mov edi, dword ptr [esi + 0x18]
// 005eb0e3  8b16                 mov edx, dword ptr [esi]
// 005eb0e5  85c9                 test ecx, ecx
// 005eb0e7  7404                 je 0x5eb0ed
// 005eb0e9  3bca                 cmp ecx, edx
// 005eb0eb  740a                 je 0x5eb0f7
// 005eb0ed  ffd3                 call ebx
// 005eb0ef  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005eb0f3  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005eb0f7  3bc7                 cmp eax, edi
// 005eb0f9  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 005eb0fd  752c                 jne 0x5eb12b
// 005eb0ff  8b5618               mov edx, dword ptr [esi + 0x18]
// 005eb102  8b4208               mov eax, dword ptr [edx + 8]
// 005eb105  8b480c               mov ecx, dword ptr [eax + 0xc]
// 005eb108  3b0f                 cmp ecx, dword ptr [edi]
// 005eb10a  0f8300010000         jae 0x5eb210
// 005eb110  57                   push edi
// 005eb111  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005eb115  50                   push eax
// 005eb116  6a00                 push 0
// 005eb118  57                   push edi
// 005eb119  8bce                 mov ecx, esi
// 005eb11b  e8b0ecffff           call 0x5e9dd0
// 005eb120  5b                   pop ebx
// 005eb121  8bc7                 mov eax, edi
// 005eb123  5f                   pop edi
// 005eb124  5e                   pop esi
// 005eb125  83c414               add esp, 0x14
// 005eb128  c21000               ret 0x10
// 005eb12b  8b17                 mov edx, dword ptr [edi]
// 005eb12d  39500c               cmp dword ptr [eax + 0xc], edx
// 005eb130  7663                 jbe 0x5eb195
// 005eb132  894c240c             mov dword ptr [esp + 0xc], ecx
// 005eb136  8d4c240c             lea ecx, [esp + 0xc]
// 005eb13a  89442410             mov dword ptr [esp + 0x10], eax
// 005eb13e  e87d91e4ff           call 0x4342c0
// 005eb143  8b17                 mov edx, dword ptr [edi]
// 005eb145  8b442410             mov eax, dword ptr [esp + 0x10]
// 005eb149  39500c               cmp dword ptr [eax + 0xc], edx
// 005eb14c  733c                 jae 0x5eb18a
// 005eb14e  8b5008               mov edx, dword ptr [eax + 8]
// 005eb151  807a1900             cmp byte ptr [edx + 0x19], 0
// 005eb155  57                   push edi
// 005eb156  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005eb15a  8bce                 mov ecx, esi
// 005eb15c  7414                 je 0x5eb172
// 005eb15e  50                   push eax
// 005eb15f  6a00                 push 0
// 005eb161  57                   push edi
// 005eb162  e869ecffff           call 0x5e9dd0
// 005eb167  5b                   pop ebx
// 005eb168  8bc7                 mov eax, edi
// 005eb16a  5f                   pop edi
// 005eb16b  5e                   pop esi
// 005eb16c  83c414               add esp, 0x14
// 005eb16f  c21000               ret 0x10
// 005eb172  8b442430             mov eax, dword ptr [esp + 0x30]
// 005eb176  50                   push eax
// 005eb177  6a01                 push 1
// 005eb179  57                   push edi
// 005eb17a  e851ecffff           call 0x5e9dd0
// 005eb17f  5b                   pop ebx
// 005eb180  8bc7                 mov eax, edi
// 005eb182  5f                   pop edi
// 005eb183  5e                   pop esi
// 005eb184  83c414               add esp, 0x14
// 005eb187  c21000               ret 0x10
// 005eb18a  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005eb18e  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 005eb192  39500c               cmp dword ptr [eax + 0xc], edx
// 005eb195  7379                 jae 0x5eb210
// 005eb197  8b16                 mov edx, dword ptr [esi]
// 005eb199  894c240c             mov dword ptr [esp + 0xc], ecx
// 005eb19d  8b4e18               mov ecx, dword ptr [esi + 0x18]
// 005eb1a0  894c2418             mov dword ptr [esp + 0x18], ecx
// 005eb1a4  8d4c240c             lea ecx, [esp + 0xc]
// 005eb1a8  89442410             mov dword ptr [esp + 0x10], eax
// 005eb1ac  89542414             mov dword ptr [esp + 0x14], edx
// 005eb1b0  e87bb8efff           call 0x4e6a30
// 005eb1b5  8d442414             lea eax, [esp + 0x14]
// 005eb1b9  50                   push eax
// 005eb1ba  8d4c2410             lea ecx, [esp + 0x10]
// 005eb1be  e8bdbde7ff           call 0x466f80
// 005eb1c3  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005eb1c7  84c0                 test al, al
// 005eb1c9  7507                 jne 0x5eb1d2
// 005eb1cb  8b17                 mov edx, dword ptr [edi]
// 005eb1cd  3b510c               cmp edx, dword ptr [ecx + 0xc]
// 005eb1d0  733e                 jae 0x5eb210
// 005eb1d2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 005eb1d6  8b5008               mov edx, dword ptr [eax + 8]
// 005eb1d9  807a1900             cmp byte ptr [edx + 0x19], 0
// 005eb1dd  57                   push edi
// 005eb1de  8b7c2428             mov edi, dword ptr [esp + 0x28]
// 005eb1e2  7416                 je 0x5eb1fa
// 005eb1e4  50                   push eax
// 005eb1e5  6a00                 push 0
// 005eb1e7  57                   push edi
// 005eb1e8  8bce                 mov ecx, esi
// 005eb1ea  e8e1ebffff           call 0x5e9dd0
// 005eb1ef  5b                   pop ebx
// 005eb1f0  8bc7                 mov eax, edi
// 005eb1f2  5f                   pop edi
// 005eb1f3  5e                   pop esi
// 005eb1f4  83c414               add esp, 0x14
// 005eb1f7  c21000               ret 0x10
// 005eb1fa  51                   push ecx
// 005eb1fb  6a01                 push 1
// 005eb1fd  57                   push edi
// 005eb1fe  8bce                 mov ecx, esi
// 005eb200  e8cbebffff           call 0x5e9dd0
// 005eb205  5b                   pop ebx
// 005eb206  8bc7                 mov eax, edi
// 005eb208  5f                   pop edi
// 005eb209  5e                   pop esi
// 005eb20a  83c414               add esp, 0x14
// 005eb20d  c21000               ret 0x10
// 005eb210  57                   push edi
// 005eb211  8d442418             lea eax, [esp + 0x18]
// 005eb215  50                   push eax
// 005eb216  8bce                 mov ecx, esi
// 005eb218  e853f2ffff           call 0x5ea470
// 005eb21d  8b10                 mov edx, dword ptr [eax]
// 005eb21f  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 005eb223  5b                   pop ebx
// 005eb224  8911                 mov dword ptr [ecx], edx
// 005eb226  8b4004               mov eax, dword ptr [eax + 4]
// 005eb229  5f                   pop edi
// 005eb22a  894104               mov dword ptr [ecx + 4], eax
// 005eb22d  8bc1                 mov eax, ecx
// 005eb22f  5e                   pop esi
// 005eb230  83c414               add esp, 0x14
// 005eb233  c21000               ret 0x10
// standard library map_ptr<pod8> (function ?insert@?$_Tree@V?$_Tmap_traits@PAUK@@UE@@U?$less@PAUK@@@std@@V?$allocator@U?$pair@QAUK@@UE@@@std@@@4@$0A@@std@@@std@@QAE?AViterator@12@Vconst_iterator@12@ABU?$pair@QAUK@@UE@@@2@@Z)

// stl: map_ptr<pod8>
struct E { int v[2]; };
#include <map>
struct K; template class std::map<K*, E>;
