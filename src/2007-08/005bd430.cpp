// from server: 100% by auto
// roc 2007-08 005bd430  unit: RBX::VPVInstance::?$EnumPropDescriptor  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005bd430
//
// 005bd430  85c0                 test eax, eax
// 005bd432  7e15                 jle 0x5bd449
// 005bd434  8b510c               mov edx, dword ptr [ecx + 0xc]
// 005bd437  c1e004               shl eax, 4
// 005bd43a  8d4402f0             lea eax, [edx + eax - 0x10]
// 005bd43e  3b4108               cmp eax, dword ptr [ecx + 8]
// 005bd441  726a                 jb 0x5bd4ad
// 005bd443  b8e82f7c00           mov eax, 0x7c2fe8
// 005bd448  c3                   ret 
// 005bd449  3df0d8ffff           cmp eax, 0xffffd8f0
// 005bd44e  7e07                 jle 0x5bd457
// 005bd450  c1e004               shl eax, 4
// 005bd453  034108               add eax, dword ptr [ecx + 8]
// 005bd456  c3                   ret 
// 005bd457  3deed8ffff           cmp eax, 0xffffd8ee
// 005bd45c  744c                 je 0x5bd4aa
// 005bd45e  3defd8ffff           cmp eax, 0xffffd8ef
// 005bd463  742d                 je 0x5bd492
// 005bd465  3df0d8ffff           cmp eax, 0xffffd8f0
// 005bd46a  741f                 je 0x5bd48b
// 005bd46c  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 005bd46f  8b5104               mov edx, dword ptr [ecx + 4]
// 005bd472  8b12                 mov edx, dword ptr [edx]
// 005bd474  b9eed8ffff           mov ecx, 0xffffd8ee
// 005bd479  2bc8                 sub ecx, eax
// 005bd47b  0fb64207             movzx eax, byte ptr [edx + 7]
// 005bd47f  3bc8                 cmp ecx, eax
// 005bd481  7fc0                 jg 0x5bd443
// 005bd483  c1e104               shl ecx, 4
// 005bd486  8d441108             lea eax, [ecx + edx + 8]
// 005bd48a  c3                   ret 
// 005bd48b  8b4110               mov eax, dword ptr [ecx + 0x10]
// 005bd48e  83c060               add eax, 0x60
// 005bd491  c3                   ret 
// 005bd492  8d4158               lea eax, [ecx + 0x58]
// 005bd495  8b4914               mov ecx, dword ptr [ecx + 0x14]
// 005bd498  8b5104               mov edx, dword ptr [ecx + 4]
// 005bd49b  8b0a                 mov ecx, dword ptr [edx]
// 005bd49d  8b510c               mov edx, dword ptr [ecx + 0xc]
// 005bd4a0  8910                 mov dword ptr [eax], edx
// 005bd4a2  c7400805000000       mov dword ptr [eax + 8], 5
// 005bd4a9  c3                   ret 
// 005bd4aa  8d4148               lea eax, [ecx + 0x48]
// 005bd4ad  c3                   ret 
// library lua-5.1/lapi.c (function _index2adr)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lapi.c
