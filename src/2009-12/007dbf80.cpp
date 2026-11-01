// from server: 100% by auto
// roc 2009-12 007dbf80  unit: RBX::GroupDragTool  size: 130 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007dbf80
//
// 007dbf80  55                   push ebp
// 007dbf81  8b6c2408             mov ebp, dword ptr [esp + 8]
// 007dbf85  56                   push esi
// 007dbf86  8bf0                 mov esi, eax
// 007dbf88  83feff               cmp esi, -1
// 007dbf8b  7472                 je 0x7dbfff
// 007dbf8d  53                   push ebx
// 007dbf8e  b280                 mov dl, 0x80
// 007dbf90  57                   push edi
// 007dbf91  8b4500               mov eax, dword ptr [ebp]
// 007dbf94  8b400c               mov eax, dword ptr [eax + 0xc]
// 007dbf97  8d3cb500000000       lea edi, [esi*4]
// 007dbf9e  03c7                 add eax, edi
// 007dbfa0  83fe01               cmp esi, 1
// 007dbfa3  7c11                 jl 0x7dbfb6
// 007dbfa5  8b58fc               mov ebx, dword ptr [eax - 4]
// 007dbfa8  8d48fc               lea ecx, [eax - 4]
// 007dbfab  83e33f               and ebx, 0x3f
// 007dbfae  84937cf29e00         test byte ptr [ebx + 0x9ef27c], dl
// 007dbfb4  7502                 jne 0x7dbfb8
// 007dbfb6  8bc8                 mov ecx, eax
// 007dbfb8  8b01                 mov eax, dword ptr [ecx]
// 007dbfba  8bd8                 mov ebx, eax
// 007dbfbc  83e33f               and ebx, 0x3f
// 007dbfbf  80fb1b               cmp bl, 0x1b
// 007dbfc2  751a                 jne 0x7dbfde
// 007dbfc4  8bd8                 mov ebx, eax
// 007dbfc6  81e3ffffb5ff         and ebx, 0xffb5ffff
// 007dbfcc  81cb00003400         or ebx, 0x340000
// 007dbfd2  c1eb11               shr ebx, 0x11
// 007dbfd5  2500c07f00           and eax, 0x7fc000
// 007dbfda  0bd8                 or ebx, eax
// 007dbfdc  8919                 mov dword ptr [ecx], ebx
// 007dbfde  8b4d00               mov ecx, dword ptr [ebp]
// 007dbfe1  8b410c               mov eax, dword ptr [ecx + 0xc]
// 007dbfe4  8b0407               mov eax, dword ptr [edi + eax]
// 007dbfe7  c1e80e               shr eax, 0xe
// 007dbfea  2dffff0100           sub eax, 0x1ffff
// 007dbfef  83f8ff               cmp eax, -1
// 007dbff2  7409                 je 0x7dbffd
// 007dbff4  8d740601             lea esi, [esi + eax + 1]
// 007dbff8  83feff               cmp esi, -1
// 007dbffb  7594                 jne 0x7dbf91
// 007dbffd  5f                   pop edi
// 007dbffe  5b                   pop ebx
// 007dbfff  5e                   pop esi
// 007dc000  5d                   pop ebp
// 007dc001  c3                   ret 
// library lua-5.1/lcode.c (function _removevalues)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lcode.c
