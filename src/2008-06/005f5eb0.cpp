// from server: 100% by auto
// from server: 90% by colin
// roc 2008-06 005f5eb0  unit: std::D::V?$allocator::V?$basic_gzip_decompressor::?$stream_buffer  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005f5eb0
//
// 005f5eb0  55                   push ebp
// 005f5eb1  8bec                 mov ebp, esp
// 005f5eb3  6aff                 push -1
// 005f5eb5  6880767d00           push 0x7d7680
// 005f5eba  64a100000000         mov eax, dword ptr fs:[0]
// 005f5ec0  50                   push eax
// 005f5ec1  64892500000000       mov dword ptr fs:[0], esp
// 005f5ec8  83ec08               sub esp, 8
// 005f5ecb  8b4124               mov eax, dword ptr [ecx + 0x24]
// 005f5ece  8b5114               mov edx, dword ptr [ecx + 0x14]
// 005f5ed1  8b00                 mov eax, dword ptr [eax]
// 005f5ed3  8b12                 mov edx, dword ptr [edx]
// 005f5ed5  53                   push ebx
// 005f5ed6  56                   push esi
// 005f5ed7  2bc2                 sub eax, edx
// 005f5ed9  57                   push edi
// 005f5eda  8965f0               mov dword ptr [ebp - 0x10], esp
// 005f5edd  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005f5ee4  85c0                 test eax, eax
// 005f5ee6  7e12                 jle 0x5f5efa
// 005f5ee8  8bb1a0000000         mov esi, dword ptr [ecx + 0xa0]
// 005f5eee  50                   push eax
// 005f5eef  52                   push edx
// 005f5ef0  56                   push esi
// 005f5ef1  83c140               add ecx, 0x40
// 005f5ef4  51                   push ecx
// 005f5ef5  e876fcffff           call 0x5f5b70
// 005f5efa  8b89a0000000         mov ecx, dword ptr [ecx + 0xa0]
// 005f5f00  85c9                 test ecx, ecx
// 005f5f02  7406                 je 0x5f5f0a
// 005f5f04  ff1570238000         call dword ptr [0x802370]

// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: templates-boost-1_34_1-dll roc_boost_resume_e8ec57138b7c1e28.cpp
