// from server: 100% by auto
// roc 2009-12 0060e070  unit: seg_00600000  size: 112 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0060e070
//
// 0060e070  83ec08               sub esp, 8
// 0060e073  56                   push esi
// 0060e074  8b742410             mov esi, dword ptr [esp + 0x10]
// 0060e078  c644240449           mov byte ptr [esp + 4], 0x49
// 0060e07d  c644240545           mov byte ptr [esp + 5], 0x45
// 0060e082  c64424064e           mov byte ptr [esp + 6], 0x4e
// 0060e087  c644240744           mov byte ptr [esp + 7], 0x44
// 0060e08c  c644240800           mov byte ptr [esp + 8], 0
// 0060e091  85f6                 test esi, esi
// 0060e093  7442                 je 0x60e0d7
// 0060e095  6a00                 push 0
// 0060e097  8d442408             lea eax, [esp + 8]
// 0060e09b  50                   push eax
// 0060e09c  56                   push esi
// 0060e09d  e86ee8ffff           call 0x60c910
// 0060e0a2  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0060e0a8  8bd0                 mov edx, eax
// 0060e0aa  8bc8                 mov ecx, eax
// 0060e0ac  c1e918               shr ecx, 0x18
// 0060e0af  c1ea10               shr edx, 0x10
// 0060e0b2  884c241c             mov byte ptr [esp + 0x1c], cl
// 0060e0b6  8854241d             mov byte ptr [esp + 0x1d], dl
// 0060e0ba  6a04                 push 4
// 0060e0bc  8d542420             lea edx, [esp + 0x20]
// 0060e0c0  8bc8                 mov ecx, eax
// 0060e0c2  52                   push edx
// 0060e0c3  c1e908               shr ecx, 8
// 0060e0c6  56                   push esi
// 0060e0c7  884c242a             mov byte ptr [esp + 0x2a], cl
// 0060e0cb  8844242b             mov byte ptr [esp + 0x2b], al
// 0060e0cf  e8bc52ffff           call 0x603390
// 0060e0d4  83c418               add esp, 0x18
// 0060e0d7  834e6810             or dword ptr [esi + 0x68], 0x10
// 0060e0db  5e                   pop esi
// 0060e0dc  83c408               add esp, 8
// 0060e0df  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_IEND)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
