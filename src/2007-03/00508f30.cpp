// from server: 100% by auto
// roc 2007-03 00508f30  unit: seg_00500000  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00508f30
//
// 00508f30  51                   push ecx
// 00508f31  53                   push ebx
// 00508f32  8b5c240c             mov ebx, dword ptr [esp + 0xc]
// 00508f36  53                   push ebx
// 00508f37  e854510000           call 0x50e090
// 00508f3c  83c404               add esp, 4
// 00508f3f  85c0                 test eax, eax
// 00508f41  7e43                 jle 0x508f86
// 00508f43  8b8bcc000000         mov ecx, dword ptr [ebx + 0xcc]
// 00508f49  55                   push ebp
// 00508f4a  8b6c2414             mov ebp, dword ptr [esp + 0x14]
// 00508f4e  56                   push esi
// 00508f4f  57                   push edi
// 00508f50  89442410             mov dword ptr [esp + 0x10], eax
// 00508f54  33f6                 xor esi, esi
// 00508f56  85c9                 test ecx, ecx
// 00508f58  8bfd                 mov edi, ebp
// 00508f5a  7620                 jbe 0x508f7c
// 00508f5c  8d642400             lea esp, [esp]
// 00508f60  8b07                 mov eax, dword ptr [edi]
// 00508f62  50                   push eax
// 00508f63  53                   push ebx
// 00508f64  e887f6ffff           call 0x5085f0
// 00508f69  8b8bcc000000         mov ecx, dword ptr [ebx + 0xcc]
// 00508f6f  83c601               add esi, 1
// 00508f72  83c408               add esp, 8
// 00508f75  83c704               add edi, 4
// 00508f78  3bf1                 cmp esi, ecx
// 00508f7a  72e4                 jb 0x508f60
// 00508f7c  836c241001           sub dword ptr [esp + 0x10], 1
// 00508f81  75d1                 jne 0x508f54
// 00508f83  5f                   pop edi
// 00508f84  5e                   pop esi
// 00508f85  5d                   pop ebp
// 00508f86  5b                   pop ebx
// 00508f87  59                   pop ecx
// 00508f88  c3                   ret 
// library libpng-1.2.7/pngwrite.c (function _png_write_image)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngwrite.c
