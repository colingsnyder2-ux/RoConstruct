// from server: 100% by auto
// roc 2007-03 006e48d0  unit: seg_006e0000  size: 226 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006e48d0
//
// 006e48d0  83ec20               sub esp, 0x20
// 006e48d3  53                   push ebx
// 006e48d4  56                   push esi
// 006e48d5  8bf1                 mov esi, ecx
// 006e48d7  56                   push esi
// 006e48d8  8d4c240c             lea ecx, [esp + 0xc]
// 006e48dc  e8ef6ef8ff           call 0x66b7d0
// 006e48e1  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006e48e5  8b5804               mov ebx, dword ptr [eax + 4]
// 006e48e8  85db                 test ebx, ebx
// 006e48ea  0f84ba000000         je 0x6e49aa
// 006e48f0  55                   push ebp
// 006e48f1  57                   push edi
// 006e48f2  8bc3                 mov eax, ebx
// 006e48f4  8b4008               mov eax, dword ptr [eax + 8]
// 006e48f7  8b1b                 mov ebx, dword ptr [ebx]
// 006e48f9  33c9                 xor ecx, ecx
// 006e48fb  39485c               cmp dword ptr [eax + 0x5c], ecx
// 006e48fe  0f94c1               sete cl
// 006e4901  394e5c               cmp dword ptr [esi + 0x5c], ecx
// 006e4904  0f8596000000         jne 0x6e49a0
// 006e490a  50                   push eax
// 006e490b  8d4c2424             lea ecx, [esp + 0x24]
// 006e490f  e8bc6ef8ff           call 0x66b7d0
// 006e4914  837e5c00             cmp dword ptr [esi + 0x5c], 0
// 006e4918  7540                 jne 0x6e495a
// 006e491a  8b4c242c             mov ecx, dword ptr [esp + 0x2c]
// 006e491e  8b542414             mov edx, dword ptr [esp + 0x14]
// 006e4922  8d41ff               lea eax, [ecx - 1]
// 006e4925  3bd0                 cmp edx, eax
// 006e4927  7577                 jne 0x6e49a0
// 006e4929  8b442418             mov eax, dword ptr [esp + 0x18]
// 006e492d  3b442428             cmp eax, dword ptr [esp + 0x28]
// 006e4931  7d6d                 jge 0x6e49a0
// 006e4933  3b442420             cmp eax, dword ptr [esp + 0x20]
// 006e4937  7e67                 jle 0x6e49a0
// 006e4939  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 006e493d  2bf9                 sub edi, ecx
// 006e493f  8d0c7a               lea ecx, [edx + edi*2]
// 006e4942  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 006e4946  6a00                 push 0
// 006e4948  2bd1                 sub edx, ecx
// 006e494a  52                   push edx
// 006e494b  8b542418             mov edx, dword ptr [esp + 0x18]
// 006e494f  2bc2                 sub eax, edx
// 006e4951  50                   push eax
// 006e4952  51                   push ecx
// 006e4953  894c2424             mov dword ptr [esp + 0x24], ecx
// 006e4957  52                   push edx
// 006e4958  eb3f                 jmp 0x6e4999
// 006e495a  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 006e495e  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006e4962  8d41ff               lea eax, [ecx - 1]
// 006e4965  3bf8                 cmp edi, eax
// 006e4967  7537                 jne 0x6e49a0
// 006e4969  8b542414             mov edx, dword ptr [esp + 0x14]
// 006e496d  3b542424             cmp edx, dword ptr [esp + 0x24]
// 006e4971  7e2d                 jle 0x6e49a0
// 006e4973  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 006e4977  3b44242c             cmp eax, dword ptr [esp + 0x2c]
// 006e497b  7d23                 jge 0x6e49a0
// 006e497d  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 006e4981  6a00                 push 0
// 006e4983  2bc2                 sub eax, edx
// 006e4985  50                   push eax
// 006e4986  8b442420             mov eax, dword ptr [esp + 0x20]
// 006e498a  2be9                 sub ebp, ecx
// 006e498c  8d4c6fff             lea ecx, [edi + ebp*2 - 1]
// 006e4990  2bc1                 sub eax, ecx
// 006e4992  50                   push eax
// 006e4993  52                   push edx
// 006e4994  894c2420             mov dword ptr [esp + 0x20], ecx
// 006e4998  51                   push ecx
// 006e4999  8bce                 mov ecx, esi
// 006e499b  e81c9bf3ff           call 0x61e4bc
// 006e49a0  85db                 test ebx, ebx
// 006e49a2  0f854affffff         jne 0x6e48f2
// 006e49a8  5f                   pop edi
// 006e49a9  5d                   pop ebp
// 006e49aa  5e                   pop esi
// 006e49ab  5b                   pop ebx
// 006e49ac  83c420               add esp, 0x20
// 006e49af  c20400               ret 4
// library xtp-15.2.1/Source\Common\XTPHookManager.cpp (function ?LongShadow@CShadowWnd@CXTPShadowManager@@QAEXPAVCShadowList@2@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Common/XTPHookManager.cpp
