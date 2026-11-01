// from server: 100% by auto
// roc 2010-06 00402dd0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00402dd0
//
// 00402dd0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00402dd4  85c9                 test ecx, ecx
// 00402dd6  744b                 je 0x402e23
// 00402dd8  56                   push esi
// 00402dd9  57                   push edi
// 00402dda  8d79ff               lea edi, [ecx - 1]
// 00402ddd  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00402de1  33c0                 xor eax, eax
// 00402de3  85ff                 test edi, edi
// 00402de5  7635                 jbe 0x402e1c
// 00402de7  8b742414             mov esi, dword ptr [esp + 0x14]
// 00402deb  eb03                 jmp 0x402df0
// 00402ded  8d4900               lea ecx, [ecx]
// 00402df0  0fb716               movzx edx, word ptr [esi]
// 00402df3  6685d2               test dx, dx
// 00402df6  7424                 je 0x402e1c
// 00402df8  668911               mov word ptr [ecx], dx
// 00402dfb  83c102               add ecx, 2
// 00402dfe  66833e27             cmp word ptr [esi], 0x27
// 00402e02  7510                 jne 0x402e14
// 00402e04  40                   inc eax
// 00402e05  3bc7                 cmp eax, edi
// 00402e07  730b                 jae 0x402e14
// 00402e09  ba27000000           mov edx, 0x27
// 00402e0e  668911               mov word ptr [ecx], dx
// 00402e11  83c102               add ecx, 2
// 00402e14  40                   inc eax
// 00402e15  83c602               add esi, 2
// 00402e18  3bc7                 cmp eax, edi
// 00402e1a  72d4                 jb 0x402df0
// 00402e1c  33c0                 xor eax, eax
// 00402e1e  5f                   pop edi
// 00402e1f  668901               mov word ptr [ecx], ax
// 00402e22  5e                   pop esi
// 00402e23  c3                   ret 
// library atl-9.0/atl.cpp (function ?EscapeSingleQuote@CAtlModule@ATL@@SAXPA_WIPB_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
