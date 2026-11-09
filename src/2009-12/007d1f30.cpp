// from server: 100% by auto
// roc 2009-12 007d1f30  unit: seg_007d0000  size: 173 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007d1f30
//
// 007d1f30  55                   push ebp
// 007d1f31  56                   push esi
// 007d1f32  57                   push edi
// 007d1f33  8b7b34               mov edi, dword ptr [ebx + 0x34]
// 007d1f36  57                   push edi
// 007d1f37  8bf0                 mov esi, eax
// 007d1f39  e802f0ffff           call 0x7d0f40
// 007d1f3e  8be8                 mov ebp, eax
// 007d1f40  892e                 mov dword ptr [esi], ebp
// 007d1f42  8b4330               mov eax, dword ptr [ebx + 0x30]
// 007d1f45  894608               mov dword ptr [esi + 8], eax
// 007d1f48  33c0                 xor eax, eax
// 007d1f4a  895e0c               mov dword ptr [esi + 0xc], ebx
// 007d1f4d  897e10               mov dword ptr [esi + 0x10], edi
// 007d1f50  897330               mov dword ptr [ebx + 0x30], esi
// 007d1f53  83c9ff               or ecx, 0xffffffff
// 007d1f56  894e1c               mov dword ptr [esi + 0x1c], ecx
// 007d1f59  894e20               mov dword ptr [esi + 0x20], ecx
// 007d1f5c  50                   push eax
// 007d1f5d  894618               mov dword ptr [esi + 0x18], eax
// 007d1f60  894624               mov dword ptr [esi + 0x24], eax
// 007d1f63  894628               mov dword ptr [esi + 0x28], eax
// 007d1f66  89462c               mov dword ptr [esi + 0x2c], eax
// 007d1f69  33c9                 xor ecx, ecx
// 007d1f6b  66894e30             mov word ptr [esi + 0x30], cx
// 007d1f6f  884632               mov byte ptr [esi + 0x32], al
// 007d1f72  894614               mov dword ptr [esi + 0x14], eax
// 007d1f75  8b5340               mov edx, dword ptr [ebx + 0x40]
// 007d1f78  50                   push eax
// 007d1f79  57                   push edi
// 007d1f7a  895520               mov dword ptr [ebp + 0x20], edx
// 007d1f7d  c6454b02             mov byte ptr [ebp + 0x4b], 2
// 007d1f81  e80ae2ffff           call 0x7d0190
// 007d1f86  894604               mov dword ptr [esi + 4], eax
// 007d1f89  8b4f08               mov ecx, dword ptr [edi + 8]
// 007d1f8c  8901                 mov dword ptr [ecx], eax
// 007d1f8e  c7410805000000       mov dword ptr [ecx + 8], 5
// 007d1f95  8b471c               mov eax, dword ptr [edi + 0x1c]
// 007d1f98  2b4708               sub eax, dword ptr [edi + 8]
// 007d1f9b  be10000000           mov esi, 0x10
// 007d1fa0  83c410               add esp, 0x10
// 007d1fa3  3bc6                 cmp eax, esi
// 007d1fa5  7f0b                 jg 0x7d1fb2
// 007d1fa7  6a01                 push 1
// 007d1fa9  57                   push edi
// 007d1faa  e88153fcff           call 0x797330
// 007d1faf  83c408               add esp, 8
// 007d1fb2  017708               add dword ptr [edi + 8], esi
// 007d1fb5  8b4708               mov eax, dword ptr [edi + 8]
// 007d1fb8  8928                 mov dword ptr [eax], ebp
// 007d1fba  c7400809000000       mov dword ptr [eax + 8], 9
// 007d1fc1  8b4f1c               mov ecx, dword ptr [edi + 0x1c]
// 007d1fc4  2b4f08               sub ecx, dword ptr [edi + 8]
// 007d1fc7  3bce                 cmp ecx, esi
// 007d1fc9  7f0b                 jg 0x7d1fd6
// 007d1fcb  6a01                 push 1
// 007d1fcd  57                   push edi
// 007d1fce  e85d53fcff           call 0x797330
// 007d1fd3  83c408               add esp, 8
// 007d1fd6  017708               add dword ptr [edi + 8], esi
// 007d1fd9  5f                   pop edi
// 007d1fda  5e                   pop esi
// 007d1fdb  5d                   pop ebp
// 007d1fdc  c3                   ret 
// library lua-5.1/lparser.c (function _open_func)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1 lparser.c
