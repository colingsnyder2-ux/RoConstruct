// from server: 100% by auto
// roc 2009-12 0080d040  unit: KKPAVCXTPImageManagerResource::?$CMap  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0080d040
//
// 0080d040  83ec08               sub esp, 8
// 0080d043  56                   push esi
// 0080d044  8bf1                 mov esi, ecx
// 0080d046  8b4608               mov eax, dword ptr [esi + 8]
// 0080d049  85c0                 test eax, eax
// 0080d04b  756d                 jne 0x80d0ba
// 0080d04d  8b4604               mov eax, dword ptr [esi + 4]
// 0080d050  85c0                 test eax, eax
// 0080d052  7505                 jne 0x80d059
// 0080d054  5e                   pop esi
// 0080d055  83c408               add esp, 8
// 0080d058  c3                   ret 
// 0080d059  53                   push ebx
// 0080d05a  57                   push edi
// 0080d05b  8d4c240c             lea ecx, [esp + 0xc]
// 0080d05f  51                   push ecx
// 0080d060  6a00                 push 0
// 0080d062  50                   push eax
// 0080d063  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0080d06b  e8b0f3ffff           call 0x80c420
// 0080d070  8bf8                 mov edi, eax
// 0080d072  83c40c               add esp, 0xc
// 0080d075  85ff                 test edi, edi
// 0080d077  743d                 je 0x80d0b6
// 0080d079  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 0080d07d  85db                 test ebx, ebx
// 0080d07f  7435                 je 0x80d0b6
// 0080d081  8bce                 mov ecx, esi
// 0080d083  e838f1ffff           call 0x80c1c0
// 0080d088  8d54240c             lea edx, [esp + 0xc]
// 0080d08c  52                   push edx
// 0080d08d  8bce                 mov ecx, esi
// 0080d08f  897e04               mov dword ptr [esi + 4], edi
// 0080d092  895e08               mov dword ptr [esi + 8], ebx
// 0080d095  c7460c01000000       mov dword ptr [esi + 0xc], 1
// 0080d09c  e86ff1ffff           call 0x80c210
// 0080d0a1  8b08                 mov ecx, dword ptr [eax]
// 0080d0a3  894e18               mov dword ptr [esi + 0x18], ecx
// 0080d0a6  8b5004               mov edx, dword ptr [eax + 4]
// 0080d0a9  8b4608               mov eax, dword ptr [esi + 8]
// 0080d0ac  5f                   pop edi
// 0080d0ad  5b                   pop ebx
// 0080d0ae  89561c               mov dword ptr [esi + 0x1c], edx
// 0080d0b1  5e                   pop esi
// 0080d0b2  83c408               add esp, 8
// 0080d0b5  c3                   ret 
// 0080d0b6  5f                   pop edi
// 0080d0b7  33c0                 xor eax, eax
// 0080d0b9  5b                   pop ebx
// 0080d0ba  5e                   pop esi
// 0080d0bb  83c408               add esp, 8
// 0080d0be  c3                   ret 
// library xtp-15.2.1/Source\Common\XTPImageManager.cpp (function ?PreMultiply@CXTPImageManagerIconHandle@@QAEPAEXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPImageManager.cpp
