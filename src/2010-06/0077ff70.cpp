// from server: 100% by auto
// roc 2010-06 0077ff70  unit: seg_00770000  size: 472 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0077ff70
//
// 0077ff70  56                   push esi
// 0077ff71  8bf0                 mov esi, eax
// 0077ff73  8b4310               mov eax, dword ptr [ebx + 0x10]
// 0077ff76  83c085               add eax, -0x7b
// 0077ff79  57                   push edi
// 0077ff7a  3da3000000           cmp eax, 0xa3
// 0077ff7f  0f87ec000000         ja 0x780071
// 0077ff85  0fb680a4007800       movzx eax, byte ptr [eax + 0x7800a4]
// 0077ff8c  ff248580007800       jmp dword ptr [eax*4 + 0x780080]
// 0077ff93  83c9ff               or ecx, 0xffffffff
// 0077ff96  c7460800000000       mov dword ptr [esi + 8], 0
// 0077ff9d  894e10               mov dword ptr [esi + 0x10], ecx
// 0077ffa0  894e14               mov dword ptr [esi + 0x14], ecx
// 0077ffa3  c70605000000         mov dword ptr [esi], 5
// 0077ffa9  dd4318               fld qword ptr [ebx + 0x18]
// 0077ffac  53                   push ebx
// 0077ffad  dd5e08               fstp qword ptr [esi + 8]
// 0077ffb0  e8cb390000           call 0x783980
// 0077ffb5  83c404               add esp, 4
// 0077ffb8  5f                   pop edi
// 0077ffb9  5e                   pop esi
// 0077ffba  c3                   ret 
// 0077ffbb  8b4318               mov eax, dword ptr [ebx + 0x18]
// 0077ffbe  8bcb                 mov ecx, ebx
// 0077ffc0  e8dbebffff           call 0x77eba0
// 0077ffc5  53                   push ebx
// 0077ffc6  e8b5390000           call 0x783980
// 0077ffcb  83c404               add esp, 4
// 0077ffce  5f                   pop edi
// 0077ffcf  5e                   pop esi
// 0077ffd0  c3                   ret 
// 0077ffd1  c70601000000         mov dword ptr [esi], 1
// 0077ffd7  c7460800000000       mov dword ptr [esi + 8], 0
// 0077ffde  eb57                 jmp 0x780037
// 0077ffe0  c70602000000         mov dword ptr [esi], 2
// 0077ffe6  c7460800000000       mov dword ptr [esi + 8], 0
// 0077ffed  eb48                 jmp 0x780037
// 0077ffef  c70603000000         mov dword ptr [esi], 3
// 0077fff5  c7460800000000       mov dword ptr [esi + 8], 0
// 0077fffc  eb39                 jmp 0x780037
// 0077fffe  8b7b30               mov edi, dword ptr [ebx + 0x30]
// 00780001  8b0f                 mov ecx, dword ptr [edi]
// 00780003  80794a00             cmp byte ptr [ecx + 0x4a], 0
// 00780007  750e                 jne 0x780017
// 00780009  68d431a500           push 0xa531d4
// 0078000e  53                   push ebx
// 0078000f  e87c250000           call 0x782590
// 00780014  83c408               add esp, 8
// 00780017  8b07                 mov eax, dword ptr [edi]
// 00780019  80604afb             and byte ptr [eax + 0x4a], 0xfb
// 0078001d  6a00                 push 0
// 0078001f  6a01                 push 1
// 00780021  6a00                 push 0
// 00780023  6a25                 push 0x25
// 00780025  57                   push edi
// 00780026  e835fb0000           call 0x78fb60
// 0078002b  83c414               add esp, 0x14
// 0078002e  c7060e000000         mov dword ptr [esi], 0xe
// 00780034  894608               mov dword ptr [esi + 8], eax
// 00780037  83c9ff               or ecx, 0xffffffff
// 0078003a  53                   push ebx
// 0078003b  894e14               mov dword ptr [esi + 0x14], ecx
// 0078003e  894e10               mov dword ptr [esi + 0x10], ecx
// 00780041  e83a390000           call 0x783980
// 00780046  83c404               add esp, 4
// 00780049  5f                   pop edi
// 0078004a  5e                   pop esi
// 0078004b  c3                   ret 
// 0078004c  5f                   pop edi
// 0078004d  8bc6                 mov eax, esi
// 0078004f  8bcb                 mov ecx, ebx
// 00780051  5e                   pop esi
// 00780052  e939f5ffff           jmp 0x77f590
// 00780057  53                   push ebx
// 00780058  e823390000           call 0x783980
// 0078005d  8b5304               mov edx, dword ptr [ebx + 4]
// 00780060  52                   push edx
// 00780061  6a00                 push 0
// 00780063  56                   push esi
// 00780064  8bc3                 mov eax, ebx
// 00780066  e8d5f8ffff           call 0x77f940
// 0078006b  83c410               add esp, 0x10
// 0078006e  5f                   pop edi
// 0078006f  5e                   pop esi
// 00780070  c3                   ret 
// 00780071  8bfe                 mov edi, esi
// 00780073  8bf3                 mov esi, ebx
// 00780075  e806fcffff           call 0x77fc80
// 0078007a  5f                   pop edi
// 0078007b  5e                   pop esi
// 0078007c  c3                   ret 
// 0078007d  8d4900               lea ecx, [ecx]
// 00780080  4c                   dec esp
// 00780081  007800               add byte ptr [eax], bh
// 00780084  ef                   out dx, eax
// 00780085  ff7700               push dword ptr [edi]
// 00780088  57                   push edi
// 00780089  007800               add byte ptr [eax], bh
// 0078008c  d1ff                 sar edi, 1
// 0078008e  7700                 ja 0x780090
// 00780090  e0ff                 loopne 0x780091
// 00780092  7700                 ja 0x780094
// library lua-5.1/lparser.c (function _simpleexp)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
