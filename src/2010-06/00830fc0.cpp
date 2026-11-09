// from server: 100% by auto
// roc 2010-06 00830fc0  unit: CXTPRibbonTheme  size: 185 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00830fc0
//
// 00830fc0  83ec20               sub esp, 0x20
// 00830fc3  53                   push ebx
// 00830fc4  55                   push ebp
// 00830fc5  33ed                 xor ebp, ebp
// 00830fc7  56                   push esi
// 00830fc8  57                   push edi
// 00830fc9  396c244c             cmp dword ptr [esp + 0x4c], ebp
// 00830fcd  0f848b000000         je 0x83105e
// 00830fd3  681861a600           push 0xa66118
// 00830fd8  e823120000           call 0x832200
// 00830fdd  8bf0                 mov esi, eax
// 00830fdf  3bf5                 cmp esi, ebp
// 00830fe1  747b                 je 0x83105e
// 00830fe3  33c0                 xor eax, eax
// 00830fe5  396c245c             cmp dword ptr [esp + 0x5c], ebp
// 00830fe9  7505                 jne 0x830ff0
// 00830feb  8d4503               lea eax, [ebp + 3]
// 00830fee  eb10                 jmp 0x831000
// 00830ff0  396c2450             cmp dword ptr [esp + 0x50], ebp
// 00830ff4  740a                 je 0x831000
// 00830ff6  33c0                 xor eax, eax
// 00830ff8  396c2454             cmp dword ptr [esp + 0x54], ebp
// 00830ffc  0f95c0               setne al
// 00830fff  40                   inc eax
// 00831000  396c2458             cmp dword ptr [esp + 0x58], ebp
// 00831004  7403                 je 0x831009
// 00831006  83c004               add eax, 4
// 00831009  6a08                 push 8
// 0083100b  50                   push eax
// 0083100c  8d442428             lea eax, [esp + 0x28]
// 00831010  50                   push eax
// 00831011  8bce                 mov ecx, esi
// 00831013  33ff                 xor edi, edi
// 00831015  33db                 xor ebx, ebx
// 00831017  896c2428             mov dword ptr [esp + 0x28], ebp
// 0083101b  e8103b0600           call 0x894b30
// 00831020  83ec10               sub esp, 0x10
// 00831023  8bcc                 mov ecx, esp
// 00831025  8939                 mov dword ptr [ecx], edi
// 00831027  895904               mov dword ptr [ecx + 4], ebx
// 0083102a  896908               mov dword ptr [ecx + 8], ebp
// 0083102d  83ec10               sub esp, 0x10
// 00831030  8bd5                 mov edx, ebp
// 00831032  89510c               mov dword ptr [ecx + 0xc], edx
// 00831035  8b10                 mov edx, dword ptr [eax]
// 00831037  8bcc                 mov ecx, esp
// 00831039  8911                 mov dword ptr [ecx], edx
// 0083103b  8b5004               mov edx, dword ptr [eax + 4]
// 0083103e  895104               mov dword ptr [ecx + 4], edx
// 00831041  8b5008               mov edx, dword ptr [eax + 8]
// 00831044  8b400c               mov eax, dword ptr [eax + 0xc]
// 00831047  895108               mov dword ptr [ecx + 8], edx
// 0083104a  8b542458             mov edx, dword ptr [esp + 0x58]
// 0083104e  89410c               mov dword ptr [ecx + 0xc], eax
// 00831051  8d4c245c             lea ecx, [esp + 0x5c]
// 00831055  51                   push ecx
// 00831056  52                   push edx
// 00831057  8bce                 mov ecx, esi
// 00831059  e8a2330600           call 0x894400
// 0083105e  8b442434             mov eax, dword ptr [esp + 0x34]
// 00831062  5f                   pop edi
// 00831063  5e                   pop esi
// 00831064  5d                   pop ebp
// 00831065  c7000d000000         mov dword ptr [eax], 0xd
// 0083106b  c740040d000000       mov dword ptr [eax + 4], 0xd
// 00831072  5b                   pop ebx
// 00831073  83c420               add esp, 0x20
// 00831076  c22c00               ret 0x2c
// library xtp-13.2.1/Source\Ribbon\XTPRibbonTheme.cpp (function ?DrawControlRadioButtonMark@CXTPRibbonTheme@@MAE?AVCSize@@PAVCDC@@VCRect@@HHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonTheme.cpp
