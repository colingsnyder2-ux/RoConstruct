// from server: 100% by auto
// roc 2010-06 00570600  unit: G3D::LineSegment  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00570600
//
// 00570600  83ec14               sub esp, 0x14
// 00570603  53                   push ebx
// 00570604  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00570608  83fb02               cmp ebx, 2
// 0057060b  b046                 mov al, 0x46
// 0057060d  56                   push esi
// 0057060e  8b742420             mov esi, dword ptr [esp + 0x20]
// 00570612  c64424086f           mov byte ptr [esp + 8], 0x6f
// 00570617  88442409             mov byte ptr [esp + 9], al
// 0057061b  8844240a             mov byte ptr [esp + 0xa], al
// 0057061f  c644240b73           mov byte ptr [esp + 0xb], 0x73
// 00570624  c644240c00           mov byte ptr [esp + 0xc], 0
// 00570629  7c0e                 jl 0x570639
// 0057062b  68cc3ea200           push 0xa23ecc
// 00570630  56                   push esi
// 00570631  e82a150000           call 0x571b60
// 00570636  83c408               add esp, 8
// 00570639  8b442424             mov eax, dword ptr [esp + 0x24]
// 0057063d  8bc8                 mov ecx, eax
// 0057063f  c1f918               sar ecx, 0x18
// 00570642  884c2410             mov byte ptr [esp + 0x10], cl
// 00570646  8bd0                 mov edx, eax
// 00570648  c1fa10               sar edx, 0x10
// 0057064b  88542411             mov byte ptr [esp + 0x11], dl
// 0057064f  8bc8                 mov ecx, eax
// 00570651  88442413             mov byte ptr [esp + 0x13], al
// 00570655  8b442428             mov eax, dword ptr [esp + 0x28]
// 00570659  c1f908               sar ecx, 8
// 0057065c  8bd0                 mov edx, eax
// 0057065e  c1fa18               sar edx, 0x18
// 00570661  884c2412             mov byte ptr [esp + 0x12], cl
// 00570665  88542414             mov byte ptr [esp + 0x14], dl
// 00570669  8bc8                 mov ecx, eax
// 0057066b  8bd0                 mov edx, eax
// 0057066d  c1f910               sar ecx, 0x10
// 00570670  c1fa08               sar edx, 8
// 00570673  884c2415             mov byte ptr [esp + 0x15], cl
// 00570677  88542416             mov byte ptr [esp + 0x16], dl
// 0057067b  88442417             mov byte ptr [esp + 0x17], al
// 0057067f  885c2418             mov byte ptr [esp + 0x18], bl
// 00570683  85f6                 test esi, esi
// 00570685  745c                 je 0x5706e3
// 00570687  6a09                 push 9
// 00570689  8d44240c             lea eax, [esp + 0xc]
// 0057068d  50                   push eax
// 0057068e  56                   push esi
// 0057068f  e89cdbffff           call 0x56e230
// 00570694  6a09                 push 9
// 00570696  8d4c2420             lea ecx, [esp + 0x20]
// 0057069a  51                   push ecx
// 0057069b  56                   push esi
// 0057069c  e85f46ffff           call 0x564d00
// 005706a1  6a09                 push 9
// 005706a3  8d54242c             lea edx, [esp + 0x2c]
// 005706a7  52                   push edx
// 005706a8  56                   push esi
// 005706a9  e83249ffff           call 0x564fe0
// 005706ae  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 005706b4  8bd0                 mov edx, eax
// 005706b6  8bc8                 mov ecx, eax
// 005706b8  c1e918               shr ecx, 0x18
// 005706bb  c1ea10               shr edx, 0x10
// 005706be  884c2450             mov byte ptr [esp + 0x50], cl
// 005706c2  88542451             mov byte ptr [esp + 0x51], dl
// 005706c6  6a04                 push 4
// 005706c8  8d542454             lea edx, [esp + 0x54]
// 005706cc  8bc8                 mov ecx, eax
// 005706ce  52                   push edx
// 005706cf  c1e908               shr ecx, 8
// 005706d2  56                   push esi
// 005706d3  884c245e             mov byte ptr [esp + 0x5e], cl
// 005706d7  8844245f             mov byte ptr [esp + 0x5f], al
// 005706db  e82046ffff           call 0x564d00
// 005706e0  83c430               add esp, 0x30
// 005706e3  5e                   pop esi
// 005706e4  5b                   pop ebx
// 005706e5  83c414               add esp, 0x14
// 005706e8  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_oFFs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
