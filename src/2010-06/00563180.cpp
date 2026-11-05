// from server: 100% by auto
// roc 2010-06 00563180  unit: G3D::_internal::DialogTemplate  size: 286 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00563180
//
// 00563180  83ec40               sub esp, 0x40
// 00563183  53                   push ebx
// 00563184  8b5c2448             mov ebx, dword ptr [esp + 0x48]
// 00563188  55                   push ebp
// 00563189  56                   push esi
// 0056318a  8d4374               lea eax, [ebx + 0x74]
// 0056318d  57                   push edi
// 0056318e  50                   push eax
// 0056318f  e82cfd0000           call 0x572ec0
// 00563194  8b8bac000000         mov ecx, dword ptr [ebx + 0xac]
// 0056319a  51                   push ecx
// 0056319b  53                   push ebx
// 0056319c  e85ff40000           call 0x572600
// 005631a1  8b93ec000000         mov edx, dword ptr [ebx + 0xec]
// 005631a7  52                   push edx
// 005631a8  53                   push ebx
// 005631a9  e852f40000           call 0x572600
// 005631ae  8b83e8000000         mov eax, dword ptr [ebx + 0xe8]
// 005631b4  50                   push eax
// 005631b5  53                   push ebx
// 005631b6  e845f40000           call 0x572600
// 005631bb  8b8bf0000000         mov ecx, dword ptr [ebx + 0xf0]
// 005631c1  51                   push ecx
// 005631c2  53                   push ebx
// 005631c3  e838f40000           call 0x572600
// 005631c8  8b93f4000000         mov edx, dword ptr [ebx + 0xf4]
// 005631ce  52                   push edx
// 005631cf  53                   push ebx
// 005631d0  e82bf40000           call 0x572600
// 005631d5  8b83f8000000         mov eax, dword ptr [ebx + 0xf8]
// 005631db  50                   push eax
// 005631dc  53                   push ebx
// 005631dd  e81ef40000           call 0x572600
// 005631e2  8b8bfc000000         mov ecx, dword ptr [ebx + 0xfc]
// 005631e8  51                   push ecx
// 005631e9  53                   push ebx
// 005631ea  e811f40000           call 0x572600
// 005631ef  8b9310020000         mov edx, dword ptr [ebx + 0x210]
// 005631f5  52                   push edx
// 005631f6  53                   push ebx
// 005631f7  e804f40000           call 0x572600
// 005631fc  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 00563202  83c444               add esp, 0x44
// 00563205  50                   push eax
// 00563206  53                   push ebx
// 00563207  e8f4f30000           call 0x572600
// 0056320c  8b8b00020000         mov ecx, dword ptr [ebx + 0x200]
// 00563212  51                   push ecx
// 00563213  53                   push ebx
// 00563214  e8e7f30000           call 0x572600
// 00563219  8b9304020000         mov edx, dword ptr [ebx + 0x204]
// 0056321f  52                   push edx
// 00563220  53                   push ebx
// 00563221  e8daf30000           call 0x572600
// 00563226  8b8308020000         mov eax, dword ptr [ebx + 0x208]
// 0056322c  50                   push eax
// 0056322d  53                   push ebx
// 0056322e  e8cdf30000           call 0x572600
// 00563233  8b8b0c020000         mov ecx, dword ptr [ebx + 0x20c]
// 00563239  51                   push ecx
// 0056323a  53                   push ebx
// 0056323b  e8c0f30000           call 0x572600
// 00563240  8b934c020000         mov edx, dword ptr [ebx + 0x24c]
// 00563246  8b6b48               mov ebp, dword ptr [ebx + 0x48]
// 00563249  688c020000           push 0x28c
// 0056324e  b910000000           mov ecx, 0x10
// 00563253  8bf3                 mov esi, ebx
// 00563255  8d7c243c             lea edi, [esp + 0x3c]
// 00563259  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 0056325b  8b7340               mov esi, dword ptr [ebx + 0x40]
// 0056325e  8b7b44               mov edi, dword ptr [ebx + 0x44]
// 00563261  6a00                 push 0
// 00563263  53                   push ebx
// 00563264  89942488000000       mov dword ptr [esp + 0x88], edx
// 0056326b  e874592400           call 0x7a8be4
// 00563270  8b842488000000       mov eax, dword ptr [esp + 0x88]
// 00563277  83c434               add esp, 0x34
// 0056327a  897340               mov dword ptr [ebx + 0x40], esi
// 0056327d  897b44               mov dword ptr [ebx + 0x44], edi
// 00563280  896b48               mov dword ptr [ebx + 0x48], ebp
// 00563283  89834c020000         mov dword ptr [ebx + 0x24c], eax
// 00563289  b910000000           mov ecx, 0x10
// 0056328e  8bfb                 mov edi, ebx
// 00563290  8d742410             lea esi, [esp + 0x10]
// 00563294  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00563296  5f                   pop edi
// 00563297  5e                   pop esi
// 00563298  5d                   pop ebp
// 00563299  5b                   pop ebx
// 0056329a  83c440               add esp, 0x40
// 0056329d  c3                   ret 
// library libpng-1.2.32/pngwrite.c (function _png_write_destroy)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngwrite.c
