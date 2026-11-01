// from server: 100% by auto
// roc 2009-06 006c3cb0  unit: lua_exception  size: 325 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 006c3cb0
//
// 006c3cb0  53                   push ebx
// 006c3cb1  55                   push ebp
// 006c3cb2  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 006c3cb6  57                   push edi
// 006c3cb7  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 006c3cbb  6884010000           push 0x184
// 006c3cc0  33db                 xor ebx, ebx
// 006c3cc2  53                   push ebx
// 006c3cc3  53                   push ebx
// 006c3cc4  57                   push edi
// 006c3cc5  ffd5                 call ebp
// 006c3cc7  83c410               add esp, 0x10
// 006c3cca  3bc3                 cmp eax, ebx
// 006c3ccc  7506                 jne 0x6c3cd4
// 006c3cce  5f                   pop edi
// 006c3ccf  5d                   pop ebp
// 006c3cd0  33c0                 xor eax, eax
// 006c3cd2  5b                   pop ebx
// 006c3cd3  c3                   ret 
// 006c3cd4  89580c               mov dword ptr [eax + 0xc], ebx
// 006c3cd7  c6401008             mov byte ptr [eax + 0x10], 8
// 006c3cdb  56                   push esi
// 006c3cdc  8d700c               lea esi, [eax + 0xc]
// 006c3cdf  8d4678               lea eax, [esi + 0x78]
// 006c3ce2  c6401421             mov byte ptr [eax + 0x14], 0x21
// 006c3ce6  894610               mov dword ptr [esi + 0x10], eax
// 006c3ce9  c6460561             mov byte ptr [esi + 5], 0x61
// 006c3ced  895e20               mov dword ptr [esi + 0x20], ebx
// 006c3cf0  895e2c               mov dword ptr [esi + 0x2c], ebx
// 006c3cf3  895e70               mov dword ptr [esi + 0x70], ebx
// 006c3cf6  895e44               mov dword ptr [esi + 0x44], ebx
// 006c3cf9  885e38               mov byte ptr [esi + 0x38], bl
// 006c3cfc  895e3c               mov dword ptr [esi + 0x3c], ebx
// 006c3cff  c6463901             mov byte ptr [esi + 0x39], 1
// 006c3d03  895e40               mov dword ptr [esi + 0x40], ebx
// 006c3d06  895e68               mov dword ptr [esi + 0x68], ebx
// 006c3d09  895e30               mov dword ptr [esi + 0x30], ebx
// 006c3d0c  885e06               mov byte ptr [esi + 6], bl
// 006c3d0f  895e14               mov dword ptr [esi + 0x14], ebx
// 006c3d12  895e28               mov dword ptr [esi + 0x28], ebx
// 006c3d15  895e18               mov dword ptr [esi + 0x18], ebx
// 006c3d18  895e74               mov dword ptr [esi + 0x74], ebx
// 006c3d1b  895e50               mov dword ptr [esi + 0x50], ebx
// 006c3d1e  33c9                 xor ecx, ecx
// 006c3d20  66894e36             mov word ptr [esi + 0x36], cx
// 006c3d24  8d4878               lea ecx, [eax + 0x78]
// 006c3d27  33d2                 xor edx, edx
// 006c3d29  66895634             mov word ptr [esi + 0x34], dx
// 006c3d2d  898888000000         mov dword ptr [eax + 0x88], ecx
// 006c3d33  89888c000000         mov dword ptr [eax + 0x8c], ecx
// 006c3d39  89680c               mov dword ptr [eax + 0xc], ebp
// 006c3d3c  897810               mov dword ptr [eax + 0x10], edi
// 006c3d3f  897070               mov dword ptr [eax + 0x70], esi
// 006c3d42  895840               mov dword ptr [eax + 0x40], ebx
// 006c3d45  895808               mov dword ptr [eax + 8], ebx
// 006c3d48  895804               mov dword ptr [eax + 4], ebx
// 006c3d4b  8918                 mov dword ptr [eax], ebx
// 006c3d4d  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 006c3d50  895968               mov dword ptr [ecx + 0x68], ebx
// 006c3d53  89701c               mov dword ptr [eax + 0x1c], esi
// 006c3d56  895834               mov dword ptr [eax + 0x34], ebx
// 006c3d59  89583c               mov dword ptr [eax + 0x3c], ebx
// 006c3d5c  895858               mov dword ptr [eax + 0x58], ebx
// 006c3d5f  885815               mov byte ptr [eax + 0x15], bl
// 006c3d62  895818               mov dword ptr [eax + 0x18], ebx
// 006c3d65  895824               mov dword ptr [eax + 0x24], ebx
// 006c3d68  895828               mov dword ptr [eax + 0x28], ebx
// 006c3d6b  89582c               mov dword ptr [eax + 0x2c], ebx
// 006c3d6e  895830               mov dword ptr [eax + 0x30], ebx
// 006c3d71  c7404478010000       mov dword ptr [eax + 0x44], 0x178
// 006c3d78  89584c               mov dword ptr [eax + 0x4c], ebx
// 006c3d7b  8d481c               lea ecx, [eax + 0x1c]
// 006c3d7e  894820               mov dword ptr [eax + 0x20], ecx
// 006c3d81  53                   push ebx
// 006c3d82  b9c8000000           mov ecx, 0xc8
// 006c3d87  894850               mov dword ptr [eax + 0x50], ecx
// 006c3d8a  894854               mov dword ptr [eax + 0x54], ecx
// 006c3d8d  6830396c00           push 0x6c3930
// 006c3d92  56                   push esi
// 006c3d93  899898000000         mov dword ptr [eax + 0x98], ebx
// 006c3d99  89989c000000         mov dword ptr [eax + 0x9c], ebx
// 006c3d9f  8998a0000000         mov dword ptr [eax + 0xa0], ebx
// 006c3da5  8998a4000000         mov dword ptr [eax + 0xa4], ebx
// 006c3dab  8998a8000000         mov dword ptr [eax + 0xa8], ebx
// 006c3db1  8998ac000000         mov dword ptr [eax + 0xac], ebx
// 006c3db7  8998b0000000         mov dword ptr [eax + 0xb0], ebx
// 006c3dbd  8998b4000000         mov dword ptr [eax + 0xb4], ebx
// 006c3dc3  8998b8000000         mov dword ptr [eax + 0xb8], ebx
// 006c3dc9  e8c2edffff           call 0x6c2b90
// 006c3dce  83c40c               add esp, 0xc
// 006c3dd1  85c0                 test eax, eax
// 006c3dd3  7410                 je 0x6c3de5
// 006c3dd5  8bc6                 mov eax, esi
// 006c3dd7  e8d4fbffff           call 0x6c39b0
// 006c3ddc  33f6                 xor esi, esi
// 006c3dde  8bc6                 mov eax, esi
// 006c3de0  5e                   pop esi
// 006c3de1  5f                   pop edi
// 006c3de2  5d                   pop ebp
// 006c3de3  5b                   pop ebx
// 006c3de4  c3                   ret 
// 006c3de5  56                   push esi
// 006c3de6  e845feffff           call 0x6c3c30
// 006c3deb  83c404               add esp, 4
// 006c3dee  8bc6                 mov eax, esi
// 006c3df0  5e                   pop esi
// 006c3df1  5f                   pop edi
// 006c3df2  5d                   pop ebp
// 006c3df3  5b                   pop ebx
// 006c3df4  c3                   ret 
// library lua-5.1.3-rbx/lstate.c (function _lua_newstate)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3-rbx lstate.c
