// from server: 100% by auto
// roc 2009-12 0060e1c0  unit: seg_00600000  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060e1c0
//
// 0060e1c0  83ec08               sub esp, 8
// 0060e1c3  53                   push ebx
// 0060e1c4  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0060e1c8  83fb04               cmp ebx, 4
// 0060e1cb  56                   push esi
// 0060e1cc  8b742414             mov esi, dword ptr [esp + 0x14]
// 0060e1d0  c644240873           mov byte ptr [esp + 8], 0x73
// 0060e1d5  c644240952           mov byte ptr [esp + 9], 0x52
// 0060e1da  c644240a47           mov byte ptr [esp + 0xa], 0x47
// 0060e1df  c644240b42           mov byte ptr [esp + 0xb], 0x42
// 0060e1e4  c644240c00           mov byte ptr [esp + 0xc], 0
// 0060e1e9  7c0e                 jl 0x60e1f9
// 0060e1eb  68205e9c00           push 0x9c5e20
// 0060e1f0  56                   push esi
// 0060e1f1  e84a200000           call 0x610240
// 0060e1f6  83c408               add esp, 8
// 0060e1f9  885c2418             mov byte ptr [esp + 0x18], bl
// 0060e1fd  85f6                 test esi, esi
// 0060e1ff  745c                 je 0x60e25d
// 0060e201  6a01                 push 1
// 0060e203  8d44240c             lea eax, [esp + 0xc]
// 0060e207  50                   push eax
// 0060e208  56                   push esi
// 0060e209  e802e7ffff           call 0x60c910
// 0060e20e  6a01                 push 1
// 0060e210  8d4c2428             lea ecx, [esp + 0x28]
// 0060e214  51                   push ecx
// 0060e215  56                   push esi
// 0060e216  e87551ffff           call 0x603390
// 0060e21b  6a01                 push 1
// 0060e21d  8d542434             lea edx, [esp + 0x34]
// 0060e221  52                   push edx
// 0060e222  56                   push esi
// 0060e223  e84854ffff           call 0x603670
// 0060e228  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0060e22e  8bd0                 mov edx, eax
// 0060e230  8bc8                 mov ecx, eax
// 0060e232  c1e918               shr ecx, 0x18
// 0060e235  c1ea10               shr edx, 0x10
// 0060e238  884c2438             mov byte ptr [esp + 0x38], cl
// 0060e23c  88542439             mov byte ptr [esp + 0x39], dl
// 0060e240  6a04                 push 4
// 0060e242  8d54243c             lea edx, [esp + 0x3c]
// 0060e246  8bc8                 mov ecx, eax
// 0060e248  52                   push edx
// 0060e249  c1e908               shr ecx, 8
// 0060e24c  56                   push esi
// 0060e24d  884c2446             mov byte ptr [esp + 0x46], cl
// 0060e251  88442447             mov byte ptr [esp + 0x47], al
// 0060e255  e83651ffff           call 0x603390
// 0060e25a  83c430               add esp, 0x30
// 0060e25d  5e                   pop esi
// 0060e25e  5b                   pop ebx
// 0060e25f  83c408               add esp, 8
// 0060e262  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_sRGB)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
