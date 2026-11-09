// from server: 100% by auto
// roc 2010-06 00830ef0  unit: CXTPRibbonTheme  size: 202 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00830ef0
//
// 00830ef0  83ec20               sub esp, 0x20
// 00830ef3  53                   push ebx
// 00830ef4  55                   push ebp
// 00830ef5  33ed                 xor ebp, ebp
// 00830ef7  56                   push esi
// 00830ef8  57                   push edi
// 00830ef9  396c244c             cmp dword ptr [esp + 0x4c], ebp
// 00830efd  0f849c000000         je 0x830f9f
// 00830f03  680061a600           push 0xa66100
// 00830f08  e8f3120000           call 0x832200
// 00830f0d  8bf0                 mov esi, eax
// 00830f0f  3bf5                 cmp esi, ebp
// 00830f11  0f8488000000         je 0x830f9f
// 00830f17  33c0                 xor eax, eax
// 00830f19  396c245c             cmp dword ptr [esp + 0x5c], ebp
// 00830f1d  7505                 jne 0x830f24
// 00830f1f  8d4503               lea eax, [ebp + 3]
// 00830f22  eb10                 jmp 0x830f34
// 00830f24  396c2450             cmp dword ptr [esp + 0x50], ebp
// 00830f28  740a                 je 0x830f34
// 00830f2a  33c0                 xor eax, eax
// 00830f2c  396c2454             cmp dword ptr [esp + 0x54], ebp
// 00830f30  0f95c0               setne al
// 00830f33  40                   inc eax
// 00830f34  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 00830f38  83f901               cmp ecx, 1
// 00830f3b  7505                 jne 0x830f42
// 00830f3d  83c004               add eax, 4
// 00830f40  eb08                 jmp 0x830f4a
// 00830f42  83f902               cmp ecx, 2
// 00830f45  7503                 jne 0x830f4a
// 00830f47  83c008               add eax, 8
// 00830f4a  6a0c                 push 0xc
// 00830f4c  50                   push eax
// 00830f4d  8d442428             lea eax, [esp + 0x28]
// 00830f51  50                   push eax
// 00830f52  8bce                 mov ecx, esi
// 00830f54  33ff                 xor edi, edi
// 00830f56  33db                 xor ebx, ebx
// 00830f58  896c2428             mov dword ptr [esp + 0x28], ebp
// 00830f5c  e8cf3b0600           call 0x894b30
// 00830f61  83ec10               sub esp, 0x10
// 00830f64  8bcc                 mov ecx, esp
// 00830f66  8939                 mov dword ptr [ecx], edi
// 00830f68  895904               mov dword ptr [ecx + 4], ebx
// 00830f6b  896908               mov dword ptr [ecx + 8], ebp
// 00830f6e  83ec10               sub esp, 0x10
// 00830f71  8bd5                 mov edx, ebp
// 00830f73  89510c               mov dword ptr [ecx + 0xc], edx
// 00830f76  8b10                 mov edx, dword ptr [eax]
// 00830f78  8bcc                 mov ecx, esp
// 00830f7a  8911                 mov dword ptr [ecx], edx
// 00830f7c  8b5004               mov edx, dword ptr [eax + 4]
// 00830f7f  895104               mov dword ptr [ecx + 4], edx
// 00830f82  8b5008               mov edx, dword ptr [eax + 8]
// 00830f85  8b400c               mov eax, dword ptr [eax + 0xc]
// 00830f88  895108               mov dword ptr [ecx + 8], edx
// 00830f8b  8b542458             mov edx, dword ptr [esp + 0x58]
// 00830f8f  89410c               mov dword ptr [ecx + 0xc], eax
// 00830f92  8d4c245c             lea ecx, [esp + 0x5c]
// 00830f96  51                   push ecx
// 00830f97  52                   push edx
// 00830f98  8bce                 mov ecx, esi
// 00830f9a  e861340600           call 0x894400
// 00830f9f  8b442434             mov eax, dword ptr [esp + 0x34]
// 00830fa3  5f                   pop edi
// 00830fa4  5e                   pop esi
// 00830fa5  5d                   pop ebp
// 00830fa6  c7000d000000         mov dword ptr [eax], 0xd
// 00830fac  c740040d000000       mov dword ptr [eax + 4], 0xd
// 00830fb3  5b                   pop ebx
// 00830fb4  83c420               add esp, 0x20
// 00830fb7  c22c00               ret 0x2c
// library xtp-13.2.1/Source\Ribbon\XTPRibbonTheme.cpp (function ?DrawControlCheckBoxMark@CXTPRibbonTheme@@MAE?AVCSize@@PAVCDC@@VCRect@@HHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonTheme.cpp
