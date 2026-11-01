// from server: 100% by auto
// roc 2009-06 004030b0  unit: RBX::VRunService::?$FactoryProduct::Creator  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004030b0
//
// 004030b0  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004030b4  85c9                 test ecx, ecx
// 004030b6  744b                 je 0x403103
// 004030b8  56                   push esi
// 004030b9  57                   push edi
// 004030ba  8d79ff               lea edi, [ecx - 1]
// 004030bd  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 004030c1  33c0                 xor eax, eax
// 004030c3  85ff                 test edi, edi
// 004030c5  7635                 jbe 0x4030fc
// 004030c7  8b742414             mov esi, dword ptr [esp + 0x14]
// 004030cb  eb03                 jmp 0x4030d0
// 004030cd  8d4900               lea ecx, [ecx]
// 004030d0  0fb716               movzx edx, word ptr [esi]
// 004030d3  6685d2               test dx, dx
// 004030d6  7424                 je 0x4030fc
// 004030d8  668911               mov word ptr [ecx], dx
// 004030db  83c102               add ecx, 2
// 004030de  66833e27             cmp word ptr [esi], 0x27
// 004030e2  7510                 jne 0x4030f4
// 004030e4  40                   inc eax
// 004030e5  3bc7                 cmp eax, edi
// 004030e7  730b                 jae 0x4030f4
// 004030e9  ba27000000           mov edx, 0x27
// 004030ee  668911               mov word ptr [ecx], dx
// 004030f1  83c102               add ecx, 2
// 004030f4  40                   inc eax
// 004030f5  83c602               add esi, 2
// 004030f8  3bc7                 cmp eax, edi
// 004030fa  72d4                 jb 0x4030d0
// 004030fc  33c0                 xor eax, eax
// 004030fe  5f                   pop edi
// 004030ff  668901               mov word ptr [ecx], ax
// 00403102  5e                   pop esi
// 00403103  c3                   ret 
// library atl-9.0/atl.cpp (function ?EscapeSingleQuote@CAtlModule@ATL@@SAXPA_WIPB_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
