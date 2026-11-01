// from server: 100% by auto
// roc 2009-12 00876090  unit: CXTPRibbonTheme  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00876090
//
// 00876090  83ec20               sub esp, 0x20
// 00876093  53                   push ebx
// 00876094  55                   push ebp
// 00876095  33ed                 xor ebp, ebp
// 00876097  56                   push esi
// 00876098  57                   push edi
// 00876099  396c244c             cmp dword ptr [esp + 0x4c], ebp
// 0087609d  0f848b000000         je 0x87612e
// 008760a3  68d817a000           push 0xa017d8
// 008760a8  e8538c0000           call 0x87ed00
// 008760ad  8bf0                 mov esi, eax
// 008760af  3bf5                 cmp esi, ebp
// 008760b1  747b                 je 0x87612e
// 008760b3  33c0                 xor eax, eax
// 008760b5  396c245c             cmp dword ptr [esp + 0x5c], ebp
// 008760b9  7505                 jne 0x8760c0
// 008760bb  8d4503               lea eax, [ebp + 3]
// 008760be  eb10                 jmp 0x8760d0
// 008760c0  396c2450             cmp dword ptr [esp + 0x50], ebp
// 008760c4  740a                 je 0x8760d0
// 008760c6  33c0                 xor eax, eax
// 008760c8  396c2454             cmp dword ptr [esp + 0x54], ebp
// 008760cc  0f95c0               setne al
// 008760cf  40                   inc eax
// 008760d0  396c2458             cmp dword ptr [esp + 0x58], ebp
// 008760d4  7403                 je 0x8760d9
// 008760d6  83c004               add eax, 4
// 008760d9  6a08                 push 8
// 008760db  50                   push eax
// 008760dc  8d442428             lea eax, [esp + 0x28]
// 008760e0  50                   push eax
// 008760e1  8bce                 mov ecx, esi
// 008760e3  33ff                 xor edi, edi
// 008760e5  33db                 xor ebx, ebx
// 008760e7  896c2428             mov dword ptr [esp + 0x28], ebp
// 008760eb  e8d0a70600           call 0x8e08c0
// 008760f0  83ec10               sub esp, 0x10
// 008760f3  8bcc                 mov ecx, esp
// 008760f5  8939                 mov dword ptr [ecx], edi
// 008760f7  895904               mov dword ptr [ecx + 4], ebx
// 008760fa  896908               mov dword ptr [ecx + 8], ebp
// 008760fd  83ec10               sub esp, 0x10
// 00876100  8bd5                 mov edx, ebp
// 00876102  89510c               mov dword ptr [ecx + 0xc], edx
// 00876105  8b10                 mov edx, dword ptr [eax]
// 00876107  8bcc                 mov ecx, esp
// 00876109  8911                 mov dword ptr [ecx], edx
// 0087610b  8b5004               mov edx, dword ptr [eax + 4]
// 0087610e  895104               mov dword ptr [ecx + 4], edx
// 00876111  8b5008               mov edx, dword ptr [eax + 8]
// 00876114  8b400c               mov eax, dword ptr [eax + 0xc]
// 00876117  895108               mov dword ptr [ecx + 8], edx
// 0087611a  8b542458             mov edx, dword ptr [esp + 0x58]
// 0087611e  89410c               mov dword ptr [ecx + 0xc], eax
// 00876121  8d4c245c             lea ecx, [esp + 0x5c]
// 00876125  51                   push ecx
// 00876126  52                   push edx
// 00876127  8bce                 mov ecx, esi
// 00876129  e862a00600           call 0x8e0190
// 0087612e  8b442434             mov eax, dword ptr [esp + 0x34]
// 00876132  5f                   pop edi
// 00876133  5e                   pop esi
// 00876134  5d                   pop ebp
// 00876135  c7000d000000         mov dword ptr [eax], 0xd
// 0087613b  c740040d000000       mov dword ptr [eax + 4], 0xd
// 00876142  5b                   pop ebx
// 00876143  83c420               add esp, 0x20
// 00876146  c22c00               ret 0x2c
// library xtp-15.2.1/Source\Ribbon\XTPRibbonTheme.cpp (function ?DrawControlRadioButtonMark@CXTPRibbonTheme@@MAE?AVCSize@@PAVCDC@@VCRect@@HHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonTheme.cpp
