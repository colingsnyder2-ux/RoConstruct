// from server: 100% by auto
// roc 2009-12 0088fa20  unit: CXTPShortcutManager  size: 288 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088fa20
//
// 0088fa20  83ec44               sub esp, 0x44
// 0088fa23  56                   push esi
// 0088fa24  6a2c                 push 0x2c
// 0088fa26  33f6                 xor esi, esi
// 0088fa28  8d442420             lea eax, [esp + 0x20]
// 0088fa2c  56                   push esi
// 0088fa2d  50                   push eax
// 0088fa2e  e87150f6ff           call 0x7f4aa4
// 0088fa33  8b542460             mov edx, dword ptr [esp + 0x60]
// 0088fa37  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 0088fa3b  83c40c               add esp, 0xc
// 0088fa3e  56                   push esi
// 0088fa3f  f7da                 neg edx
// 0088fa41  56                   push esi
// 0088fa42  8954242c             mov dword ptr [esp + 0x2c], edx
// 0088fa46  8d542410             lea edx, [esp + 0x10]
// 0088fa4a  52                   push edx
// 0088fa4b  b801000000           mov eax, 1
// 0088fa50  6689442434           mov word ptr [esp + 0x34], ax
// 0088fa55  56                   push esi
// 0088fa56  8d44242c             lea eax, [esp + 0x2c]
// 0088fa5a  894c2430             mov dword ptr [esp + 0x30], ecx
// 0088fa5e  50                   push eax
// 0088fa5f  b920000000           mov ecx, 0x20
// 0088fa64  56                   push esi
// 0088fa65  c744243428000000     mov dword ptr [esp + 0x34], 0x28
// 0088fa6d  66894c2442           mov word ptr [esp + 0x42], cx
// 0088fa72  89742444             mov dword ptr [esp + 0x44], esi
// 0088fa76  ff1560b19800         call dword ptr [0x98b160]
// 0088fa7c  8bc8                 mov ecx, eax
// 0088fa7e  894c2418             mov dword ptr [esp + 0x18], ecx
// 0088fa82  3bce                 cmp ecx, esi
// 0088fa84  0f84ad000000         je 0x88fb37
// 0088fa8a  39742408             cmp dword ptr [esp + 8], esi
// 0088fa8e  0f84a3000000         je 0x88fb37
// 0088fa94  8b442450             mov eax, dword ptr [esp + 0x50]
// 0088fa98  53                   push ebx
// 0088fa99  57                   push edi
// 0088fa9a  8b7c2460             mov edi, dword ptr [esp + 0x60]
// 0088fa9e  8bd8                 mov ebx, eax
// 0088faa0  0fafdf               imul ebx, edi
// 0088faa3  3974245c             cmp dword ptr [esp + 0x5c], esi
// 0088faa7  8d148500000000       lea edx, [eax*4]
// 0088faae  895c2418             mov dword ptr [esp + 0x18], ebx
// 0088fab2  8954241c             mov dword ptr [esp + 0x1c], edx
// 0088fab6  89742414             mov dword ptr [esp + 0x14], esi
// 0088faba  7e70                 jle 0x88fb2c
// 0088fabc  55                   push ebp
// 0088fabd  8b6c2458             mov ebp, dword ptr [esp + 0x58]
// 0088fac1  89742410             mov dword ptr [esp + 0x10], esi
// 0088fac5  8b742410             mov esi, dword ptr [esp + 0x10]
// 0088fac9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0088facd  03ce                 add ecx, esi
// 0088facf  33f6                 xor esi, esi
// 0088fad1  8bd5                 mov edx, ebp
// 0088fad3  85c0                 test eax, eax
// 0088fad5  7e37                 jle 0x88fb0e
// 0088fad7  8a02                 mov al, byte ptr [edx]
// 0088fad9  0fb65a01             movzx ebx, byte ptr [edx + 1]
// 0088fadd  42                   inc edx
// 0088fade  42                   inc edx
// 0088fadf  885c2464             mov byte ptr [esp + 0x64], bl
// 0088fae3  8a1a                 mov bl, byte ptr [edx]
// 0088fae5  8819                 mov byte ptr [ecx], bl
// 0088fae7  0fb65c2464           movzx ebx, byte ptr [esp + 0x64]
// 0088faec  41                   inc ecx
// 0088faed  8819                 mov byte ptr [ecx], bl
// 0088faef  41                   inc ecx
// 0088faf0  8801                 mov byte ptr [ecx], al
// 0088faf2  42                   inc edx
// 0088faf3  41                   inc ecx
// 0088faf4  32c0                 xor al, al
// 0088faf6  83ff04               cmp edi, 4
// 0088faf9  7503                 jne 0x88fafe
// 0088fafb  8a02                 mov al, byte ptr [edx]
// 0088fafd  42                   inc edx
// 0088fafe  8801                 mov byte ptr [ecx], al
// 0088fb00  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 0088fb04  46                   inc esi
// 0088fb05  41                   inc ecx
// 0088fb06  3bf0                 cmp esi, eax
// 0088fb08  7ccd                 jl 0x88fad7
// 0088fb0a  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 0088fb0e  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0088fb12  8b542420             mov edx, dword ptr [esp + 0x20]
// 0088fb16  01542410             add dword ptr [esp + 0x10], edx
// 0088fb1a  41                   inc ecx
// 0088fb1b  03eb                 add ebp, ebx
// 0088fb1d  3b4c2460             cmp ecx, dword ptr [esp + 0x60]
// 0088fb21  894c2418             mov dword ptr [esp + 0x18], ecx
// 0088fb25  7c9e                 jl 0x88fac5
// 0088fb27  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0088fb2b  5d                   pop ebp
// 0088fb2c  5f                   pop edi
// 0088fb2d  5b                   pop ebx
// 0088fb2e  8bc1                 mov eax, ecx
// 0088fb30  5e                   pop esi
// 0088fb31  83c444               add esp, 0x44
// 0088fb34  c21000               ret 0x10
// 0088fb37  33c0                 xor eax, eax
// 0088fb39  5e                   pop esi
// 0088fb3a  83c444               add esp, 0x44
// 0088fb3d  c21000               ret 0x10
// library xtp-15.2.1/Source\GraphicLibrary\XTPGraphicBitmapPng.cpp (function ?ConvertToBitmap@CXTPGraphicBitmapPng@@ABEPAUHBITMAP__@@PAEVCSize@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/GraphicLibrary/XTPGraphicBitmapPng.cpp
