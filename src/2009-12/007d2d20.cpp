// from server: 100% by auto
// roc 2009-12 007d2d20  unit: seg_007d0000  size: 472 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d2d20
//
// 007d2d20  56                   push esi
// 007d2d21  8bf0                 mov esi, eax
// 007d2d23  8b4310               mov eax, dword ptr [ebx + 0x10]
// 007d2d26  83c085               add eax, -0x7b
// 007d2d29  57                   push edi
// 007d2d2a  3da3000000           cmp eax, 0xa3
// 007d2d2f  0f87ec000000         ja 0x7d2e21
// 007d2d35  0fb680542e7d00       movzx eax, byte ptr [eax + 0x7d2e54]
// 007d2d3c  ff2485302e7d00       jmp dword ptr [eax*4 + 0x7d2e30]
// 007d2d43  83c9ff               or ecx, 0xffffffff
// 007d2d46  c7460800000000       mov dword ptr [esi + 8], 0
// 007d2d4d  894e10               mov dword ptr [esi + 0x10], ecx
// 007d2d50  894e14               mov dword ptr [esi + 0x14], ecx
// 007d2d53  c70605000000         mov dword ptr [esi], 5
// 007d2d59  dd4318               fld qword ptr [ebx + 0x18]
// 007d2d5c  53                   push ebx
// 007d2d5d  dd5e08               fstp qword ptr [esi + 8]
// 007d2d60  e8cb390000           call 0x7d6730
// 007d2d65  83c404               add esp, 4
// 007d2d68  5f                   pop edi
// 007d2d69  5e                   pop esi
// 007d2d6a  c3                   ret 
// 007d2d6b  8b4318               mov eax, dword ptr [ebx + 0x18]
// 007d2d6e  8bcb                 mov ecx, ebx
// 007d2d70  e8dbebffff           call 0x7d1950
// 007d2d75  53                   push ebx
// 007d2d76  e8b5390000           call 0x7d6730
// 007d2d7b  83c404               add esp, 4
// 007d2d7e  5f                   pop edi
// 007d2d7f  5e                   pop esi
// 007d2d80  c3                   ret 
// 007d2d81  c70601000000         mov dword ptr [esi], 1
// 007d2d87  c7460800000000       mov dword ptr [esi + 8], 0
// 007d2d8e  eb57                 jmp 0x7d2de7
// 007d2d90  c70602000000         mov dword ptr [esi], 2
// 007d2d96  c7460800000000       mov dword ptr [esi + 8], 0
// 007d2d9d  eb48                 jmp 0x7d2de7
// 007d2d9f  c70603000000         mov dword ptr [esi], 3
// 007d2da5  c7460800000000       mov dword ptr [esi + 8], 0
// 007d2dac  eb39                 jmp 0x7d2de7
// 007d2dae  8b7b30               mov edi, dword ptr [ebx + 0x30]
// 007d2db1  8b0f                 mov ecx, dword ptr [edi]
// 007d2db3  80794a00             cmp byte ptr [ecx + 0x4a], 0
// 007d2db7  750e                 jne 0x7d2dc7
// 007d2db9  686cef9e00           push 0x9eef6c
// 007d2dbe  53                   push ebx
// 007d2dbf  e87c250000           call 0x7d5340
// 007d2dc4  83c408               add esp, 8
// 007d2dc7  8b07                 mov eax, dword ptr [edi]
// 007d2dc9  80604afb             and byte ptr [eax + 0x4a], 0xfb
// 007d2dcd  6a00                 push 0
// 007d2dcf  6a01                 push 1
// 007d2dd1  6a00                 push 0
// 007d2dd3  6a25                 push 0x25
// 007d2dd5  57                   push edi
// 007d2dd6  e825980000           call 0x7dc600
// 007d2ddb  83c414               add esp, 0x14
// 007d2dde  c7060e000000         mov dword ptr [esi], 0xe
// 007d2de4  894608               mov dword ptr [esi + 8], eax
// 007d2de7  83c9ff               or ecx, 0xffffffff
// 007d2dea  53                   push ebx
// 007d2deb  894e14               mov dword ptr [esi + 0x14], ecx
// 007d2dee  894e10               mov dword ptr [esi + 0x10], ecx
// 007d2df1  e83a390000           call 0x7d6730
// 007d2df6  83c404               add esp, 4
// 007d2df9  5f                   pop edi
// 007d2dfa  5e                   pop esi
// 007d2dfb  c3                   ret 
// 007d2dfc  5f                   pop edi
// 007d2dfd  8bc6                 mov eax, esi
// 007d2dff  8bcb                 mov ecx, ebx
// 007d2e01  5e                   pop esi
// 007d2e02  e939f5ffff           jmp 0x7d2340
// 007d2e07  53                   push ebx
// 007d2e08  e823390000           call 0x7d6730
// 007d2e0d  8b5304               mov edx, dword ptr [ebx + 4]
// 007d2e10  52                   push edx
// 007d2e11  6a00                 push 0
// 007d2e13  56                   push esi
// 007d2e14  8bc3                 mov eax, ebx
// 007d2e16  e8d5f8ffff           call 0x7d26f0
// 007d2e1b  83c410               add esp, 0x10
// 007d2e1e  5f                   pop edi
// 007d2e1f  5e                   pop esi
// 007d2e20  c3                   ret 
// 007d2e21  8bfe                 mov edi, esi
// 007d2e23  8bf3                 mov esi, ebx
// 007d2e25  e806fcffff           call 0x7d2a30
// 007d2e2a  5f                   pop edi
// 007d2e2b  5e                   pop esi
// 007d2e2c  c3                   ret 
// 007d2e2d  8d4900               lea ecx, [ecx]
// 007d2e30  fc                   cld 
// 007d2e31  2d7d009f2d           sub eax, 0x2d9f007d
// 007d2e36  7d00                 jge 0x7d2e38
// 007d2e38  07                   pop es
// 007d2e39  2e7d00               jge 0x7d2e3c
// 007d2e3c  812d7d00902d7d00ae2d sub dword ptr [0x2d90007d], 0x2dae007d
// 007d2e46  7d00                 jge 0x7d2e48
// 007d2e48  43                   inc ebx
// 007d2e49  2d7d006b2d           sub eax, 0x2d6b007d
// 007d2e4e  7d00                 jge 0x7d2e50
// 007d2e50  212e                 and dword ptr [esi], ebp
// 007d2e52  7d00                 jge 0x7d2e54
// 007d2e54  0008                 add byte ptr [eax], cl
// 007d2e56  0808                 or byte ptr [eax], cl
// 007d2e58  0808                 or byte ptr [eax], cl
// 007d2e5a  0808                 or byte ptr [eax], cl
// 007d2e5c  0808                 or byte ptr [eax], cl
// 007d2e5e  0808                 or byte ptr [eax], cl
// 007d2e60  0808                 or byte ptr [eax], cl
// 007d2e62  0808                 or byte ptr [eax], cl
// 007d2e64  0808                 or byte ptr [eax], cl
// 007d2e66  0808                 or byte ptr [eax], cl
// 007d2e68  0808                 or byte ptr [eax], cl
// 007d2e6a  0808                 or byte ptr [eax], cl
// 007d2e6c  0808                 or byte ptr [eax], cl
// 007d2e6e  0808                 or byte ptr [eax], cl
// 007d2e70  0808                 or byte ptr [eax], cl
// 007d2e72  0808                 or byte ptr [eax], cl
// 007d2e74  0808                 or byte ptr [eax], cl
// 007d2e76  0808                 or byte ptr [eax], cl
// 007d2e78  0808                 or byte ptr [eax], cl
// 007d2e7a  0808                 or byte ptr [eax], cl
// 007d2e7c  0808                 or byte ptr [eax], cl
// 007d2e7e  0808                 or byte ptr [eax], cl
// 007d2e80  0808                 or byte ptr [eax], cl
// 007d2e82  0808                 or byte ptr [eax], cl
// 007d2e84  0808                 or byte ptr [eax], cl
// 007d2e86  0808                 or byte ptr [eax], cl
// 007d2e88  0808                 or byte ptr [eax], cl
// 007d2e8a  0808                 or byte ptr [eax], cl
// 007d2e8c  0808                 or byte ptr [eax], cl
// 007d2e8e  0808                 or byte ptr [eax], cl
// 007d2e90  0808                 or byte ptr [eax], cl
// 007d2e92  0808                 or byte ptr [eax], cl
// 007d2e94  0808                 or byte ptr [eax], cl
// 007d2e96  0808                 or byte ptr [eax], cl
// 007d2e98  0808                 or byte ptr [eax], cl
// 007d2e9a  0808                 or byte ptr [eax], cl
// 007d2e9c  0808                 or byte ptr [eax], cl
// 007d2e9e  0808                 or byte ptr [eax], cl
// 007d2ea0  0808                 or byte ptr [eax], cl
// 007d2ea2  0808                 or byte ptr [eax], cl
// 007d2ea4  0808                 or byte ptr [eax], cl
// 007d2ea6  0808                 or byte ptr [eax], cl
// 007d2ea8  0808                 or byte ptr [eax], cl
// 007d2eaa  0808                 or byte ptr [eax], cl
// 007d2eac  0808                 or byte ptr [eax], cl
// 007d2eae  0808                 or byte ptr [eax], cl
// 007d2eb0  0808                 or byte ptr [eax], cl
// 007d2eb2  0808                 or byte ptr [eax], cl
// 007d2eb4  0808                 or byte ptr [eax], cl
// 007d2eb6  0808                 or byte ptr [eax], cl
// 007d2eb8  0808                 or byte ptr [eax], cl
// 007d2eba  0808                 or byte ptr [eax], cl
// 007d2ebc  0808                 or byte ptr [eax], cl
// 007d2ebe  0808                 or byte ptr [eax], cl
// 007d2ec0  0808                 or byte ptr [eax], cl
// 007d2ec2  0808                 or byte ptr [eax], cl
// 007d2ec4  0808                 or byte ptr [eax], cl
// 007d2ec6  0808                 or byte ptr [eax], cl
// 007d2ec8  0808                 or byte ptr [eax], cl
// 007d2eca  0808                 or byte ptr [eax], cl
// 007d2ecc  0808                 or byte ptr [eax], cl
// 007d2ece  0808                 or byte ptr [eax], cl
// 007d2ed0  0808                 or byte ptr [eax], cl
// 007d2ed2  0808                 or byte ptr [eax], cl
// 007d2ed4  0808                 or byte ptr [eax], cl
// 007d2ed6  0808                 or byte ptr [eax], cl
// 007d2ed8  0808                 or byte ptr [eax], cl
// 007d2eda  0808                 or byte ptr [eax], cl
// 007d2edc  0808                 or byte ptr [eax], cl
// 007d2ede  0808                 or byte ptr [eax], cl
// 007d2ee0  0108                 add dword ptr [eax], ecx
// 007d2ee2  0208                 add cl, byte ptr [eax]
// 007d2ee4  0808                 or byte ptr [eax], cl
// 007d2ee6  0308                 add ecx, dword ptr [eax]
// 007d2ee8  0808                 or byte ptr [eax], cl
// 007d2eea  0808                 or byte ptr [eax], cl
// 007d2eec  0408                 add al, 8
// 007d2eee  0808                 or byte ptr [eax], cl
// 007d2ef0  0508080808           add eax, 0x8080808
// 007d2ef5  06                   push es
// 007d2ef6  0807                 or byte ptr [edi], al
// library lua-5.1/lparser.c (function _simpleexp)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
