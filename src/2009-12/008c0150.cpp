// from server: 100% by auto
// roc 2009-12 008c0150  unit: CXTPShadowsManager::CShadowWnd  size: 226 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c0150
//
// 008c0150  83ec20               sub esp, 0x20
// 008c0153  53                   push ebx
// 008c0154  56                   push esi
// 008c0155  8bf1                 mov esi, ecx
// 008c0157  56                   push esi
// 008c0158  8d4c240c             lea ecx, [esp + 0xc]
// 008c015c  e80fb1f8ff           call 0x84b270
// 008c0161  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 008c0165  8b5804               mov ebx, dword ptr [eax + 4]
// 008c0168  85db                 test ebx, ebx
// 008c016a  0f84ba000000         je 0x8c022a
// 008c0170  55                   push ebp
// 008c0171  57                   push edi
// 008c0172  8bc3                 mov eax, ebx
// 008c0174  8b4008               mov eax, dword ptr [eax + 8]
// 008c0177  8b1b                 mov ebx, dword ptr [ebx]
// 008c0179  33c9                 xor ecx, ecx
// 008c017b  39485c               cmp dword ptr [eax + 0x5c], ecx
// 008c017e  0f94c1               sete cl
// 008c0181  394e5c               cmp dword ptr [esi + 0x5c], ecx
// 008c0184  0f8596000000         jne 0x8c0220
// 008c018a  50                   push eax
// 008c018b  8d4c2424             lea ecx, [esp + 0x24]
// 008c018f  e8dcb0f8ff           call 0x84b270
// 008c0194  837e5c00             cmp dword ptr [esi + 0x5c], 0
// 008c0198  7540                 jne 0x8c01da
// 008c019a  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 008c019e  8b542414             mov edx, dword ptr [esp + 0x14]
// 008c01a2  8d41ff               lea eax, [ecx - 1]
// 008c01a5  3bd0                 cmp edx, eax
// 008c01a7  7577                 jne 0x8c0220
// 008c01a9  8b442418             mov eax, dword ptr [esp + 0x18]
// 008c01ad  3b442428             cmp eax, dword ptr [esp + 0x28]
// 008c01b1  7d6d                 jge 0x8c0220
// 008c01b3  3b442420             cmp eax, dword ptr [esp + 0x20]
// 008c01b7  7e67                 jle 0x8c0220
// 008c01b9  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 008c01bd  2bf9                 sub edi, ecx
// 008c01bf  8d0c7a               lea ecx, [edx + edi*2]
// 008c01c2  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 008c01c6  6a00                 push 0
// 008c01c8  2bd1                 sub edx, ecx
// 008c01ca  52                   push edx
// 008c01cb  8b542418             mov edx, dword ptr [esp + 0x18]
// 008c01cf  2bc2                 sub eax, edx
// 008c01d1  50                   push eax
// 008c01d2  51                   push ecx
// 008c01d3  894c2424             mov dword ptr [esp + 0x24], ecx
// 008c01d7  52                   push edx
// 008c01d8  eb3f                 jmp 0x8c0219
// 008c01da  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 008c01de  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008c01e2  8d41ff               lea eax, [ecx - 1]
// 008c01e5  3bf8                 cmp edi, eax
// 008c01e7  7537                 jne 0x8c0220
// 008c01e9  8b542414             mov edx, dword ptr [esp + 0x14]
// 008c01ed  3b542424             cmp edx, dword ptr [esp + 0x24]
// 008c01f1  7e2d                 jle 0x8c0220
// 008c01f3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008c01f7  3b44242c             cmp eax, dword ptr [esp + 0x2c]
// 008c01fb  7d23                 jge 0x8c0220
// 008c01fd  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 008c0201  6a00                 push 0
// 008c0203  2bc2                 sub eax, edx
// 008c0205  50                   push eax
// 008c0206  8b442420             mov eax, dword ptr [esp + 0x20]
// 008c020a  2be9                 sub ebp, ecx
// 008c020c  8d4c6fff             lea ecx, [edi + ebp*2 - 1]
// 008c0210  2bc1                 sub eax, ecx
// 008c0212  50                   push eax
// 008c0213  52                   push edx
// 008c0214  894c2420             mov dword ptr [esp + 0x20], ecx
// 008c0218  51                   push ecx
// 008c0219  8bce                 mov ecx, esi
// 008c021b  e8123af3ff           call 0x7f3c32
// 008c0220  85db                 test ebx, ebx
// 008c0222  0f854affffff         jne 0x8c0172
// 008c0228  5f                   pop edi
// 008c0229  5d                   pop ebp
// 008c022a  5e                   pop esi
// 008c022b  5b                   pop ebx
// 008c022c  83c420               add esp, 0x20
// 008c022f  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPHookManager.cpp (function ?LongShadow@CShadowWnd@CXTPShadowManager@@QAEXPAVCShadowList@2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPHookManager.cpp
