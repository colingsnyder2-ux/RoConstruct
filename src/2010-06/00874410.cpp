// from server: 100% by auto
// roc 2010-06 00874410  unit: CXTPShadowsManager::CShadowWnd  size: 226 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00874410
//
// 00874410  83ec20               sub esp, 0x20
// 00874413  53                   push ebx
// 00874414  56                   push esi
// 00874415  8bf1                 mov esi, ecx
// 00874417  56                   push esi
// 00874418  8d4c240c             lea ecx, [esp + 0xc]
// 0087441c  e88faef8ff           call 0x7ff2b0
// 00874421  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00874425  8b5804               mov ebx, dword ptr [eax + 4]
// 00874428  85db                 test ebx, ebx
// 0087442a  0f84ba000000         je 0x8744ea
// 00874430  55                   push ebp
// 00874431  57                   push edi
// 00874432  8bc3                 mov eax, ebx
// 00874434  8b4008               mov eax, dword ptr [eax + 8]
// 00874437  8b1b                 mov ebx, dword ptr [ebx]
// 00874439  33c9                 xor ecx, ecx
// 0087443b  39485c               cmp dword ptr [eax + 0x5c], ecx
// 0087443e  0f94c1               sete cl
// 00874441  394e5c               cmp dword ptr [esi + 0x5c], ecx
// 00874444  0f8596000000         jne 0x8744e0
// 0087444a  50                   push eax
// 0087444b  8d4c2424             lea ecx, [esp + 0x24]
// 0087444f  e85caef8ff           call 0x7ff2b0
// 00874454  837e5c00             cmp dword ptr [esi + 0x5c], 0
// 00874458  7540                 jne 0x87449a
// 0087445a  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 0087445e  8b542414             mov edx, dword ptr [esp + 0x14]
// 00874462  8d41ff               lea eax, [ecx - 1]
// 00874465  3bd0                 cmp edx, eax
// 00874467  7577                 jne 0x8744e0
// 00874469  8b442418             mov eax, dword ptr [esp + 0x18]
// 0087446d  3b442428             cmp eax, dword ptr [esp + 0x28]
// 00874471  7d6d                 jge 0x8744e0
// 00874473  3b442420             cmp eax, dword ptr [esp + 0x20]
// 00874477  7e67                 jle 0x8744e0
// 00874479  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0087447d  2bf9                 sub edi, ecx
// 0087447f  8d0c7a               lea ecx, [edx + edi*2]
// 00874482  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 00874486  6a00                 push 0
// 00874488  2bd1                 sub edx, ecx
// 0087448a  52                   push edx
// 0087448b  8b542418             mov edx, dword ptr [esp + 0x18]
// 0087448f  2bc2                 sub eax, edx
// 00874491  50                   push eax
// 00874492  51                   push ecx
// 00874493  894c2424             mov dword ptr [esp + 0x24], ecx
// 00874497  52                   push edx
// 00874498  eb3f                 jmp 0x8744d9
// 0087449a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0087449e  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 008744a2  8d41ff               lea eax, [ecx - 1]
// 008744a5  3bf8                 cmp edi, eax
// 008744a7  7537                 jne 0x8744e0
// 008744a9  8b542414             mov edx, dword ptr [esp + 0x14]
// 008744ad  3b542424             cmp edx, dword ptr [esp + 0x24]
// 008744b1  7e2d                 jle 0x8744e0
// 008744b3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 008744b7  3b44242c             cmp eax, dword ptr [esp + 0x2c]
// 008744bb  7d23                 jge 0x8744e0
// 008744bd  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 008744c1  6a00                 push 0
// 008744c3  2bc2                 sub eax, edx
// 008744c5  50                   push eax
// 008744c6  8b442420             mov eax, dword ptr [esp + 0x20]
// 008744ca  2be9                 sub ebp, ecx
// 008744cc  8d4c6fff             lea ecx, [edi + ebp*2 - 1]
// 008744d0  2bc1                 sub eax, ecx
// 008744d2  50                   push eax
// 008744d3  52                   push edx
// 008744d4  894c2420             mov dword ptr [esp + 0x20], ecx
// 008744d8  51                   push ecx
// 008744d9  8bce                 mov ecx, esi
// 008744db  e89238f3ff           call 0x7a7d72
// 008744e0  85db                 test ebx, ebx
// 008744e2  0f854affffff         jne 0x874432
// 008744e8  5f                   pop edi
// 008744e9  5d                   pop ebp
// 008744ea  5e                   pop esi
// 008744eb  5b                   pop ebx
// 008744ec  83c420               add esp, 0x20
// 008744ef  c20400               ret 4
// library xtp-13.2.1/Source\Common\XTPHookManager.cpp (function ?LongShadow@CShadowWnd@CXTPShadowManager@@QAEXPAVCShadowList@2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Common/XTPHookManager.cpp
