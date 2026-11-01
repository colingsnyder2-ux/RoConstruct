// from server: 100% by auto
// roc 2009-06 007e56a0  unit: CXTPShadowsManager::CShadowWnd  size: 226 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007e56a0
//
// 007e56a0  83ec20               sub esp, 0x20
// 007e56a3  53                   push ebx
// 007e56a4  56                   push esi
// 007e56a5  8bf1                 mov esi, ecx
// 007e56a7  56                   push esi
// 007e56a8  8d4c240c             lea ecx, [esp + 0xc]
// 007e56ac  e8bfadf8ff           call 0x770470
// 007e56b1  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 007e56b5  8b5804               mov ebx, dword ptr [eax + 4]
// 007e56b8  85db                 test ebx, ebx
// 007e56ba  0f84ba000000         je 0x7e577a
// 007e56c0  55                   push ebp
// 007e56c1  57                   push edi
// 007e56c2  8bc3                 mov eax, ebx
// 007e56c4  8b4008               mov eax, dword ptr [eax + 8]
// 007e56c7  8b1b                 mov ebx, dword ptr [ebx]
// 007e56c9  33c9                 xor ecx, ecx
// 007e56cb  39485c               cmp dword ptr [eax + 0x5c], ecx
// 007e56ce  0f94c1               sete cl
// 007e56d1  394e5c               cmp dword ptr [esi + 0x5c], ecx
// 007e56d4  0f8596000000         jne 0x7e5770
// 007e56da  50                   push eax
// 007e56db  8d4c2424             lea ecx, [esp + 0x24]
// 007e56df  e88cadf8ff           call 0x770470
// 007e56e4  837e5c00             cmp dword ptr [esi + 0x5c], 0
// 007e56e8  7540                 jne 0x7e572a
// 007e56ea  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 007e56ee  8b542414             mov edx, dword ptr [esp + 0x14]
// 007e56f2  8d41ff               lea eax, [ecx - 1]
// 007e56f5  3bd0                 cmp edx, eax
// 007e56f7  7577                 jne 0x7e5770
// 007e56f9  8b442418             mov eax, dword ptr [esp + 0x18]
// 007e56fd  3b442428             cmp eax, dword ptr [esp + 0x28]
// 007e5701  7d6d                 jge 0x7e5770
// 007e5703  3b442420             cmp eax, dword ptr [esp + 0x20]
// 007e5707  7e67                 jle 0x7e5770
// 007e5709  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 007e570d  2bf9                 sub edi, ecx
// 007e570f  8d0c7a               lea ecx, [edx + edi*2]
// 007e5712  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 007e5716  6a00                 push 0
// 007e5718  2bd1                 sub edx, ecx
// 007e571a  52                   push edx
// 007e571b  8b542418             mov edx, dword ptr [esp + 0x18]
// 007e571f  2bc2                 sub eax, edx
// 007e5721  50                   push eax
// 007e5722  51                   push ecx
// 007e5723  894c2424             mov dword ptr [esp + 0x24], ecx
// 007e5727  52                   push edx
// 007e5728  eb3f                 jmp 0x7e5769
// 007e572a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 007e572e  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007e5732  8d41ff               lea eax, [ecx - 1]
// 007e5735  3bf8                 cmp edi, eax
// 007e5737  7537                 jne 0x7e5770
// 007e5739  8b542414             mov edx, dword ptr [esp + 0x14]
// 007e573d  3b542424             cmp edx, dword ptr [esp + 0x24]
// 007e5741  7e2d                 jle 0x7e5770
// 007e5743  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 007e5747  3b44242c             cmp eax, dword ptr [esp + 0x2c]
// 007e574b  7d23                 jge 0x7e5770
// 007e574d  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 007e5751  6a00                 push 0
// 007e5753  2bc2                 sub eax, edx
// 007e5755  50                   push eax
// 007e5756  8b442420             mov eax, dword ptr [esp + 0x20]
// 007e575a  2be9                 sub ebp, ecx
// 007e575c  8d4c6fff             lea ecx, [edi + ebp*2 - 1]
// 007e5760  2bc1                 sub eax, ecx
// 007e5762  50                   push eax
// 007e5763  52                   push edx
// 007e5764  894c2420             mov dword ptr [esp + 0x20], ecx
// 007e5768  51                   push ecx
// 007e5769  8bce                 mov ecx, esi
// 007e576b  e89a36f3ff           call 0x718e0a
// 007e5770  85db                 test ebx, ebx
// 007e5772  0f854affffff         jne 0x7e56c2
// 007e5778  5f                   pop edi
// 007e5779  5d                   pop ebp
// 007e577a  5e                   pop esi
// 007e577b  5b                   pop ebx
// 007e577c  83c420               add esp, 0x20
// 007e577f  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPHookManager.cpp (function ?LongShadow@CShadowWnd@CXTPShadowManager@@QAEXPAVCShadowList@2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPHookManager.cpp
