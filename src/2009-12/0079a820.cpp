// from server: 100% by auto
// roc 2009-12 0079a820  unit: lua_exception  size: 100 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079a820
//
// 0079a820  8b4604               mov eax, dword ptr [esi + 4]
// 0079a823  83780806             cmp dword ptr [eax + 8], 6
// 0079a827  7538                 jne 0x79a861
// 0079a829  8b08                 mov ecx, dword ptr [eax]
// 0079a82b  80790600             cmp byte ptr [ecx + 6], 0
// 0079a82f  7530                 jne 0x79a861
// 0079a831  8b4910               mov ecx, dword ptr [ecx + 0x10]
// 0079a834  85c9                 test ecx, ecx
// 0079a836  7429                 je 0x79a861
// 0079a838  3b7314               cmp esi, dword ptr [ebx + 0x14]
// 0079a83b  7506                 jne 0x79a843
// 0079a83d  8b5318               mov edx, dword ptr [ebx + 0x18]
// 0079a840  89560c               mov dword ptr [esi + 0xc], edx
// 0079a843  8b00                 mov eax, dword ptr [eax]
// 0079a845  8b5010               mov edx, dword ptr [eax + 0x10]
// 0079a848  8b460c               mov eax, dword ptr [esi + 0xc]
// 0079a84b  2b420c               sub eax, dword ptr [edx + 0xc]
// 0079a84e  c1f802               sar eax, 2
// 0079a851  48                   dec eax
// 0079a852  50                   push eax
// 0079a853  57                   push edi
// 0079a854  51                   push ecx
// 0079a855  e826680300           call 0x7d1080
// 0079a85a  83c40c               add esp, 0xc
// 0079a85d  85c0                 test eax, eax
// 0079a85f  7522                 jne 0x79a883
// 0079a861  3b7314               cmp esi, dword ptr [ebx + 0x14]
// 0079a864  7505                 jne 0x79a86b
// 0079a866  8b4308               mov eax, dword ptr [ebx + 8]
// 0079a869  eb03                 jmp 0x79a86e
// 0079a86b  8b461c               mov eax, dword ptr [esi + 0x1c]
// 0079a86e  2b06                 sub eax, dword ptr [esi]
// 0079a870  c1f804               sar eax, 4
// 0079a873  3bc7                 cmp eax, edi
// 0079a875  7c0a                 jl 0x79a881
// 0079a877  85ff                 test edi, edi
// 0079a879  7e06                 jle 0x79a881
// 0079a87b  b858ab9e00           mov eax, 0x9eab58
// 0079a880  c3                   ret 
// 0079a881  33c0                 xor eax, eax
// 0079a883  c3                   ret 
// library lua-5.1/ldebug.c (function _findlocal)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
