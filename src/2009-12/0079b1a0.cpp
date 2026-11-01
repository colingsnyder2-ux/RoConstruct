// from server: 100% by auto
// roc 2009-12 0079b1a0  unit: seg_00790000  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0079b1a0
//
// 0079b1a0  8b4104               mov eax, dword ptr [ecx + 4]
// 0079b1a3  56                   push esi
// 0079b1a4  be06000000           mov esi, 6
// 0079b1a9  397008               cmp dword ptr [eax + 8], esi
// 0079b1ac  750e                 jne 0x79b1bc
// 0079b1ae  8b00                 mov eax, dword ptr [eax]
// 0079b1b0  80780600             cmp byte ptr [eax + 6], 0
// 0079b1b4  7506                 jne 0x79b1bc
// 0079b1b6  83791400             cmp dword ptr [ecx + 0x14], 0
// 0079b1ba  7f7a                 jg 0x79b236
// 0079b1bc  8b41ec               mov eax, dword ptr [ecx - 0x14]
// 0079b1bf  397008               cmp dword ptr [eax + 8], esi
// 0079b1c2  7572                 jne 0x79b236
// 0079b1c4  8b10                 mov edx, dword ptr [eax]
// 0079b1c6  807a0600             cmp byte ptr [edx + 6], 0
// 0079b1ca  756a                 jne 0x79b236
// 0079b1cc  8b51ec               mov edx, dword ptr [ecx - 0x14]
// 0079b1cf  83e918               sub ecx, 0x18
// 0079b1d2  397208               cmp dword ptr [edx + 8], esi
// 0079b1d5  7524                 jne 0x79b1fb
// 0079b1d7  8b02                 mov eax, dword ptr [edx]
// 0079b1d9  80780600             cmp byte ptr [eax + 6], 0
// 0079b1dd  751c                 jne 0x79b1fb
// 0079b1df  3b4f14               cmp ecx, dword ptr [edi + 0x14]
// 0079b1e2  7506                 jne 0x79b1ea
// 0079b1e4  8b4718               mov eax, dword ptr [edi + 0x18]
// 0079b1e7  89410c               mov dword ptr [ecx + 0xc], eax
// 0079b1ea  8b02                 mov eax, dword ptr [edx]
// 0079b1ec  8b7010               mov esi, dword ptr [eax + 0x10]
// 0079b1ef  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0079b1f2  2b460c               sub eax, dword ptr [esi + 0xc]
// 0079b1f5  c1f802               sar eax, 2
// 0079b1f8  48                   dec eax
// 0079b1f9  eb03                 jmp 0x79b1fe
// 0079b1fb  83c8ff               or eax, 0xffffffff
// 0079b1fe  8b12                 mov edx, dword ptr [edx]
// 0079b200  8b5210               mov edx, dword ptr [edx + 0x10]
// 0079b203  8b520c               mov edx, dword ptr [edx + 0xc]
// 0079b206  8b0482               mov eax, dword ptr [edx + eax*4]
// 0079b209  8bd0                 mov edx, eax
// 0079b20b  83e23f               and edx, 0x3f
// 0079b20e  83fa1c               cmp edx, 0x1c
// 0079b211  740a                 je 0x79b21d
// 0079b213  83fa1d               cmp edx, 0x1d
// 0079b216  7405                 je 0x79b21d
// 0079b218  83fa21               cmp edx, 0x21
// 0079b21b  7519                 jne 0x79b236
// 0079b21d  8b542408             mov edx, dword ptr [esp + 8]
// 0079b221  52                   push edx
// 0079b222  c1e806               shr eax, 6
// 0079b225  51                   push ecx
// 0079b226  25ff000000           and eax, 0xff
// 0079b22b  57                   push edi
// 0079b22c  e8effdffff           call 0x79b020
// 0079b231  83c40c               add esp, 0xc
// 0079b234  5e                   pop esi
// 0079b235  c3                   ret 
// 0079b236  33c0                 xor eax, eax
// 0079b238  5e                   pop esi
// 0079b239  c3                   ret 
// library lua-5.1/ldebug.c (function _getfuncname)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 ldebug.c
