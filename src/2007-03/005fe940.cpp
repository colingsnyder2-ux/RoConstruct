// from server: 100% by auto
// roc 2007-03 005fe940  unit: seg_005f0000  size: 472 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005fe940
//
// 005fe940  56                   push esi
// 005fe941  8bf0                 mov esi, eax
// 005fe943  8b4310               mov eax, dword ptr [ebx + 0x10]
// 005fe946  83c085               add eax, -0x7b
// 005fe949  3da3000000           cmp eax, 0xa3
// 005fe94e  57                   push edi
// 005fe94f  0f87ec000000         ja 0x5fea41
// 005fe955  0fb68074ea5f00       movzx eax, byte ptr [eax + 0x5fea74]
// 005fe95c  ff248550ea5f00       jmp dword ptr [eax*4 + 0x5fea50]
// 005fe963  83c9ff               or ecx, 0xffffffff
// 005fe966  c7460800000000       mov dword ptr [esi + 8], 0
// 005fe96d  894e10               mov dword ptr [esi + 0x10], ecx
// 005fe970  894e14               mov dword ptr [esi + 0x14], ecx
// 005fe973  c70605000000         mov dword ptr [esi], 5
// 005fe979  dd4318               fld qword ptr [ebx + 0x18]
// 005fe97c  53                   push ebx
// 005fe97d  dd5e08               fstp qword ptr [esi + 8]
// 005fe980  e81b3a0000           call 0x6023a0
// 005fe985  83c404               add esp, 4
// 005fe988  5f                   pop edi
// 005fe989  5e                   pop esi
// 005fe98a  c3                   ret 
// 005fe98b  8b4318               mov eax, dword ptr [ebx + 0x18]
// 005fe98e  8bcb                 mov ecx, ebx
// 005fe990  e8abebffff           call 0x5fd540
// 005fe995  53                   push ebx
// 005fe996  e8053a0000           call 0x6023a0
// 005fe99b  83c404               add esp, 4
// 005fe99e  5f                   pop edi
// 005fe99f  5e                   pop esi
// 005fe9a0  c3                   ret 
// 005fe9a1  c70601000000         mov dword ptr [esi], 1
// 005fe9a7  c7460800000000       mov dword ptr [esi + 8], 0
// 005fe9ae  eb57                 jmp 0x5fea07
// 005fe9b0  c70602000000         mov dword ptr [esi], 2
// 005fe9b6  c7460800000000       mov dword ptr [esi + 8], 0
// 005fe9bd  eb48                 jmp 0x5fea07
// 005fe9bf  c70603000000         mov dword ptr [esi], 3
// 005fe9c5  c7460800000000       mov dword ptr [esi + 8], 0
// 005fe9cc  eb39                 jmp 0x5fea07
// 005fe9ce  8b7b30               mov edi, dword ptr [ebx + 0x30]
// 005fe9d1  8b0f                 mov ecx, dword ptr [edi]
// 005fe9d3  80794a00             cmp byte ptr [ecx + 0x4a], 0
// 005fe9d7  750e                 jne 0x5fe9e7
// 005fe9d9  68c4057c00           push 0x7c05c4
// 005fe9de  53                   push ebx
// 005fe9df  e88c250000           call 0x600f70
// 005fe9e4  83c408               add esp, 8
// 005fe9e7  8b07                 mov eax, dword ptr [edi]
// 005fe9e9  80604afb             and byte ptr [eax + 0x4a], 0xfb
// 005fe9ed  6a00                 push 0
// 005fe9ef  6a01                 push 1
// 005fe9f1  6a00                 push 0
// 005fe9f3  6a25                 push 0x25
// 005fe9f5  57                   push edi
// 005fe9f6  e8b5610100           call 0x614bb0
// 005fe9fb  83c414               add esp, 0x14
// 005fe9fe  c7060e000000         mov dword ptr [esi], 0xe
// 005fea04  894608               mov dword ptr [esi + 8], eax
// 005fea07  83c9ff               or ecx, 0xffffffff
// 005fea0a  53                   push ebx
// 005fea0b  894e14               mov dword ptr [esi + 0x14], ecx
// 005fea0e  894e10               mov dword ptr [esi + 0x10], ecx
// 005fea11  e88a390000           call 0x6023a0
// 005fea16  83c404               add esp, 4
// 005fea19  5f                   pop edi
// 005fea1a  5e                   pop esi
// 005fea1b  c3                   ret 
// 005fea1c  5f                   pop edi
// 005fea1d  8bc6                 mov eax, esi
// 005fea1f  8bcb                 mov ecx, ebx
// 005fea21  5e                   pop esi
// 005fea22  e939f5ffff           jmp 0x5fdf60
// 005fea27  53                   push ebx
// 005fea28  e873390000           call 0x6023a0
// 005fea2d  8b5304               mov edx, dword ptr [ebx + 4]
// 005fea30  52                   push edx
// 005fea31  6a00                 push 0
// 005fea33  56                   push esi
// 005fea34  8bc3                 mov eax, ebx
// 005fea36  e8d5f8ffff           call 0x5fe310
// 005fea3b  83c410               add esp, 0x10
// 005fea3e  5f                   pop edi
// 005fea3f  5e                   pop esi
// 005fea40  c3                   ret 
// 005fea41  8bfe                 mov edi, esi
// 005fea43  8bf3                 mov esi, ebx
// 005fea45  e806fcffff           call 0x5fe650
// 005fea4a  5f                   pop edi
// 005fea4b  5e                   pop esi
// 005fea4c  c3                   ret 
// 005fea4d  8d4900               lea ecx, [ecx]
// 005fea50  1cea                 sbb al, 0xea
// 005fea52  5f                   pop edi
// 005fea53  00bfe95f0027         add byte ptr [edi + 0x27005fe9], bh
// 005fea59  ea5f00a1e95f00       ljmp 0x5f:0xe9a1005f
// 005fea60  b0e9                 mov al, 0xe9
// 005fea62  5f                   pop edi
// 005fea63  00ce                 add dh, cl
// 005fea65  e95f0063e9           jmp 0xe9c2eac9
// 005fea6a  5f                   pop edi
// 005fea6b  008be95f0041         add byte ptr [ebx + 0x41005fe9], cl
// 005fea71  ea5f0000080808       ljmp 0x808:0x800005f
// 005fea78  0808                 or byte ptr [eax], cl
// 005fea7a  0808                 or byte ptr [eax], cl
// 005fea7c  0808                 or byte ptr [eax], cl
// 005fea7e  0808                 or byte ptr [eax], cl
// 005fea80  0808                 or byte ptr [eax], cl
// 005fea82  0808                 or byte ptr [eax], cl
// 005fea84  0808                 or byte ptr [eax], cl
// 005fea86  0808                 or byte ptr [eax], cl
// 005fea88  0808                 or byte ptr [eax], cl
// 005fea8a  0808                 or byte ptr [eax], cl
// 005fea8c  0808                 or byte ptr [eax], cl
// 005fea8e  0808                 or byte ptr [eax], cl
// 005fea90  0808                 or byte ptr [eax], cl
// 005fea92  0808                 or byte ptr [eax], cl
// 005fea94  0808                 or byte ptr [eax], cl
// 005fea96  0808                 or byte ptr [eax], cl
// 005fea98  0808                 or byte ptr [eax], cl
// 005fea9a  0808                 or byte ptr [eax], cl
// 005fea9c  0808                 or byte ptr [eax], cl
// 005fea9e  0808                 or byte ptr [eax], cl
// 005feaa0  0808                 or byte ptr [eax], cl
// 005feaa2  0808                 or byte ptr [eax], cl
// 005feaa4  0808                 or byte ptr [eax], cl
// 005feaa6  0808                 or byte ptr [eax], cl
// 005feaa8  0808                 or byte ptr [eax], cl
// 005feaaa  0808                 or byte ptr [eax], cl
// 005feaac  0808                 or byte ptr [eax], cl
// 005feaae  0808                 or byte ptr [eax], cl
// 005feab0  0808                 or byte ptr [eax], cl
// 005feab2  0808                 or byte ptr [eax], cl
// 005feab4  0808                 or byte ptr [eax], cl
// 005feab6  0808                 or byte ptr [eax], cl
// 005feab8  0808                 or byte ptr [eax], cl
// 005feaba  0808                 or byte ptr [eax], cl
// 005feabc  0808                 or byte ptr [eax], cl
// 005feabe  0808                 or byte ptr [eax], cl
// 005feac0  0808                 or byte ptr [eax], cl
// 005feac2  0808                 or byte ptr [eax], cl
// 005feac4  0808                 or byte ptr [eax], cl
// 005feac6  0808                 or byte ptr [eax], cl
// 005feac8  0808                 or byte ptr [eax], cl
// 005feaca  0808                 or byte ptr [eax], cl
// 005feacc  0808                 or byte ptr [eax], cl
// 005feace  0808                 or byte ptr [eax], cl
// 005fead0  0808                 or byte ptr [eax], cl
// 005fead2  0808                 or byte ptr [eax], cl
// 005fead4  0808                 or byte ptr [eax], cl
// 005fead6  0808                 or byte ptr [eax], cl
// 005fead8  0808                 or byte ptr [eax], cl
// 005feada  0808                 or byte ptr [eax], cl
// 005feadc  0808                 or byte ptr [eax], cl
// 005feade  0808                 or byte ptr [eax], cl
// 005feae0  0808                 or byte ptr [eax], cl
// 005feae2  0808                 or byte ptr [eax], cl
// 005feae4  0808                 or byte ptr [eax], cl
// 005feae6  0808                 or byte ptr [eax], cl
// 005feae8  0808                 or byte ptr [eax], cl
// 005feaea  0808                 or byte ptr [eax], cl
// 005feaec  0808                 or byte ptr [eax], cl
// 005feaee  0808                 or byte ptr [eax], cl
// 005feaf0  0808                 or byte ptr [eax], cl
// 005feaf2  0808                 or byte ptr [eax], cl
// 005feaf4  0808                 or byte ptr [eax], cl
// 005feaf6  0808                 or byte ptr [eax], cl
// 005feaf8  0808                 or byte ptr [eax], cl
// 005feafa  0808                 or byte ptr [eax], cl
// 005feafc  0808                 or byte ptr [eax], cl
// 005feafe  0808                 or byte ptr [eax], cl
// 005feb00  0108                 add dword ptr [eax], ecx
// 005feb02  0208                 add cl, byte ptr [eax]
// 005feb04  0808                 or byte ptr [eax], cl
// 005feb06  0308                 add ecx, dword ptr [eax]
// 005feb08  0808                 or byte ptr [eax], cl
// 005feb0a  0808                 or byte ptr [eax], cl
// 005feb0c  0408                 add al, 8
// 005feb0e  0808                 or byte ptr [eax], cl
// 005feb10  0508080808           add eax, 0x8080808
// 005feb15  06                   push es
// 005feb16  0807                 or byte ptr [edi], al
// library lua-5.1.1/lparser.c (function _simpleexp)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.1 lparser.c
