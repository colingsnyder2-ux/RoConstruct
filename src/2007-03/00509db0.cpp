// from server: 100% by auto
// roc 2007-03 00509db0  unit: seg_00500000  size: 251 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00509db0
//
// 00509db0  57                   push edi
// 00509db1  8b7c2408             mov edi, dword ptr [esp + 8]
// 00509db5  85ff                 test edi, edi
// 00509db7  0f84ec000000         je 0x509ea9
// 00509dbd  56                   push esi
// 00509dbe  8b742410             mov esi, dword ptr [esp + 0x10]
// 00509dc2  85f6                 test esi, esi
// 00509dc4  0f84de000000         je 0x509ea8
// 00509dca  53                   push ebx
// 00509dcb  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 00509dcf  85db                 test ebx, ebx
// 00509dd1  0f84d0000000         je 0x509ea7
// 00509dd7  837c242000           cmp dword ptr [esp + 0x20], 0
// 00509ddc  0f84c5000000         je 0x509ea7
// 00509de2  8bc3                 mov eax, ebx
// 00509de4  8d5001               lea edx, [eax + 1]
// 00509de7  8a08                 mov cl, byte ptr [eax]
// 00509de9  83c001               add eax, 1
// 00509dec  84c9                 test cl, cl
// 00509dee  75f7                 jne 0x509de7
// 00509df0  2bc2                 sub eax, edx
// 00509df2  55                   push ebp
// 00509df3  83c001               add eax, 1
// 00509df6  50                   push eax
// 00509df7  57                   push edi
// 00509df8  e823f20000           call 0x519020
// 00509dfd  8be8                 mov ebp, eax
// 00509dff  83c408               add esp, 8
// 00509e02  85ed                 test ebp, ebp
// 00509e04  7513                 jne 0x509e19
// 00509e06  68280d7a00           push 0x7a0d28
// 00509e0b  57                   push edi
// 00509e0c  e8bfe50000           call 0x5183d0
// 00509e11  83c408               add esp, 8
// 00509e14  5d                   pop ebp
// 00509e15  5b                   pop ebx
// 00509e16  5e                   pop esi
// 00509e17  5f                   pop edi
// 00509e18  c3                   ret 
// 00509e19  8bd5                 mov edx, ebp
// 00509e1b  8bc3                 mov eax, ebx
// 00509e1d  2bd3                 sub edx, ebx
// 00509e1f  90                   nop 
// 00509e20  8a08                 mov cl, byte ptr [eax]
// 00509e22  880c02               mov byte ptr [edx + eax], cl
// 00509e25  83c001               add eax, 1
// 00509e28  84c9                 test cl, cl
// 00509e2a  75f4                 jne 0x509e20
// 00509e2c  8b5c2428             mov ebx, dword ptr [esp + 0x28]
// 00509e30  53                   push ebx
// 00509e31  57                   push edi
// 00509e32  e8e9f10000           call 0x519020
// 00509e37  8bf8                 mov edi, eax
// 00509e39  83c408               add esp, 8
// 00509e3c  85ff                 test edi, edi
// 00509e3e  751e                 jne 0x509e5e
// 00509e40  8b742414             mov esi, dword ptr [esp + 0x14]
// 00509e44  55                   push ebp
// 00509e45  56                   push esi
// 00509e46  e8a5f10000           call 0x518ff0
// 00509e4b  68f80c7a00           push 0x7a0cf8
// 00509e50  56                   push esi
// 00509e51  e87ae50000           call 0x5183d0
// 00509e56  83c410               add esp, 0x10
// 00509e59  5d                   pop ebp
// 00509e5a  5b                   pop ebx
// 00509e5b  5e                   pop esi
// 00509e5c  5f                   pop edi
// 00509e5d  c3                   ret 
// 00509e5e  8b442424             mov eax, dword ptr [esp + 0x24]
// 00509e62  53                   push ebx
// 00509e63  50                   push eax
// 00509e64  57                   push edi
// 00509e65  e878531100           call 0x61f1e2
// 00509e6a  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00509e6e  6a00                 push 0
// 00509e70  6a10                 push 0x10
// 00509e72  56                   push esi
// 00509e73  51                   push ecx
// 00509e74  e807090000           call 0x50a780
// 00509e79  8a54243c             mov dl, byte ptr [esp + 0x3c]
// 00509e7d  838eb800000010       or dword ptr [esi + 0xb8], 0x10
// 00509e84  83c41c               add esp, 0x1c
// 00509e87  814e0800100000       or dword ptr [esi + 8], 0x1000
// 00509e8e  89aec4000000         mov dword ptr [esi + 0xc4], ebp
// 00509e94  899ecc000000         mov dword ptr [esi + 0xcc], ebx
// 00509e9a  89bec8000000         mov dword ptr [esi + 0xc8], edi
// 00509ea0  8896d0000000         mov byte ptr [esi + 0xd0], dl
// 00509ea6  5d                   pop ebp
// 00509ea7  5b                   pop ebx
// 00509ea8  5e                   pop esi
// 00509ea9  5f                   pop edi
// 00509eaa  c3                   ret 
// library libpng-1.2.7/pngset.c (function _png_set_iCCP)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngset.c
