// from server: 100% by auto
// roc 2011-06 004037c0  unit: RBX::VRenderHooksService::?$FactoryProduct::Creator  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 004037c0
//
// 004037c0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004037c4  85c9                 test ecx, ecx
// 004037c6  744b                 je 0x403813
// 004037c8  56                   push esi
// 004037c9  57                   push edi
// 004037ca  8d79ff               lea edi, [ecx - 1]
// 004037cd  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004037d1  33c0                 xor eax, eax
// 004037d3  85ff                 test edi, edi
// 004037d5  7635                 jbe 0x40380c
// 004037d7  8b742414             mov esi, dword ptr [esp + 0x14]
// 004037db  eb03                 jmp 0x4037e0
// 004037dd  8d4900               lea ecx, [ecx]
// 004037e0  0fb716               movzx edx, word ptr [esi]
// 004037e3  6685d2               test dx, dx
// 004037e6  7424                 je 0x40380c
// 004037e8  668911               mov word ptr [ecx], dx
// 004037eb  83c102               add ecx, 2
// 004037ee  66833e27             cmp word ptr [esi], 0x27
// 004037f2  7510                 jne 0x403804
// 004037f4  40                   inc eax
// 004037f5  3bc7                 cmp eax, edi
// 004037f7  730b                 jae 0x403804
// 004037f9  ba27000000           mov edx, 0x27
// 004037fe  668911               mov word ptr [ecx], dx
// 00403801  83c102               add ecx, 2
// 00403804  40                   inc eax
// 00403805  83c602               add esi, 2
// 00403808  3bc7                 cmp eax, edi
// 0040380a  72d4                 jb 0x4037e0
// 0040380c  33c0                 xor eax, eax
// 0040380e  5f                   pop edi
// 0040380f  668901               mov word ptr [ecx], ax
// 00403812  5e                   pop esi
// 00403813  c3                   ret 
// library atl-9.0/atl.cpp (function ?EscapeSingleQuote@CAtlModule@ATL@@SAXPA_WIPB_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
