// from server: 100% by auto
// roc 2007-03 00401c20  unit: seg_00400000  size: 85 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00401c20
//
// 00401c20  8b442408             mov eax, dword ptr [esp + 8]
// 00401c24  85c0                 test eax, eax
// 00401c26  744c                 je 0x401c74
// 00401c28  56                   push esi
// 00401c29  57                   push edi
// 00401c2a  8d78ff               lea edi, [eax - 1]
// 00401c2d  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00401c31  33c9                 xor ecx, ecx
// 00401c33  85ff                 test edi, edi
// 00401c35  7636                 jbe 0x401c6d
// 00401c37  8b742414             mov esi, dword ptr [esp + 0x14]
// 00401c3b  eb03                 jmp 0x401c40
// 00401c3d  8d4900               lea ecx, [ecx]
// 00401c40  0fb716               movzx edx, word ptr [esi]
// 00401c43  6685d2               test dx, dx
// 00401c46  7425                 je 0x401c6d
// 00401c48  668910               mov word ptr [eax], dx
// 00401c4b  83c002               add eax, 2
// 00401c4e  66833e27             cmp word ptr [esi], 0x27
// 00401c52  750f                 jne 0x401c63
// 00401c54  83c101               add ecx, 1
// 00401c57  3bcf                 cmp ecx, edi
// 00401c59  7308                 jae 0x401c63
// 00401c5b  66c7002700           mov word ptr [eax], 0x27
// 00401c60  83c002               add eax, 2
// 00401c63  83c101               add ecx, 1
// 00401c66  83c602               add esi, 2
// 00401c69  3bcf                 cmp ecx, edi
// 00401c6b  72d3                 jb 0x401c40
// 00401c6d  5f                   pop edi
// 00401c6e  66c7000000           mov word ptr [eax], 0
// 00401c73  5e                   pop esi
// 00401c74  c3                   ret 
// library atl-8.0/atl.cpp (function ?EscapeSingleQuote@CAtlModule@ATL@@SAXPA_WIPB_W@Z)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-8.0 atl.cpp
