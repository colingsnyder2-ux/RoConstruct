// from server: 100% by auto
// roc 2010-06 005707a0  unit: G3D::LineSegment  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 005707a0
//
// 005707a0  83ec14               sub esp, 0x14
// 005707a3  53                   push ebx
// 005707a4  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 005707a8  83fb02               cmp ebx, 2
// 005707ab  56                   push esi
// 005707ac  8b742420             mov esi, dword ptr [esp + 0x20]
// 005707b0  c644240870           mov byte ptr [esp + 8], 0x70
// 005707b5  c644240948           mov byte ptr [esp + 9], 0x48
// 005707ba  c644240a59           mov byte ptr [esp + 0xa], 0x59
// 005707bf  c644240b73           mov byte ptr [esp + 0xb], 0x73
// 005707c4  c644240c00           mov byte ptr [esp + 0xc], 0
// 005707c9  7c0e                 jl 0x5707d9
// 005707cb  68fc3ea200           push 0xa23efc
// 005707d0  56                   push esi
// 005707d1  e88a130000           call 0x571b60
// 005707d6  83c408               add esp, 8
// 005707d9  8b442424             mov eax, dword ptr [esp + 0x24]
// 005707dd  8bc8                 mov ecx, eax
// 005707df  c1e918               shr ecx, 0x18
// 005707e2  884c2410             mov byte ptr [esp + 0x10], cl
// 005707e6  8bd0                 mov edx, eax
// 005707e8  c1ea10               shr edx, 0x10
// 005707eb  88542411             mov byte ptr [esp + 0x11], dl
// 005707ef  8bc8                 mov ecx, eax
// 005707f1  88442413             mov byte ptr [esp + 0x13], al
// 005707f5  8b442428             mov eax, dword ptr [esp + 0x28]
// 005707f9  c1e908               shr ecx, 8
// 005707fc  8bd0                 mov edx, eax
// 005707fe  c1ea18               shr edx, 0x18
// 00570801  884c2412             mov byte ptr [esp + 0x12], cl
// 00570805  88542414             mov byte ptr [esp + 0x14], dl
// 00570809  8bc8                 mov ecx, eax
// 0057080b  8bd0                 mov edx, eax
// 0057080d  c1e910               shr ecx, 0x10
// 00570810  c1ea08               shr edx, 8
// 00570813  884c2415             mov byte ptr [esp + 0x15], cl
// 00570817  88542416             mov byte ptr [esp + 0x16], dl
// 0057081b  88442417             mov byte ptr [esp + 0x17], al
// 0057081f  885c2418             mov byte ptr [esp + 0x18], bl
// 00570823  85f6                 test esi, esi
// 00570825  745c                 je 0x570883
// 00570827  6a09                 push 9
// 00570829  8d44240c             lea eax, [esp + 0xc]
// 0057082d  50                   push eax
// 0057082e  56                   push esi
// 0057082f  e8fcd9ffff           call 0x56e230
// 00570834  6a09                 push 9
// 00570836  8d4c2420             lea ecx, [esp + 0x20]
// 0057083a  51                   push ecx
// 0057083b  56                   push esi
// 0057083c  e8bf44ffff           call 0x564d00
// 00570841  6a09                 push 9
// 00570843  8d54242c             lea edx, [esp + 0x2c]
// 00570847  52                   push edx
// 00570848  56                   push esi
// 00570849  e89247ffff           call 0x564fe0
// 0057084e  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 00570854  8bd0                 mov edx, eax
// 00570856  8bc8                 mov ecx, eax
// 00570858  c1e918               shr ecx, 0x18
// 0057085b  c1ea10               shr edx, 0x10
// 0057085e  884c2450             mov byte ptr [esp + 0x50], cl
// 00570862  88542451             mov byte ptr [esp + 0x51], dl
// 00570866  6a04                 push 4
// 00570868  8d542454             lea edx, [esp + 0x54]
// 0057086c  8bc8                 mov ecx, eax
// 0057086e  52                   push edx
// 0057086f  c1e908               shr ecx, 8
// 00570872  56                   push esi
// 00570873  884c245e             mov byte ptr [esp + 0x5e], cl
// 00570877  8844245f             mov byte ptr [esp + 0x5f], al
// 0057087b  e88044ffff           call 0x564d00
// 00570880  83c430               add esp, 0x30
// 00570883  5e                   pop esi
// 00570884  5b                   pop ebx
// 00570885  83c414               add esp, 0x14
// 00570888  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_pHYs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
