// from server: 100% by auto
// roc 2009-06 0058ce50  unit: seg_00580000  size: 233 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0058ce50
//
// 0058ce50  83ec14               sub esp, 0x14
// 0058ce53  53                   push ebx
// 0058ce54  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 0058ce58  83fb02               cmp ebx, 2
// 0058ce5b  56                   push esi
// 0058ce5c  8b742420             mov esi, dword ptr [esp + 0x20]
// 0058ce60  c644240870           mov byte ptr [esp + 8], 0x70
// 0058ce65  c644240948           mov byte ptr [esp + 9], 0x48
// 0058ce6a  c644240a59           mov byte ptr [esp + 0xa], 0x59
// 0058ce6f  c644240b73           mov byte ptr [esp + 0xb], 0x73
// 0058ce74  c644240c00           mov byte ptr [esp + 0xc], 0
// 0058ce79  7c0e                 jl 0x58ce89
// 0058ce7b  68f4f28c00           push 0x8cf2f4
// 0058ce80  56                   push esi
// 0058ce81  e88a130000           call 0x58e210
// 0058ce86  83c408               add esp, 8
// 0058ce89  8b442424             mov eax, dword ptr [esp + 0x24]
// 0058ce8d  8bc8                 mov ecx, eax
// 0058ce8f  c1e918               shr ecx, 0x18
// 0058ce92  884c2410             mov byte ptr [esp + 0x10], cl
// 0058ce96  8bd0                 mov edx, eax
// 0058ce98  c1ea10               shr edx, 0x10
// 0058ce9b  88542411             mov byte ptr [esp + 0x11], dl
// 0058ce9f  8bc8                 mov ecx, eax
// 0058cea1  88442413             mov byte ptr [esp + 0x13], al
// 0058cea5  8b442428             mov eax, dword ptr [esp + 0x28]
// 0058cea9  c1e908               shr ecx, 8
// 0058ceac  8bd0                 mov edx, eax
// 0058ceae  c1ea18               shr edx, 0x18
// 0058ceb1  884c2412             mov byte ptr [esp + 0x12], cl
// 0058ceb5  88542414             mov byte ptr [esp + 0x14], dl
// 0058ceb9  8bc8                 mov ecx, eax
// 0058cebb  8bd0                 mov edx, eax
// 0058cebd  c1e910               shr ecx, 0x10
// 0058cec0  c1ea08               shr edx, 8
// 0058cec3  884c2415             mov byte ptr [esp + 0x15], cl
// 0058cec7  88542416             mov byte ptr [esp + 0x16], dl
// 0058cecb  88442417             mov byte ptr [esp + 0x17], al
// 0058cecf  885c2418             mov byte ptr [esp + 0x18], bl
// 0058ced3  85f6                 test esi, esi
// 0058ced5  745c                 je 0x58cf33
// 0058ced7  6a09                 push 9
// 0058ced9  8d44240c             lea eax, [esp + 0xc]
// 0058cedd  50                   push eax
// 0058cede  56                   push esi
// 0058cedf  e8dcd9ffff           call 0x58a8c0
// 0058cee4  6a09                 push 9
// 0058cee6  8d4c2420             lea ecx, [esp + 0x20]
// 0058ceea  51                   push ecx
// 0058ceeb  56                   push esi
// 0058ceec  e8ef46ffff           call 0x5815e0
// 0058cef1  6a09                 push 9
// 0058cef3  8d54242c             lea edx, [esp + 0x2c]
// 0058cef7  52                   push edx
// 0058cef8  56                   push esi
// 0058cef9  e8c249ffff           call 0x5818c0
// 0058cefe  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0058cf04  8bd0                 mov edx, eax
// 0058cf06  8bc8                 mov ecx, eax
// 0058cf08  c1e918               shr ecx, 0x18
// 0058cf0b  c1ea10               shr edx, 0x10
// 0058cf0e  884c2450             mov byte ptr [esp + 0x50], cl
// 0058cf12  88542451             mov byte ptr [esp + 0x51], dl
// 0058cf16  6a04                 push 4
// 0058cf18  8d542454             lea edx, [esp + 0x54]
// 0058cf1c  8bc8                 mov ecx, eax
// 0058cf1e  52                   push edx
// 0058cf1f  c1e908               shr ecx, 8
// 0058cf22  56                   push esi
// 0058cf23  884c245e             mov byte ptr [esp + 0x5e], cl
// 0058cf27  8844245f             mov byte ptr [esp + 0x5f], al
// 0058cf2b  e8b046ffff           call 0x5815e0
// 0058cf30  83c430               add esp, 0x30
// 0058cf33  5e                   pop esi
// 0058cf34  5b                   pop ebx
// 0058cf35  83c414               add esp, 0x14
// 0058cf38  c3                   ret 
// library libpng-1.2.22/pngwutil.c (function _png_write_pHYs)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.22 pngwutil.c
