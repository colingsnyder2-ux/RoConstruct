// from server: 100% by auto
// roc 2012-06 00658600  unit: seg_00650000  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00658600
//
// 00658600  83ec14               sub esp, 0x14
// 00658603  53                   push ebx
// 00658604  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00658608  83fb02               cmp ebx, 2
// 0065860b  56                   push esi
// 0065860c  8b742420             mov esi, dword ptr [esp + 0x20]
// 00658610  c644240870           mov byte ptr [esp + 8], 0x70
// 00658615  c644240948           mov byte ptr [esp + 9], 0x48
// 0065861a  c644240a59           mov byte ptr [esp + 0xa], 0x59
// 0065861f  c644240b73           mov byte ptr [esp + 0xb], 0x73
// 00658624  c644240c00           mov byte ptr [esp + 0xc], 0
// 00658629  7c0e                 jl 0x658639
// 0065862b  681ca0b800           push 0xb8a01c
// 00658630  56                   push esi
// 00658631  e82a5cffff           call 0x64e260
// 00658636  83c408               add esp, 8
// 00658639  8b442424             mov eax, dword ptr [esp + 0x24]
// 0065863d  8bc8                 mov ecx, eax
// 0065863f  c1e918               shr ecx, 0x18
// 00658642  884c2410             mov byte ptr [esp + 0x10], cl
// 00658646  8bd0                 mov edx, eax
// 00658648  c1ea10               shr edx, 0x10
// 0065864b  88542411             mov byte ptr [esp + 0x11], dl
// 0065864f  8bc8                 mov ecx, eax
// 00658651  88442413             mov byte ptr [esp + 0x13], al
// 00658655  8b442428             mov eax, dword ptr [esp + 0x28]
// 00658659  c1e908               shr ecx, 8
// 0065865c  8bd0                 mov edx, eax
// 0065865e  c1ea18               shr edx, 0x18
// 00658661  884c2412             mov byte ptr [esp + 0x12], cl
// 00658665  88542414             mov byte ptr [esp + 0x14], dl
// 00658669  8bc8                 mov ecx, eax
// 0065866b  8bd0                 mov edx, eax
// 0065866d  c1e910               shr ecx, 0x10
// 00658670  c1ea08               shr edx, 8
// 00658673  884c2415             mov byte ptr [esp + 0x15], cl
// 00658677  88542416             mov byte ptr [esp + 0x16], dl
// 0065867b  88442417             mov byte ptr [esp + 0x17], al
// 0065867f  885c2418             mov byte ptr [esp + 0x18], bl
// 00658683  85f6                 test esi, esi
// 00658685  745c                 je 0x6586e3
// 00658687  6a09                 push 9
// 00658689  8d44240c             lea eax, [esp + 0xc]
// 0065868d  50                   push eax
// 0065868e  56                   push esi
// 0065868f  e82cdaffff           call 0x6560c0
// 00658694  6a09                 push 9
// 00658696  8d4c2420             lea ecx, [esp + 0x20]
// 0065869a  51                   push ecx
// 0065869b  56                   push esi
// 0065869c  e81ff0feff           call 0x6476c0
// 006586a1  6a09                 push 9
// 006586a3  8d54242c             lea edx, [esp + 0x2c]
// 006586a7  52                   push edx
// 006586a8  56                   push esi
// 006586a9  e8e257feff           call 0x63de90
// 006586ae  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 006586b4  8bd0                 mov edx, eax
// 006586b6  8bc8                 mov ecx, eax
// 006586b8  c1e918               shr ecx, 0x18
// 006586bb  c1ea10               shr edx, 0x10
// 006586be  884c2450             mov byte ptr [esp + 0x50], cl
// 006586c2  88542451             mov byte ptr [esp + 0x51], dl
// 006586c6  6a04                 push 4
// 006586c8  8d542454             lea edx, [esp + 0x54]
// 006586cc  8bc8                 mov ecx, eax
// 006586ce  52                   push edx
// 006586cf  c1e908               shr ecx, 8
// 006586d2  56                   push esi
// 006586d3  884c245e             mov byte ptr [esp + 0x5e], cl
// 006586d7  8844245f             mov byte ptr [esp + 0x5f], al
// 006586db  e8e0effeff           call 0x6476c0
// 006586e0  83c430               add esp, 0x30
// 006586e3  5e                   pop esi
// 006586e4  5b                   pop ebx
// 006586e5  83c414               add esp, 0x14
// 006586e8  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_pHYs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
