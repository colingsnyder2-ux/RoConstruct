// from server: 100% by auto
// roc 2008-06 00401b90  unit: VCWorkspace::?$CComObject  size: 84 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00401b90
//
// 00401b90  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00401b94  85c9                 test ecx, ecx
// 00401b96  744b                 je 0x401be3
// 00401b98  56                   push esi
// 00401b99  57                   push edi
// 00401b9a  8d79ff               lea edi, [ecx - 1]
// 00401b9d  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00401ba1  33c0                 xor eax, eax
// 00401ba3  85ff                 test edi, edi
// 00401ba5  7635                 jbe 0x401bdc
// 00401ba7  8b742414             mov esi, dword ptr [esp + 0x14]
// 00401bab  eb03                 jmp 0x401bb0
// 00401bad  8d4900               lea ecx, [ecx]
// 00401bb0  0fb716               movzx edx, word ptr [esi]
// 00401bb3  6685d2               test dx, dx
// 00401bb6  7424                 je 0x401bdc
// 00401bb8  668911               mov word ptr [ecx], dx
// 00401bbb  83c102               add ecx, 2
// 00401bbe  66833e27             cmp word ptr [esi], 0x27
// 00401bc2  7510                 jne 0x401bd4
// 00401bc4  40                   inc eax
// 00401bc5  3bc7                 cmp eax, edi
// 00401bc7  730b                 jae 0x401bd4
// 00401bc9  ba27000000           mov edx, 0x27
// 00401bce  668911               mov word ptr [ecx], dx
// 00401bd1  83c102               add ecx, 2
// 00401bd4  40                   inc eax
// 00401bd5  83c602               add esi, 2
// 00401bd8  3bc7                 cmp eax, edi
// 00401bda  72d4                 jb 0x401bb0
// 00401bdc  33c0                 xor eax, eax
// 00401bde  5f                   pop edi
// 00401bdf  668901               mov word ptr [ecx], ax
// 00401be2  5e                   pop esi
// 00401be3  c3                   ret 
// library atl-9.0/atl.cpp (function ?EscapeSingleQuote@CAtlModule@ATL@@SAXPA_WIPB_W@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: atl-9.0 atl.cpp
