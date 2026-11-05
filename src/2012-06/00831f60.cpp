// roc 2012-06 00831f60  unit: RBX::PAVPrimitive::$$A6AXU?$pair::?$signal::Vslot::?$callable  size: 108 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00831f60
//
// 00831f60  8b442408             mov eax, dword ptr [esp + 8]
// 00831f64  56                   push esi
// 00831f65  57                   push edi
// 00831f66  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 00831f6a  8bcf                 mov ecx, edi
// 00831f6c  e8cff9ffff           call 0x831940
// 00831f71  8bf0                 mov esi, eax
// 00831f73  8b4608               mov eax, dword ptr [esi + 8]
// 00831f76  83c0fd               add eax, -3
// 00831f79  83f804               cmp eax, 4
// 00831f7c  7733                 ja 0x831fb1
// 00831f7e  ff2485b81f8300       jmp dword ptr [eax*4 + 0x831fb8]
// 00831f85  8b06                 mov eax, dword ptr [esi]
// 00831f87  8b400c               mov eax, dword ptr [eax + 0xc]
// 00831f8a  5f                   pop edi
// 00831f8b  5e                   pop esi
// 00831f8c  c3                   ret 
// 00831f8d  8b0e                 mov ecx, dword ptr [esi]
// 00831f8f  8b4110               mov eax, dword ptr [ecx + 0x10]
// 00831f92  5f                   pop edi
// 00831f93  5e                   pop esi
// 00831f94  c3                   ret 
// 00831f95  8b16                 mov edx, dword ptr [esi]
// 00831f97  52                   push edx
// 00831f98  e8333d1000           call 0x935cd0
// 00831f9d  83c404               add esp, 4
// 00831fa0  5f                   pop edi
// 00831fa1  5e                   pop esi
// 00831fa2  c3                   ret 
// 00831fa3  56                   push esi
// 00831fa4  57                   push edi
// 00831fa5  e826161000           call 0x9335d0
// 00831faa  83c408               add esp, 8
// 00831fad  85c0                 test eax, eax
// 00831faf  75d4                 jne 0x831f85
// 00831fb1  5f                   pop edi
// 00831fb2  33c0                 xor eax, eax
// 00831fb4  5e                   pop esi
// 00831fb5  c3                   ret 
// 00831fb6  8bff                 mov edi, edi
// 00831fb8  a31f830085           mov dword ptr [0x8500831f], eax
// 00831fbd  1f                   pop ds
// 00831fbe  830095               add dword ptr [eax], -0x6b
// 00831fc1  1f                   pop ds
// 00831fc2  8300b1               add dword ptr [eax], -0x4f
// 00831fc5  1f                   pop ds
// 00831fc6  83008d               add dword ptr [eax], -0x73
// 00831fc9  1f                   pop ds
// library lua-5.1/lapi.c (function _lua_objlen)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
