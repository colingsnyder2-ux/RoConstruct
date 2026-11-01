// from server: 100% by auto
// roc 2009-12 00402d80  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00402d80
//
// 00402d80  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00402d84  85c9                 test ecx, ecx
// 00402d86  744b                 je 0x402dd3
// 00402d88  56                   push esi
// 00402d89  57                   push edi
// 00402d8a  8d79ff               lea edi, [ecx - 1]
// 00402d8d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00402d91  33c0                 xor eax, eax
// 00402d93  85ff                 test edi, edi
// 00402d95  7635                 jbe 0x402dcc
// 00402d97  8b742414             mov esi, dword ptr [esp + 0x14]
// 00402d9b  eb03                 jmp 0x402da0
// 00402d9d  8d4900               lea ecx, [ecx]
// 00402da0  0fb716               movzx edx, word ptr [esi]
// 00402da3  6685d2               test dx, dx
// 00402da6  7424                 je 0x402dcc
// 00402da8  668911               mov word ptr [ecx], dx
// 00402dab  83c102               add ecx, 2
// 00402dae  66833e27             cmp word ptr [esi], 0x27
// 00402db2  7510                 jne 0x402dc4
// 00402db4  40                   inc eax
// 00402db5  3bc7                 cmp eax, edi
// 00402db7  730b                 jae 0x402dc4
// 00402db9  ba27000000           mov edx, 0x27
// 00402dbe  668911               mov word ptr [ecx], dx
// 00402dc1  83c102               add ecx, 2
// 00402dc4  40                   inc eax
// 00402dc5  83c602               add esi, 2
// 00402dc8  3bc7                 cmp eax, edi
// 00402dca  72d4                 jb 0x402da0
// 00402dcc  33c0                 xor eax, eax
// 00402dce  5f                   pop edi
// 00402dcf  668901               mov word ptr [ecx], ax
// 00402dd2  5e                   pop esi
// 00402dd3  c3                   ret 
// library atl-9.0/atl.cpp (function ?EscapeSingleQuote@CAtlModule@ATL@@SAXPA_WIPB_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
