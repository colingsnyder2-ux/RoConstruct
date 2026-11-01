// from server: 100% by auto
// roc 2009-12 007d0f40  unit: seg_007d0000  size: 96 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d0f40
//
// 007d0f40  53                   push ebx
// 007d0f41  56                   push esi
// 007d0f42  57                   push edi
// 007d0f43  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 007d0f47  6a4c                 push 0x4c
// 007d0f49  33db                 xor ebx, ebx
// 007d0f4b  53                   push ebx
// 007d0f4c  53                   push ebx
// 007d0f4d  57                   push edi
// 007d0f4e  e85d080000           call 0x7d17b0
// 007d0f53  8bf0                 mov esi, eax
// 007d0f55  6a09                 push 9
// 007d0f57  56                   push esi
// 007d0f58  57                   push edi
// 007d0f59  e802ceffff           call 0x7cdd60
// 007d0f5e  83c41c               add esp, 0x1c
// 007d0f61  5f                   pop edi
// 007d0f62  895e08               mov dword ptr [esi + 8], ebx
// 007d0f65  895e28               mov dword ptr [esi + 0x28], ebx
// 007d0f68  895e10               mov dword ptr [esi + 0x10], ebx
// 007d0f6b  895e34               mov dword ptr [esi + 0x34], ebx
// 007d0f6e  895e0c               mov dword ptr [esi + 0xc], ebx
// 007d0f71  895e2c               mov dword ptr [esi + 0x2c], ebx
// 007d0f74  895e30               mov dword ptr [esi + 0x30], ebx
// 007d0f77  895e24               mov dword ptr [esi + 0x24], ebx
// 007d0f7a  885e48               mov byte ptr [esi + 0x48], bl
// 007d0f7d  895e1c               mov dword ptr [esi + 0x1c], ebx
// 007d0f80  885e49               mov byte ptr [esi + 0x49], bl
// 007d0f83  885e4a               mov byte ptr [esi + 0x4a], bl
// 007d0f86  885e4b               mov byte ptr [esi + 0x4b], bl
// 007d0f89  895e14               mov dword ptr [esi + 0x14], ebx
// 007d0f8c  895e38               mov dword ptr [esi + 0x38], ebx
// 007d0f8f  895e18               mov dword ptr [esi + 0x18], ebx
// 007d0f92  895e3c               mov dword ptr [esi + 0x3c], ebx
// 007d0f95  895e40               mov dword ptr [esi + 0x40], ebx
// 007d0f98  895e20               mov dword ptr [esi + 0x20], ebx
// 007d0f9b  8bc6                 mov eax, esi
// 007d0f9d  5e                   pop esi
// 007d0f9e  5b                   pop ebx
// 007d0f9f  c3                   ret 
// library lua-5.1/lfunc.c (function _luaF_newproto)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lfunc.c
