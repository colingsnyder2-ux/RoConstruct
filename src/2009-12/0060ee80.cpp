// from server: 100% by auto
// roc 2009-12 0060ee80  unit: seg_00600000  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060ee80
//
// 0060ee80  83ec14               sub esp, 0x14
// 0060ee83  53                   push ebx
// 0060ee84  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0060ee88  83fb02               cmp ebx, 2
// 0060ee8b  56                   push esi
// 0060ee8c  8b742420             mov esi, dword ptr [esp + 0x20]
// 0060ee90  c644240870           mov byte ptr [esp + 8], 0x70
// 0060ee95  c644240948           mov byte ptr [esp + 9], 0x48
// 0060ee9a  c644240a59           mov byte ptr [esp + 0xa], 0x59
// 0060ee9f  c644240b73           mov byte ptr [esp + 0xb], 0x73
// 0060eea4  c644240c00           mov byte ptr [esp + 0xc], 0
// 0060eea9  7c0e                 jl 0x60eeb9
// 0060eeab  6884619c00           push 0x9c6184
// 0060eeb0  56                   push esi
// 0060eeb1  e88a130000           call 0x610240
// 0060eeb6  83c408               add esp, 8
// 0060eeb9  8b442424             mov eax, dword ptr [esp + 0x24]
// 0060eebd  8bc8                 mov ecx, eax
// 0060eebf  c1e918               shr ecx, 0x18
// 0060eec2  884c2410             mov byte ptr [esp + 0x10], cl
// 0060eec6  8bd0                 mov edx, eax
// 0060eec8  c1ea10               shr edx, 0x10
// 0060eecb  88542411             mov byte ptr [esp + 0x11], dl
// 0060eecf  8bc8                 mov ecx, eax
// 0060eed1  88442413             mov byte ptr [esp + 0x13], al
// 0060eed5  8b442428             mov eax, dword ptr [esp + 0x28]
// 0060eed9  c1e908               shr ecx, 8
// 0060eedc  8bd0                 mov edx, eax
// 0060eede  c1ea18               shr edx, 0x18
// 0060eee1  884c2412             mov byte ptr [esp + 0x12], cl
// 0060eee5  88542414             mov byte ptr [esp + 0x14], dl
// 0060eee9  8bc8                 mov ecx, eax
// 0060eeeb  8bd0                 mov edx, eax
// 0060eeed  c1e910               shr ecx, 0x10
// 0060eef0  c1ea08               shr edx, 8
// 0060eef3  884c2415             mov byte ptr [esp + 0x15], cl
// 0060eef7  88542416             mov byte ptr [esp + 0x16], dl
// 0060eefb  88442417             mov byte ptr [esp + 0x17], al
// 0060eeff  885c2418             mov byte ptr [esp + 0x18], bl
// 0060ef03  85f6                 test esi, esi
// 0060ef05  745c                 je 0x60ef63
// 0060ef07  6a09                 push 9
// 0060ef09  8d44240c             lea eax, [esp + 0xc]
// 0060ef0d  50                   push eax
// 0060ef0e  56                   push esi
// 0060ef0f  e8fcd9ffff           call 0x60c910
// 0060ef14  6a09                 push 9
// 0060ef16  8d4c2420             lea ecx, [esp + 0x20]
// 0060ef1a  51                   push ecx
// 0060ef1b  56                   push esi
// 0060ef1c  e86f44ffff           call 0x603390
// 0060ef21  6a09                 push 9
// 0060ef23  8d54242c             lea edx, [esp + 0x2c]
// 0060ef27  52                   push edx
// 0060ef28  56                   push esi
// 0060ef29  e84247ffff           call 0x603670
// 0060ef2e  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0060ef34  8bd0                 mov edx, eax
// 0060ef36  8bc8                 mov ecx, eax
// 0060ef38  c1e918               shr ecx, 0x18
// 0060ef3b  c1ea10               shr edx, 0x10
// 0060ef3e  884c2450             mov byte ptr [esp + 0x50], cl
// 0060ef42  88542451             mov byte ptr [esp + 0x51], dl
// 0060ef46  6a04                 push 4
// 0060ef48  8d542454             lea edx, [esp + 0x54]
// 0060ef4c  8bc8                 mov ecx, eax
// 0060ef4e  52                   push edx
// 0060ef4f  c1e908               shr ecx, 8
// 0060ef52  56                   push esi
// 0060ef53  884c245e             mov byte ptr [esp + 0x5e], cl
// 0060ef57  8844245f             mov byte ptr [esp + 0x5f], al
// 0060ef5b  e83044ffff           call 0x603390
// 0060ef60  83c430               add esp, 0x30
// 0060ef63  5e                   pop esi
// 0060ef64  5b                   pop ebx
// 0060ef65  83c414               add esp, 0x14
// 0060ef68  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_pHYs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
