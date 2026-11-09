// from server: 100% by auto
// roc 2011-06 00550d90  unit: seg_00550000  size: 443 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00550d90
//
// 00550d90  83ec14               sub esp, 0x14
// 00550d93  8b442418             mov eax, dword ptr [esp + 0x18]
// 00550d97  c7042401000000       mov dword ptr [esp], 1
// 00550d9e  85c0                 test eax, eax
// 00550da0  0f8498010000         je 0x550f3e
// 00550da6  837c241c00           cmp dword ptr [esp + 0x1c], 0
// 00550dab  53                   push ebx
// 00550dac  8b5c2434             mov ebx, dword ptr [esp + 0x34]
// 00550db0  55                   push ebp
// 00550db1  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 00550db5  56                   push esi
// 00550db6  8b742444             mov esi, dword ptr [esp + 0x44]
// 00550dba  57                   push edi
// 00550dbb  8b7c2444             mov edi, dword ptr [esp + 0x44]
// 00550dbf  7c25                 jl 0x550de6
// 00550dc1  837c243000           cmp dword ptr [esp + 0x30], 0
// 00550dc6  7e1e                 jle 0x550de6
// 00550dc8  837c243400           cmp dword ptr [esp + 0x34], 0
// 00550dcd  7c17                 jl 0x550de6
// 00550dcf  837c243800           cmp dword ptr [esp + 0x38], 0
// 00550dd4  7c10                 jl 0x550de6
// 00550dd6  85ed                 test ebp, ebp
// 00550dd8  7c0c                 jl 0x550de6
// 00550dda  85db                 test ebx, ebx
// 00550ddc  7c08                 jl 0x550de6
// 00550dde  85ff                 test edi, edi
// 00550de0  7c04                 jl 0x550de6
// 00550de2  85f6                 test esi, esi
// 00550de4  7d1a                 jge 0x550e00
// 00550de6  68cc05a800           push 0xa805cc
// 00550deb  50                   push eax
// 00550dec  e8ef050100           call 0x5613e0
// 00550df1  8b442430             mov eax, dword ptr [esp + 0x30]
// 00550df5  83c408               add esp, 8
// 00550df8  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00550e00  b9ffffff7f           mov ecx, 0x7fffffff
// 00550e05  394c242c             cmp dword ptr [esp + 0x2c], ecx
// 00550e09  7f22                 jg 0x550e2d
// 00550e0b  394c2430             cmp dword ptr [esp + 0x30], ecx
// 00550e0f  7f1c                 jg 0x550e2d
// 00550e11  394c2434             cmp dword ptr [esp + 0x34], ecx
// 00550e15  7f16                 jg 0x550e2d
// 00550e17  394c2438             cmp dword ptr [esp + 0x38], ecx
// 00550e1b  7f10                 jg 0x550e2d
// 00550e1d  3be9                 cmp ebp, ecx
// 00550e1f  7f0c                 jg 0x550e2d
// 00550e21  3bd9                 cmp ebx, ecx
// 00550e23  7f08                 jg 0x550e2d
// 00550e25  3bf9                 cmp edi, ecx
// 00550e27  7f04                 jg 0x550e2d
// 00550e29  3bf1                 cmp esi, ecx
// 00550e2b  7e1a                 jle 0x550e47
// 00550e2d  688c05a800           push 0xa8058c
// 00550e32  50                   push eax
// 00550e33  e8a8050100           call 0x5613e0
// 00550e38  8b442430             mov eax, dword ptr [esp + 0x30]
// 00550e3c  83c408               add esp, 8
// 00550e3f  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00550e47  b9a0860100           mov ecx, 0x186a0
// 00550e4c  2b4c2430             sub ecx, dword ptr [esp + 0x30]
// 00550e50  394c242c             cmp dword ptr [esp + 0x2c], ecx
// 00550e54  7e1a                 jle 0x550e70
// 00550e56  687005a800           push 0xa80570
// 00550e5b  50                   push eax
// 00550e5c  e87f050100           call 0x5613e0
// 00550e61  8b442430             mov eax, dword ptr [esp + 0x30]
// 00550e65  83c408               add esp, 8
// 00550e68  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00550e70  baa0860100           mov edx, 0x186a0
// 00550e75  2b542438             sub edx, dword ptr [esp + 0x38]
// 00550e79  39542434             cmp dword ptr [esp + 0x34], edx
// 00550e7d  7e1a                 jle 0x550e99
// 00550e7f  685805a800           push 0xa80558
// 00550e84  50                   push eax
// 00550e85  e856050100           call 0x5613e0
// 00550e8a  8b442430             mov eax, dword ptr [esp + 0x30]
// 00550e8e  83c408               add esp, 8
// 00550e91  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00550e99  b9a0860100           mov ecx, 0x186a0
// 00550e9e  2bcb                 sub ecx, ebx
// 00550ea0  3be9                 cmp ebp, ecx
// 00550ea2  7e1a                 jle 0x550ebe
// 00550ea4  683c05a800           push 0xa8053c
// 00550ea9  50                   push eax
// 00550eaa  e831050100           call 0x5613e0
// 00550eaf  8b442430             mov eax, dword ptr [esp + 0x30]
// 00550eb3  83c408               add esp, 8
// 00550eb6  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00550ebe  baa0860100           mov edx, 0x186a0
// 00550ec3  2bd6                 sub edx, esi
// 00550ec5  3bfa                 cmp edi, edx
// 00550ec7  7e16                 jle 0x550edf
// 00550ec9  682405a800           push 0xa80524
// 00550ece  50                   push eax
// 00550ecf  e80c050100           call 0x5613e0
// 00550ed4  83c408               add esp, 8
// 00550ed7  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00550edf  2b742438             sub esi, dword ptr [esp + 0x38]
// 00550ee3  2b6c2434             sub ebp, dword ptr [esp + 0x34]
// 00550ee7  8d44241c             lea eax, [esp + 0x1c]
// 00550eeb  50                   push eax
// 00550eec  8d4c2418             lea ecx, [esp + 0x18]
// 00550ef0  51                   push ecx
// 00550ef1  56                   push esi
// 00550ef2  55                   push ebp
// 00550ef3  e818feffff           call 0x550d10
// 00550ef8  2b7c2444             sub edi, dword ptr [esp + 0x44]
// 00550efc  2b5c2448             sub ebx, dword ptr [esp + 0x48]
// 00550f00  8d542430             lea edx, [esp + 0x30]
// 00550f04  52                   push edx
// 00550f05  8d44242c             lea eax, [esp + 0x2c]
// 00550f09  50                   push eax
// 00550f0a  57                   push edi
// 00550f0b  53                   push ebx
// 00550f0c  e8fffdffff           call 0x550d10
// 00550f11  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00550f15  83c420               add esp, 0x20
// 00550f18  5f                   pop edi
// 00550f19  5e                   pop esi
// 00550f1a  5d                   pop ebp
// 00550f1b  5b                   pop ebx
// 00550f1c  3b4c2408             cmp ecx, dword ptr [esp + 8]
// 00550f20  7522                 jne 0x550f44
// 00550f22  8b54240c             mov edx, dword ptr [esp + 0xc]
// 00550f26  3b542410             cmp edx, dword ptr [esp + 0x10]
// 00550f2a  7518                 jne 0x550f44
// 00550f2c  8b442418             mov eax, dword ptr [esp + 0x18]
// 00550f30  68e804a800           push 0xa804e8
// 00550f35  50                   push eax
// 00550f36  e8a5040100           call 0x5613e0
// 00550f3b  83c408               add esp, 8
// 00550f3e  33c0                 xor eax, eax
// 00550f40  83c414               add esp, 0x14
// 00550f43  c3                   ret 
// 00550f44  8b0424               mov eax, dword ptr [esp]
// 00550f47  83c414               add esp, 0x14
// 00550f4a  c3                   ret 
// library libpng-1.2.35/png.c (function _png_check_cHRM_fixed)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.35 png.c
