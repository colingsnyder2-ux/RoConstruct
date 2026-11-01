// from server: 100% by auto
// roc 2007-03 00515070  unit: seg_00510000  size: 120 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00515070
//
// 00515070  83ec0c               sub esp, 0xc
// 00515073  a1b4f58a00           mov eax, dword ptr [0x8af5b4]
// 00515078  33c4                 xor eax, esp
// 0051507a  89442408             mov dword ptr [esp + 8], eax
// 0051507e  56                   push esi
// 0051507f  8b742414             mov esi, dword ptr [esp + 0x14]
// 00515083  b00a                 mov al, 0xa
// 00515085  88442409             mov byte ptr [esp + 9], al
// 00515089  8844240b             mov byte ptr [esp + 0xb], al
// 0051508d  0fb6862c010000       movzx eax, byte ptr [esi + 0x12c]
// 00515094  b908000000           mov ecx, 8
// 00515099  2bc8                 sub ecx, eax
// 0051509b  51                   push ecx
// 0051509c  8d540408             lea edx, [esp + eax + 8]
// 005150a0  52                   push edx
// 005150a1  56                   push esi
// 005150a2  c644241089           mov byte ptr [esp + 0x10], 0x89
// 005150a7  c644241150           mov byte ptr [esp + 0x11], 0x50
// 005150ac  c64424124e           mov byte ptr [esp + 0x12], 0x4e
// 005150b1  c644241347           mov byte ptr [esp + 0x13], 0x47
// 005150b6  c64424140d           mov byte ptr [esp + 0x14], 0xd
// 005150bb  c64424161a           mov byte ptr [esp + 0x16], 0x1a
// 005150c0  e81b53ffff           call 0x50a3e0
// 005150c5  83c40c               add esp, 0xc
// 005150c8  80be2c01000003       cmp byte ptr [esi + 0x12c], 3
// 005150cf  7307                 jae 0x5150d8
// 005150d1  814e6800100000       or dword ptr [esi + 0x68], 0x1000
// 005150d8  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 005150dc  5e                   pop esi
// 005150dd  33cc                 xor ecx, esp
// 005150df  e8c29d1000           call 0x61eea6
// 005150e4  83c40c               add esp, 0xc
// 005150e7  c3                   ret 
// library libpng-1.2.7/pngwutil.c (function _png_write_sig)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS /MD
// roc-lib: libpng-1.2.7 pngwutil.c
