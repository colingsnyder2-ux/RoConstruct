// from server: 100% by auto
// roc 2010-06 00843c20  unit: CXTPShortcutManager  size: 288 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00843c20
//
// 00843c20  83ec44               sub esp, 0x44
// 00843c23  56                   push esi
// 00843c24  6a2c                 push 0x2c
// 00843c26  33f6                 xor esi, esi
// 00843c28  8d442420             lea eax, [esp + 0x20]
// 00843c2c  56                   push esi
// 00843c2d  50                   push eax
// 00843c2e  e8b14ff6ff           call 0x7a8be4
// 00843c33  8b542460             mov edx, dword ptr [esp + 0x60]
// 00843c37  8b4c245c             mov ecx, dword ptr [esp + 0x5c]
// 00843c3b  83c40c               add esp, 0xc
// 00843c3e  56                   push esi
// 00843c3f  f7da                 neg edx
// 00843c41  56                   push esi
// 00843c42  8954242c             mov dword ptr [esp + 0x2c], edx
// 00843c46  8d542410             lea edx, [esp + 0x10]
// 00843c4a  52                   push edx
// 00843c4b  b801000000           mov eax, 1
// 00843c50  6689442434           mov word ptr [esp + 0x34], ax
// 00843c55  56                   push esi
// 00843c56  8d44242c             lea eax, [esp + 0x2c]
// 00843c5a  894c2430             mov dword ptr [esp + 0x30], ecx
// 00843c5e  50                   push eax
// 00843c5f  b920000000           mov ecx, 0x20
// 00843c64  56                   push esi
// 00843c65  c744243428000000     mov dword ptr [esp + 0x34], 0x28
// 00843c6d  66894c2442           mov word ptr [esp + 0x42], cx
// 00843c72  89742444             mov dword ptr [esp + 0x44], esi
// 00843c76  ff15b0a09e00         call dword ptr [0x9ea0b0]
// 00843c7c  8bc8                 mov ecx, eax
// 00843c7e  894c2418             mov dword ptr [esp + 0x18], ecx
// 00843c82  3bce                 cmp ecx, esi
// 00843c84  0f84ad000000         je 0x843d37
// 00843c8a  39742408             cmp dword ptr [esp + 8], esi
// 00843c8e  0f84a3000000         je 0x843d37
// 00843c94  8b442450             mov eax, dword ptr [esp + 0x50]
// 00843c98  53                   push ebx
// 00843c99  57                   push edi
// 00843c9a  8b7c2460             mov edi, dword ptr [esp + 0x60]
// 00843c9e  8bd8                 mov ebx, eax
// 00843ca0  0fafdf               imul ebx, edi
// 00843ca3  3974245c             cmp dword ptr [esp + 0x5c], esi
// 00843ca7  8d148500000000       lea edx, [eax*4]
// 00843cae  895c2418             mov dword ptr [esp + 0x18], ebx
// 00843cb2  8954241c             mov dword ptr [esp + 0x1c], edx
// 00843cb6  89742414             mov dword ptr [esp + 0x14], esi
// 00843cba  7e70                 jle 0x843d2c
// 00843cbc  55                   push ebp
// 00843cbd  8b6c2458             mov ebp, dword ptr [esp + 0x58]
// 00843cc1  89742410             mov dword ptr [esp + 0x10], esi
// 00843cc5  8b742410             mov esi, dword ptr [esp + 0x10]
// 00843cc9  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00843ccd  03ce                 add ecx, esi
// 00843ccf  33f6                 xor esi, esi
// 00843cd1  8bd5                 mov edx, ebp
// 00843cd3  85c0                 test eax, eax
// 00843cd5  7e37                 jle 0x843d0e
// 00843cd7  8a02                 mov al, byte ptr [edx]
// 00843cd9  0fb65a01             movzx ebx, byte ptr [edx + 1]
// 00843cdd  42                   inc edx
// 00843cde  42                   inc edx
// 00843cdf  885c2464             mov byte ptr [esp + 0x64], bl
// 00843ce3  8a1a                 mov bl, byte ptr [edx]
// 00843ce5  8819                 mov byte ptr [ecx], bl
// 00843ce7  0fb65c2464           movzx ebx, byte ptr [esp + 0x64]
// 00843cec  41                   inc ecx
// 00843ced  8819                 mov byte ptr [ecx], bl
// 00843cef  41                   inc ecx
// 00843cf0  8801                 mov byte ptr [ecx], al
// 00843cf2  42                   inc edx
// 00843cf3  41                   inc ecx
// 00843cf4  32c0                 xor al, al
// 00843cf6  83ff04               cmp edi, 4
// 00843cf9  7503                 jne 0x843cfe
// 00843cfb  8a02                 mov al, byte ptr [edx]
// 00843cfd  42                   inc edx
// 00843cfe  8801                 mov byte ptr [ecx], al
// 00843d00  8b44245c             mov eax, dword ptr [esp + 0x5c]
// 00843d04  46                   inc esi
// 00843d05  41                   inc ecx
// 00843d06  3bf0                 cmp esi, eax
// 00843d08  7ccd                 jl 0x843cd7
// 00843d0a  8b5c241c             mov ebx, dword ptr [esp + 0x1c]
// 00843d0e  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 00843d12  8b542420             mov edx, dword ptr [esp + 0x20]
// 00843d16  01542410             add dword ptr [esp + 0x10], edx
// 00843d1a  41                   inc ecx
// 00843d1b  03eb                 add ebp, ebx
// 00843d1d  3b4c2460             cmp ecx, dword ptr [esp + 0x60]
// 00843d21  894c2418             mov dword ptr [esp + 0x18], ecx
// 00843d25  7c9e                 jl 0x843cc5
// 00843d27  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00843d2b  5d                   pop ebp
// 00843d2c  5f                   pop edi
// 00843d2d  5b                   pop ebx
// 00843d2e  8bc1                 mov eax, ecx
// 00843d30  5e                   pop esi
// 00843d31  83c444               add esp, 0x44
// 00843d34  c21000               ret 0x10
// 00843d37  33c0                 xor eax, eax
// 00843d39  5e                   pop esi
// 00843d3a  83c444               add esp, 0x44
// 00843d3d  c21000               ret 0x10
// library xtp-13.2.1/Source\GraphicLibrary\XTPGraphicBitmapPng.cpp (function ?ConvertToBitmap@CXTPGraphicBitmapPng@@ABEPAUHBITMAP__@@PAEVCSize@@H@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/GraphicLibrary/XTPGraphicBitmapPng.cpp
