// from server: 100% by auto
// roc 2009-06 006c3a40  unit: lua_exception  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c3a40
//
// 006c3a40  53                   push ebx
// 006c3a41  56                   push esi
// 006c3a42  57                   push edi
// 006c3a43  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 006c3a47  6884000000           push 0x84
// 006c3a4c  33db                 xor ebx, ebx
// 006c3a4e  53                   push ebx
// 006c3a4f  53                   push ebx
// 006c3a50  57                   push edi
// 006c3a51  e80a9d0200           call 0x6ed760
// 006c3a56  8bf0                 mov esi, eax
// 006c3a58  6a08                 push 8
// 006c3a5a  83c60c               add esi, 0xc
// 006c3a5d  56                   push esi
// 006c3a5e  57                   push edi
// 006c3a5f  e8ac620200           call 0x6e9d10
// 006c3a64  8b4710               mov eax, dword ptr [edi + 0x10]
// 006c3a67  33c9                 xor ecx, ecx
// 006c3a69  33d2                 xor edx, edx
// 006c3a6b  83c41c               add esp, 0x1c
// 006c3a6e  894610               mov dword ptr [esi + 0x10], eax
// 006c3a71  895e20               mov dword ptr [esi + 0x20], ebx
// 006c3a74  895e2c               mov dword ptr [esi + 0x2c], ebx
// 006c3a77  895e70               mov dword ptr [esi + 0x70], ebx
// 006c3a7a  895e44               mov dword ptr [esi + 0x44], ebx
// 006c3a7d  885e38               mov byte ptr [esi + 0x38], bl
// 006c3a80  895e3c               mov dword ptr [esi + 0x3c], ebx
// 006c3a83  c6463901             mov byte ptr [esi + 0x39], 1
// 006c3a87  895e40               mov dword ptr [esi + 0x40], ebx
// 006c3a8a  895e68               mov dword ptr [esi + 0x68], ebx
// 006c3a8d  895e30               mov dword ptr [esi + 0x30], ebx
// 006c3a90  66894e36             mov word ptr [esi + 0x36], cx
// 006c3a94  66895634             mov word ptr [esi + 0x34], dx
// 006c3a98  885e06               mov byte ptr [esi + 6], bl
// 006c3a9b  895e14               mov dword ptr [esi + 0x14], ebx
// 006c3a9e  895e28               mov dword ptr [esi + 0x28], ebx
// 006c3aa1  895e18               mov dword ptr [esi + 0x18], ebx
// 006c3aa4  895e74               mov dword ptr [esi + 0x74], ebx
// 006c3aa7  895e50               mov dword ptr [esi + 0x50], ebx
// 006c3aaa  e801feffff           call 0x6c38b0
// 006c3aaf  8b4748               mov eax, dword ptr [edi + 0x48]
// 006c3ab2  894648               mov dword ptr [esi + 0x48], eax
// 006c3ab5  8b4f4c               mov ecx, dword ptr [edi + 0x4c]
// 006c3ab8  894e4c               mov dword ptr [esi + 0x4c], ecx
// 006c3abb  8b5750               mov edx, dword ptr [edi + 0x50]
// 006c3abe  895650               mov dword ptr [esi + 0x50], edx
// 006c3ac1  8a4738               mov al, byte ptr [edi + 0x38]
// 006c3ac4  884638               mov byte ptr [esi + 0x38], al
// 006c3ac7  8b4f3c               mov ecx, dword ptr [edi + 0x3c]
// 006c3aca  894e3c               mov dword ptr [esi + 0x3c], ecx
// 006c3acd  8b5744               mov edx, dword ptr [edi + 0x44]
// 006c3ad0  8bc1                 mov eax, ecx
// 006c3ad2  894640               mov dword ptr [esi + 0x40], eax
// 006c3ad5  5f                   pop edi
// 006c3ad6  895644               mov dword ptr [esi + 0x44], edx
// 006c3ad9  8bc6                 mov eax, esi
// 006c3adb  5e                   pop esi
// 006c3adc  5b                   pop ebx
// 006c3add  c3                   ret 
// library lua-5.1.3-rbx/lstate.c (function _luaE_newthread)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3-rbx lstate.c
