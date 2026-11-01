// from server: 100% by auto
// roc 2009-06 006b91f0  unit: RBX::UniversalTool  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006b91f0
//
// 006b91f0  8b442408             mov eax, dword ptr [esp + 8]
// 006b91f4  56                   push esi
// 006b91f5  57                   push edi
// 006b91f6  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 006b91fa  8bcf                 mov ecx, edi
// 006b91fc  e8cff9ffff           call 0x6b8bd0
// 006b9201  8bf0                 mov esi, eax
// 006b9203  8b4608               mov eax, dword ptr [esi + 8]
// 006b9206  83c0fd               add eax, -3
// 006b9209  83f804               cmp eax, 4
// 006b920c  7733                 ja 0x6b9241
// 006b920e  ff248548926b00       jmp dword ptr [eax*4 + 0x6b9248]
// 006b9215  8b06                 mov eax, dword ptr [esi]
// 006b9217  8b400c               mov eax, dword ptr [eax + 0xc]
// 006b921a  5f                   pop edi
// 006b921b  5e                   pop esi
// 006b921c  c3                   ret 
// 006b921d  8b0e                 mov ecx, dword ptr [esi]
// 006b921f  8b4110               mov eax, dword ptr [ecx + 0x10]
// 006b9222  5f                   pop edi
// 006b9223  5e                   pop esi
// 006b9224  c3                   ret 
// 006b9225  8b16                 mov edx, dword ptr [esi]
// 006b9227  52                   push edx
// 006b9228  e8c3320300           call 0x6ec4f0
// 006b922d  83c404               add esp, 4
// 006b9230  5f                   pop edi
// 006b9231  5e                   pop esi
// 006b9232  c3                   ret 
// 006b9233  56                   push esi
// 006b9234  57                   push edi
// 006b9235  e8a60c0300           call 0x6e9ee0
// 006b923a  83c408               add esp, 8
// 006b923d  85c0                 test eax, eax
// 006b923f  75d4                 jne 0x6b9215
// 006b9241  5f                   pop edi
// 006b9242  33c0                 xor eax, eax
// 006b9244  5e                   pop esi
// 006b9245  c3                   ret 
// 006b9246  8bff                 mov edi, edi
// 006b9248  33926b001592         xor edx, dword ptr [edx - 0x6deaff95]
// 006b924e  6b0025               imul eax, dword ptr [eax], 0x25
// 006b9251  92                   xchg edx, eax
// 006b9252  6b0041               imul eax, dword ptr [eax], 0x41
// 006b9255  92                   xchg edx, eax
// 006b9256  6b001d               imul eax, dword ptr [eax], 0x1d
// 006b9259  92                   xchg edx, eax
// library lua-5.1/lapi.c (function _lua_objlen)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
