// from server: 100% by auto
// roc 2011-06 0056cef0  unit: seg_00560000  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0056cef0
//
// 0056cef0  83ec14               sub esp, 0x14
// 0056cef3  53                   push ebx
// 0056cef4  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0056cef8  83fb02               cmp ebx, 2
// 0056cefb  56                   push esi
// 0056cefc  8b742420             mov esi, dword ptr [esp + 0x20]
// 0056cf00  c644240870           mov byte ptr [esp + 8], 0x70
// 0056cf05  c644240948           mov byte ptr [esp + 9], 0x48
// 0056cf0a  c644240a59           mov byte ptr [esp + 0xa], 0x59
// 0056cf0f  c644240b73           mov byte ptr [esp + 0xb], 0x73
// 0056cf14  c644240c00           mov byte ptr [esp + 0xc], 0
// 0056cf19  7c0e                 jl 0x56cf29
// 0056cf1b  68cc61a800           push 0xa861cc
// 0056cf20  56                   push esi
// 0056cf21  e8ba44ffff           call 0x5613e0
// 0056cf26  83c408               add esp, 8
// 0056cf29  8b442424             mov eax, dword ptr [esp + 0x24]
// 0056cf2d  8bc8                 mov ecx, eax
// 0056cf2f  c1e918               shr ecx, 0x18
// 0056cf32  884c2410             mov byte ptr [esp + 0x10], cl
// 0056cf36  8bd0                 mov edx, eax
// 0056cf38  c1ea10               shr edx, 0x10
// 0056cf3b  88542411             mov byte ptr [esp + 0x11], dl
// 0056cf3f  8bc8                 mov ecx, eax
// 0056cf41  88442413             mov byte ptr [esp + 0x13], al
// 0056cf45  8b442428             mov eax, dword ptr [esp + 0x28]
// 0056cf49  c1e908               shr ecx, 8
// 0056cf4c  8bd0                 mov edx, eax
// 0056cf4e  c1ea18               shr edx, 0x18
// 0056cf51  884c2412             mov byte ptr [esp + 0x12], cl
// 0056cf55  88542414             mov byte ptr [esp + 0x14], dl
// 0056cf59  8bc8                 mov ecx, eax
// 0056cf5b  8bd0                 mov edx, eax
// 0056cf5d  c1e910               shr ecx, 0x10
// 0056cf60  c1ea08               shr edx, 8
// 0056cf63  884c2415             mov byte ptr [esp + 0x15], cl
// 0056cf67  88542416             mov byte ptr [esp + 0x16], dl
// 0056cf6b  88442417             mov byte ptr [esp + 0x17], al
// 0056cf6f  885c2418             mov byte ptr [esp + 0x18], bl
// 0056cf73  85f6                 test esi, esi
// 0056cf75  745c                 je 0x56cfd3
// 0056cf77  6a09                 push 9
// 0056cf79  8d44240c             lea eax, [esp + 0xc]
// 0056cf7d  50                   push eax
// 0056cf7e  56                   push esi
// 0056cf7f  e82cdaffff           call 0x56a9b0
// 0056cf84  6a09                 push 9
// 0056cf86  8d4c2420             lea ecx, [esp + 0x20]
// 0056cf8a  51                   push ecx
// 0056cf8b  56                   push esi
// 0056cf8c  e8afd8feff           call 0x55a840
// 0056cf91  6a09                 push 9
// 0056cf93  8d54242c             lea edx, [esp + 0x2c]
// 0056cf97  52                   push edx
// 0056cf98  56                   push esi
// 0056cf99  e8b238feff           call 0x550850
// 0056cf9e  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0056cfa4  8bd0                 mov edx, eax
// 0056cfa6  8bc8                 mov ecx, eax
// 0056cfa8  c1e918               shr ecx, 0x18
// 0056cfab  c1ea10               shr edx, 0x10
// 0056cfae  884c2450             mov byte ptr [esp + 0x50], cl
// 0056cfb2  88542451             mov byte ptr [esp + 0x51], dl
// 0056cfb6  6a04                 push 4
// 0056cfb8  8d542454             lea edx, [esp + 0x54]
// 0056cfbc  8bc8                 mov ecx, eax
// 0056cfbe  52                   push edx
// 0056cfbf  c1e908               shr ecx, 8
// 0056cfc2  56                   push esi
// 0056cfc3  884c245e             mov byte ptr [esp + 0x5e], cl
// 0056cfc7  8844245f             mov byte ptr [esp + 0x5f], al
// 0056cfcb  e870d8feff           call 0x55a840
// 0056cfd0  83c430               add esp, 0x30
// 0056cfd3  5e                   pop esi
// 0056cfd4  5b                   pop ebx
// 0056cfd5  83c414               add esp, 0x14
// 0056cfd8  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_pHYs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
