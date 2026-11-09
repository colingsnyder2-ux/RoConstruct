// from server: 100% by auto
// roc 2009-06 0058c170  unit: seg_00580000  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058c170
//
// 0058c170  83ec08               sub esp, 8
// 0058c173  53                   push ebx
// 0058c174  8b5c2414             mov ebx, dword ptr [esp + 0x14]
// 0058c178  83fb04               cmp ebx, 4
// 0058c17b  56                   push esi
// 0058c17c  8b742414             mov esi, dword ptr [esp + 0x14]
// 0058c180  c644240873           mov byte ptr [esp + 8], 0x73
// 0058c185  c644240952           mov byte ptr [esp + 9], 0x52
// 0058c18a  c644240a47           mov byte ptr [esp + 0xa], 0x47
// 0058c18f  c644240b42           mov byte ptr [esp + 0xb], 0x42
// 0058c194  c644240c00           mov byte ptr [esp + 0xc], 0
// 0058c199  7c0e                 jl 0x58c1a9
// 0058c19b  6888ef8c00           push 0x8cef88
// 0058c1a0  56                   push esi
// 0058c1a1  e86a200000           call 0x58e210
// 0058c1a6  83c408               add esp, 8
// 0058c1a9  885c2418             mov byte ptr [esp + 0x18], bl
// 0058c1ad  85f6                 test esi, esi
// 0058c1af  745c                 je 0x58c20d
// 0058c1b1  6a01                 push 1
// 0058c1b3  8d44240c             lea eax, [esp + 0xc]
// 0058c1b7  50                   push eax
// 0058c1b8  56                   push esi
// 0058c1b9  e802e7ffff           call 0x58a8c0
// 0058c1be  6a01                 push 1
// 0058c1c0  8d4c2428             lea ecx, [esp + 0x28]
// 0058c1c4  51                   push ecx
// 0058c1c5  56                   push esi
// 0058c1c6  e81554ffff           call 0x5815e0
// 0058c1cb  6a01                 push 1
// 0058c1cd  8d542434             lea edx, [esp + 0x34]
// 0058c1d1  52                   push edx
// 0058c1d2  56                   push esi
// 0058c1d3  e8e856ffff           call 0x5818c0
// 0058c1d8  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0058c1de  8bd0                 mov edx, eax
// 0058c1e0  8bc8                 mov ecx, eax
// 0058c1e2  c1e918               shr ecx, 0x18
// 0058c1e5  c1ea10               shr edx, 0x10
// 0058c1e8  884c2438             mov byte ptr [esp + 0x38], cl
// 0058c1ec  88542439             mov byte ptr [esp + 0x39], dl
// 0058c1f0  6a04                 push 4
// 0058c1f2  8d54243c             lea edx, [esp + 0x3c]
// 0058c1f6  8bc8                 mov ecx, eax
// 0058c1f8  52                   push edx
// 0058c1f9  c1e908               shr ecx, 8
// 0058c1fc  56                   push esi
// 0058c1fd  884c2446             mov byte ptr [esp + 0x46], cl
// 0058c201  88442447             mov byte ptr [esp + 0x47], al
// 0058c205  e8d653ffff           call 0x5815e0
// 0058c20a  83c430               add esp, 0x30
// 0058c20d  5e                   pop esi
// 0058c20e  5b                   pop ebx
// 0058c20f  83c408               add esp, 8
// 0058c212  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_sRGB)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
