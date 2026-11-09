// from server: 100% by auto
// roc 2011-06 00559d70  unit: seg_00550000  size: 401 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00559d70
//
// 00559d70  53                   push ebx
// 00559d71  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00559d75  85db                 test ebx, ebx
// 00559d77  0f846f010000         je 0x559eec
// 00559d7d  57                   push edi
// 00559d7e  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 00559d82  85ff                 test edi, edi
// 00559d84  0f8461010000         je 0x559eeb
// 00559d8a  55                   push ebp
// 00559d8b  8b6c2418             mov ebp, dword ptr [esp + 0x18]
// 00559d8f  8bc5                 mov eax, ebp
// 00559d91  8d5001               lea edx, [eax + 1]
// 00559d94  8a08                 mov cl, byte ptr [eax]
// 00559d96  40                   inc eax
// 00559d97  84c9                 test cl, cl
// 00559d99  75f9                 jne 0x559d94
// 00559d9b  56                   push esi
// 00559d9c  2bc2                 sub eax, edx
// 00559d9e  8d7001               lea esi, [eax + 1]
// 00559da1  56                   push esi
// 00559da2  53                   push ebx
// 00559da3  e828790000           call 0x5616d0
// 00559da8  83c408               add esp, 8
// 00559dab  8987a0000000         mov dword ptr [edi + 0xa0], eax
// 00559db1  85c0                 test eax, eax
// 00559db3  7513                 jne 0x559dc8
// 00559db5  68e023a800           push 0xa823e0
// 00559dba  53                   push ebx
// 00559dbb  e820760000           call 0x5613e0
// 00559dc0  83c408               add esp, 8
// 00559dc3  5e                   pop esi
// 00559dc4  5d                   pop ebp
// 00559dc5  5f                   pop edi
// 00559dc6  5b                   pop ebx
// 00559dc7  c3                   ret 
// 00559dc8  56                   push esi
// 00559dc9  55                   push ebp
// 00559dca  50                   push eax
// 00559dcb  e80c182b00           call 0x80b5dc
// 00559dd0  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00559dd4  8b6c243c             mov ebp, dword ptr [esp + 0x3c]
// 00559dd8  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00559ddc  8a542434             mov dl, byte ptr [esp + 0x34]
// 00559de0  8987a4000000         mov dword ptr [edi + 0xa4], eax
// 00559de6  8a442438             mov al, byte ptr [esp + 0x38]
// 00559dea  8887b5000000         mov byte ptr [edi + 0xb5], al
// 00559df0  8bc5                 mov eax, ebp
// 00559df2  83c40c               add esp, 0xc
// 00559df5  898fa8000000         mov dword ptr [edi + 0xa8], ecx
// 00559dfb  8897b4000000         mov byte ptr [edi + 0xb4], dl
// 00559e01  8d7001               lea esi, [eax + 1]
// 00559e04  8a08                 mov cl, byte ptr [eax]
// 00559e06  40                   inc eax
// 00559e07  84c9                 test cl, cl
// 00559e09  75f9                 jne 0x559e04
// 00559e0b  2bc6                 sub eax, esi
// 00559e0d  8d7001               lea esi, [eax + 1]
// 00559e10  56                   push esi
// 00559e11  53                   push ebx
// 00559e12  e8b9780000           call 0x5616d0
// 00559e17  83c408               add esp, 8
// 00559e1a  8987ac000000         mov dword ptr [edi + 0xac], eax
// 00559e20  85c0                 test eax, eax
// 00559e22  7513                 jne 0x559e37
// 00559e24  68bc23a800           push 0xa823bc
// 00559e29  53                   push ebx
// 00559e2a  e8b1750000           call 0x5613e0
// 00559e2f  83c408               add esp, 8
// 00559e32  5e                   pop esi
// 00559e33  5d                   pop ebp
// 00559e34  5f                   pop edi
// 00559e35  5b                   pop ebx
// 00559e36  c3                   ret 
// 00559e37  56                   push esi
// 00559e38  55                   push ebp
// 00559e39  50                   push eax
// 00559e3a  e89d172b00           call 0x80b5dc
// 00559e3f  8b742438             mov esi, dword ptr [esp + 0x38]
// 00559e43  8d34b504000000       lea esi, [esi*4 + 4]
// 00559e4a  56                   push esi
// 00559e4b  53                   push ebx
// 00559e4c  e87f780000           call 0x5616d0
// 00559e51  83c414               add esp, 0x14
// 00559e54  8987b0000000         mov dword ptr [edi + 0xb0], eax
// 00559e5a  85c0                 test eax, eax
// 00559e5c  7513                 jne 0x559e71
// 00559e5e  689423a800           push 0xa82394
// 00559e63  53                   push ebx
// 00559e64  e877750000           call 0x5613e0
// 00559e69  83c408               add esp, 8
// 00559e6c  5e                   pop esi
// 00559e6d  5d                   pop ebp
// 00559e6e  5f                   pop edi
// 00559e6f  5b                   pop ebx
// 00559e70  c3                   ret 
// 00559e71  56                   push esi
// 00559e72  6a00                 push 0
// 00559e74  50                   push eax
// 00559e75  e86a142b00           call 0x80b2e4
// 00559e7a  33f6                 xor esi, esi
// 00559e7c  83c40c               add esp, 0xc
// 00559e7f  3974242c             cmp dword ptr [esp + 0x2c], esi
// 00559e83  7e53                 jle 0x559ed8
// 00559e85  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00559e89  8b04b1               mov eax, dword ptr [ecx + esi*4]
// 00559e8c  8d5001               lea edx, [eax + 1]
// 00559e8f  90                   nop 
// 00559e90  8a08                 mov cl, byte ptr [eax]
// 00559e92  40                   inc eax
// 00559e93  84c9                 test cl, cl
// 00559e95  75f9                 jne 0x559e90
// 00559e97  2bc2                 sub eax, edx
// 00559e99  8d6801               lea ebp, [eax + 1]
// 00559e9c  55                   push ebp
// 00559e9d  53                   push ebx
// 00559e9e  e82d780000           call 0x5616d0
// 00559ea3  8b97b0000000         mov edx, dword ptr [edi + 0xb0]
// 00559ea9  8904b2               mov dword ptr [edx + esi*4], eax
// 00559eac  8b87b0000000         mov eax, dword ptr [edi + 0xb0]
// 00559eb2  8d04b0               lea eax, [eax + esi*4]
// 00559eb5  83c408               add esp, 8
// 00559eb8  833800               cmp dword ptr [eax], 0
// 00559ebb  7431                 je 0x559eee
// 00559ebd  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 00559ec1  8b14b1               mov edx, dword ptr [ecx + esi*4]
// 00559ec4  8b00                 mov eax, dword ptr [eax]
// 00559ec6  55                   push ebp
// 00559ec7  52                   push edx
// 00559ec8  50                   push eax
// 00559ec9  e80e172b00           call 0x80b5dc
// 00559ece  46                   inc esi
// 00559ecf  83c40c               add esp, 0xc
// 00559ed2  3b74242c             cmp esi, dword ptr [esp + 0x2c]
// 00559ed6  7cad                 jl 0x559e85
// 00559ed8  814f0800040000       or dword ptr [edi + 8], 0x400
// 00559edf  818fb800000080000000 or dword ptr [edi + 0xb8], 0x80
// 00559ee9  5e                   pop esi
// 00559eea  5d                   pop ebp
// 00559eeb  5f                   pop edi
// 00559eec  5b                   pop ebx
// 00559eed  c3                   ret 
// 00559eee  686c23a800           push 0xa8236c
// 00559ef3  53                   push ebx
// 00559ef4  e8e7740000           call 0x5613e0
// 00559ef9  83c408               add esp, 8
// 00559efc  5e                   pop esi
// 00559efd  5d                   pop ebp
// 00559efe  5f                   pop edi
// 00559eff  5b                   pop ebx
// 00559f00  c3                   ret 
// library libpng-1.2.37/pngset.c (function _png_set_pCAL)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.37 pngset.c
