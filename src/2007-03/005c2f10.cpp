// from server: 100% by auto
// roc 2007-03 005c2f10  unit: seg_005c0000  size: 156 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005c2f10
//
// 005c2f10  8b4104               mov eax, dword ptr [ecx + 4]
// 005c2f13  56                   push esi
// 005c2f14  be06000000           mov esi, 6
// 005c2f19  397008               cmp dword ptr [eax + 8], esi
// 005c2f1c  750e                 jne 0x5c2f2c
// 005c2f1e  8b00                 mov eax, dword ptr [eax]
// 005c2f20  80780600             cmp byte ptr [eax + 6], 0
// 005c2f24  7506                 jne 0x5c2f2c
// 005c2f26  83791400             cmp dword ptr [ecx + 0x14], 0
// 005c2f2a  7f7c                 jg 0x5c2fa8
// 005c2f2c  8b41ec               mov eax, dword ptr [ecx - 0x14]
// 005c2f2f  397008               cmp dword ptr [eax + 8], esi
// 005c2f32  7574                 jne 0x5c2fa8
// 005c2f34  8b10                 mov edx, dword ptr [eax]
// 005c2f36  807a0600             cmp byte ptr [edx + 6], 0
// 005c2f3a  756c                 jne 0x5c2fa8
// 005c2f3c  8b51ec               mov edx, dword ptr [ecx - 0x14]
// 005c2f3f  83e918               sub ecx, 0x18
// 005c2f42  397208               cmp dword ptr [edx + 8], esi
// 005c2f45  7526                 jne 0x5c2f6d
// 005c2f47  8b02                 mov eax, dword ptr [edx]
// 005c2f49  80780600             cmp byte ptr [eax + 6], 0
// 005c2f4d  751e                 jne 0x5c2f6d
// 005c2f4f  3b4f14               cmp ecx, dword ptr [edi + 0x14]
// 005c2f52  7506                 jne 0x5c2f5a
// 005c2f54  8b4718               mov eax, dword ptr [edi + 0x18]
// 005c2f57  89410c               mov dword ptr [ecx + 0xc], eax
// 005c2f5a  8b02                 mov eax, dword ptr [edx]
// 005c2f5c  8b7010               mov esi, dword ptr [eax + 0x10]
// 005c2f5f  8b410c               mov eax, dword ptr [ecx + 0xc]
// 005c2f62  2b460c               sub eax, dword ptr [esi + 0xc]
// 005c2f65  c1f802               sar eax, 2
// 005c2f68  83e801               sub eax, 1
// 005c2f6b  eb03                 jmp 0x5c2f70
// 005c2f6d  83c8ff               or eax, 0xffffffff
// 005c2f70  8b12                 mov edx, dword ptr [edx]
// 005c2f72  8b5210               mov edx, dword ptr [edx + 0x10]
// 005c2f75  8b520c               mov edx, dword ptr [edx + 0xc]
// 005c2f78  8b0482               mov eax, dword ptr [edx + eax*4]
// 005c2f7b  8bd0                 mov edx, eax
// 005c2f7d  83e23f               and edx, 0x3f
// 005c2f80  83fa1c               cmp edx, 0x1c
// 005c2f83  740a                 je 0x5c2f8f
// 005c2f85  83fa1d               cmp edx, 0x1d
// 005c2f88  7405                 je 0x5c2f8f
// 005c2f8a  83fa21               cmp edx, 0x21
// 005c2f8d  7519                 jne 0x5c2fa8
// 005c2f8f  8b542408             mov edx, dword ptr [esp + 8]
// 005c2f93  52                   push edx
// 005c2f94  c1e806               shr eax, 6
// 005c2f97  51                   push ecx
// 005c2f98  25ff000000           and eax, 0xff
// 005c2f9d  57                   push edi
// 005c2f9e  e8edfdffff           call 0x5c2d90
// 005c2fa3  83c40c               add esp, 0xc
// 005c2fa6  5e                   pop esi
// 005c2fa7  c3                   ret 
// 005c2fa8  33c0                 xor eax, eax
// 005c2faa  5e                   pop esi
// 005c2fab  c3                   ret 
// library lua-5.1.1/ldebug.c (function _getfuncname)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 ldebug.c
