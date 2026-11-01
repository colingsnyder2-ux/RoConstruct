// from server: 100% by auto
// roc 2009-06 007be290  unit: CXTPCommandBarAnimation::PAUCAnimateInfo::?$CArray  size: 288 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007be290
//
// 007be290  83ec44               sub esp, 0x44
// 007be293  56                   push esi
// 007be294  6a2c                 push 0x2c
// 007be296  33f6                 xor esi, esi
// 007be298  8d442420             lea eax, [esp + 0x20]
// 007be29c  56                   push esi
// 007be29d  50                   push eax
// 007be29e  e8d1b9f5ff           call 0x719c74
// 007be2a3  8b542460             mov edx, dword ptr [esp + 0x60]
// 007be2a7  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 007be2ab  83c40c               add esp, 0xc
// 007be2ae  56                   push esi
// 007be2af  f7da                 neg edx
// 007be2b1  56                   push esi
// 007be2b2  8954242c             mov dword ptr [esp + 0x2c], edx
// 007be2b6  8d542410             lea edx, [esp + 0x10]
// 007be2ba  52                   push edx
// 007be2bb  b801000000           mov eax, 1
// 007be2c0  6689442434           mov word ptr [esp + 0x34], ax
// 007be2c5  56                   push esi
// 007be2c6  8d44242c             lea eax, [esp + 0x2c]
// 007be2ca  894c2430             mov dword ptr [esp + 0x30], ecx
// 007be2ce  50                   push eax
// 007be2cf  b920000000           mov ecx, 0x20
// 007be2d4  56                   push esi
// 007be2d5  c744243428000000     mov dword ptr [esp + 0x34], 0x28
// 007be2dd  66894c2442           mov word ptr [esp + 0x42], cx
// 007be2e2  89742444             mov dword ptr [esp + 0x44], esi
// 007be2e6  ff155ce18900         call dword ptr [0x89e15c]
// 007be2ec  8bc8                 mov ecx, eax
// 007be2ee  894c2418             mov dword ptr [esp + 0x18], ecx
// 007be2f2  3bce                 cmp ecx, esi
// 007be2f4  0f84ad000000         je 0x7be3a7
// 007be2fa  39742408             cmp dword ptr [esp + 8], esi
// 007be2fe  0f84a3000000         je 0x7be3a7
// 007be304  8b442450             mov eax, dword ptr [esp + 0x50]
// 007be308  53                   push ebx
// 007be309  57                   push edi
// 007be30a  8b7c2460             mov edi, dword ptr [esp + 0x60]
// 007be30e  8bd8                 mov ebx, eax
// 007be310  0fafdf               imul ebx, edi
// 007be313  3974245c             cmp dword ptr [esp + 0x5c], esi
// 007be317  8d148500000000       lea edx, [eax*4]
// 007be31e  895c2418             mov dword ptr [esp + 0x18], ebx
// 007be322  8954241c             mov dword ptr [esp + 0x1c], edx
// 007be326  89742414             mov dword ptr [esp + 0x14], esi
// 007be32a  7e70                 jle 0x7be39c
// 007be32c  55                   push ebp
// 007be32d  8b6c2458             mov ebp, dword ptr [esp + 0x58]
// 007be331  89742410             mov dword ptr [esp + 0x10], esi
// 007be335  8b742410             mov esi, dword ptr [esp + 0x10]
// 007be339  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 007be33d  03ce                 add ecx, esi
// 007be33f  33f6                 xor esi, esi
// 007be341  8bd5                 mov edx, ebp
// 007be343  85c0                 test eax, eax
// 007be345  7e37                 jle 0x7be37e
// 007be347  8a02                 mov al, byte ptr [edx]
// 007be349  0fb65a01             movzx ebx, byte ptr [edx + 1]
// 007be34d  42                   inc edx
// 007be34e  42                   inc edx
// 007be34f  885c2464             mov byte ptr [esp + 0x64], bl
// 007be353  8a1a                 mov bl, byte ptr [edx]
// 007be355  8819                 mov byte ptr [ecx], bl
// 007be357  0fb65c2464           movzx ebx, byte ptr [esp + 0x64]
// 007be35c  41                   inc ecx
// 007be35d  8819                 mov byte ptr [ecx], bl
// 007be35f  41                   inc ecx
// 007be360  8801                 mov byte ptr [ecx], al
// 007be362  42                   inc edx
// 007be363  41                   inc ecx
// 007be364  32c0                 xor al, al
// 007be366  83ff04               cmp edi, 4
// 007be369  7503                 jne 0x7be36e
// 007be36b  8a02                 mov al, byte ptr [edx]
// 007be36d  42                   inc edx
// 007be36e  8801                 mov byte ptr [ecx], al
// 007be370  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 007be374  46                   inc esi
// 007be375  41                   inc ecx
// 007be376  3bf0                 cmp esi, eax
// 007be378  7ccd                 jl 0x7be347
// 007be37a  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 007be37e  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007be382  8b542420             mov edx, dword ptr [esp + 0x20]
// 007be386  01542410             add dword ptr [esp + 0x10], edx
// 007be38a  41                   inc ecx
// 007be38b  03eb                 add ebp, ebx
// 007be38d  3b4c2460             cmp ecx, dword ptr [esp + 0x60]
// 007be391  894c2418             mov dword ptr [esp + 0x18], ecx
// 007be395  7c9e                 jl 0x7be335
// 007be397  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 007be39b  5d                   pop ebp
// 007be39c  5f                   pop edi
// 007be39d  5b                   pop ebx
// 007be39e  8bc1                 mov eax, ecx
// 007be3a0  5e                   pop esi
// 007be3a1  83c444               add esp, 0x44
// 007be3a4  c21000               ret 0x10
// 007be3a7  33c0                 xor eax, eax
// 007be3a9  5e                   pop esi
// 007be3aa  83c444               add esp, 0x44
// 007be3ad  c21000               ret 0x10
// library xtp-15.2.1/Source\GraphicLibrary\XTPGraphicBitmapPng.cpp (function ?ConvertToBitmap@CXTPGraphicBitmapPng@@ABEPAUHBITMAP__@@PAEVCSize@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/GraphicLibrary/XTPGraphicBitmapPng.cpp
