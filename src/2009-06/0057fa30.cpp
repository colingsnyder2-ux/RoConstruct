// from server: 100% by auto
// roc 2009-06 0057fa30  unit: G3D::_internal::DialogTemplate  size: 286 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0057fa30
//
// 0057fa30  83ec40               sub esp, 0x40
// 0057fa33  53                   push ebx
// 0057fa34  8b5c2448             mov ebx, dword ptr [esp + 0x48]
// 0057fa38  55                   push ebp
// 0057fa39  56                   push esi
// 0057fa3a  8d4374               lea eax, [ebx + 0x74]
// 0057fa3d  57                   push edi
// 0057fa3e  50                   push eax
// 0057fa3f  e82cfb0000           call 0x58f570
// 0057fa44  8b8bac000000         mov ecx, dword ptr [ebx + 0xac]
// 0057fa4a  51                   push ecx
// 0057fa4b  53                   push ebx
// 0057fa4c  e85ff20000           call 0x58ecb0
// 0057fa51  8b93ec000000         mov edx, dword ptr [ebx + 0xec]
// 0057fa57  52                   push edx
// 0057fa58  53                   push ebx
// 0057fa59  e852f20000           call 0x58ecb0
// 0057fa5e  8b83e8000000         mov eax, dword ptr [ebx + 0xe8]
// 0057fa64  50                   push eax
// 0057fa65  53                   push ebx
// 0057fa66  e845f20000           call 0x58ecb0
// 0057fa6b  8b8bf0000000         mov ecx, dword ptr [ebx + 0xf0]
// 0057fa71  51                   push ecx
// 0057fa72  53                   push ebx
// 0057fa73  e838f20000           call 0x58ecb0
// 0057fa78  8b93f4000000         mov edx, dword ptr [ebx + 0xf4]
// 0057fa7e  52                   push edx
// 0057fa7f  53                   push ebx
// 0057fa80  e82bf20000           call 0x58ecb0
// 0057fa85  8b83f8000000         mov eax, dword ptr [ebx + 0xf8]
// 0057fa8b  50                   push eax
// 0057fa8c  53                   push ebx
// 0057fa8d  e81ef20000           call 0x58ecb0
// 0057fa92  8b8bfc000000         mov ecx, dword ptr [ebx + 0xfc]
// 0057fa98  51                   push ecx
// 0057fa99  53                   push ebx
// 0057fa9a  e811f20000           call 0x58ecb0
// 0057fa9f  8b9310020000         mov edx, dword ptr [ebx + 0x210]
// 0057faa5  52                   push edx
// 0057faa6  53                   push ebx
// 0057faa7  e804f20000           call 0x58ecb0
// 0057faac  8b83fc010000         mov eax, dword ptr [ebx + 0x1fc]
// 0057fab2  83c444               add esp, 0x44
// 0057fab5  50                   push eax
// 0057fab6  53                   push ebx
// 0057fab7  e8f4f10000           call 0x58ecb0
// 0057fabc  8b8b00020000         mov ecx, dword ptr [ebx + 0x200]
// 0057fac2  51                   push ecx
// 0057fac3  53                   push ebx
// 0057fac4  e8e7f10000           call 0x58ecb0
// 0057fac9  8b9304020000         mov edx, dword ptr [ebx + 0x204]
// 0057facf  52                   push edx
// 0057fad0  53                   push ebx
// 0057fad1  e8daf10000           call 0x58ecb0
// 0057fad6  8b8308020000         mov eax, dword ptr [ebx + 0x208]
// 0057fadc  50                   push eax
// 0057fadd  53                   push ebx
// 0057fade  e8cdf10000           call 0x58ecb0
// 0057fae3  8b8b0c020000         mov ecx, dword ptr [ebx + 0x20c]
// 0057fae9  51                   push ecx
// 0057faea  53                   push ebx
// 0057faeb  e8c0f10000           call 0x58ecb0
// 0057faf0  8b934c020000         mov edx, dword ptr [ebx + 0x24c]
// 0057faf6  8b6b48               mov ebp, dword ptr [ebx + 0x48]
// 0057faf9  688c020000           push 0x28c
// 0057fafe  b910000000           mov ecx, 0x10
// 0057fb03  8bf3                 mov esi, ebx
// 0057fb05  8d7c243c             lea edi, [esp + 0x3c]
// 0057fb09  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 0057fb0b  8b7340               mov esi, dword ptr [ebx + 0x40]
// 0057fb0e  8b7b44               mov edi, dword ptr [ebx + 0x44]
// 0057fb11  6a00                 push 0
// 0057fb13  53                   push ebx
// 0057fb14  89942488000000       mov dword ptr [esp + 0x88], edx
// 0057fb1b  e854a11900           call 0x719c74
// 0057fb20  8b842488000000       mov eax, dword ptr [esp + 0x88]
// 0057fb27  83c434               add esp, 0x34
// 0057fb2a  897340               mov dword ptr [ebx + 0x40], esi
// 0057fb2d  897b44               mov dword ptr [ebx + 0x44], edi
// 0057fb30  896b48               mov dword ptr [ebx + 0x48], ebp
// 0057fb33  89834c020000         mov dword ptr [ebx + 0x24c], eax
// 0057fb39  b910000000           mov ecx, 0x10
// 0057fb3e  8bfb                 mov edi, ebx
// 0057fb40  8d742410             lea esi, [esp + 0x10]
// 0057fb44  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 0057fb46  5f                   pop edi
// 0057fb47  5e                   pop esi
// 0057fb48  5d                   pop ebp
// 0057fb49  5b                   pop ebx
// 0057fb4a  83c440               add esp, 0x40
// 0057fb4d  c3                   ret 
// library libpng-1.2.32/pngwrite.c (function _png_write_destroy)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.32 pngwrite.c
