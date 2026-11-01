// from server: 100% by auto
// roc 2009-12 00875fc0  unit: CXTPRibbonTheme  size: 202 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00875fc0
//
// 00875fc0  83ec20               sub esp, 0x20
// 00875fc3  53                   push ebx
// 00875fc4  55                   push ebp
// 00875fc5  33ed                 xor ebp, ebp
// 00875fc7  56                   push esi
// 00875fc8  57                   push edi
// 00875fc9  396c244c             cmp dword ptr [esp + 0x4c], ebp
// 00875fcd  0f849c000000         je 0x87606f
// 00875fd3  68c017a000           push 0xa017c0
// 00875fd8  e8238d0000           call 0x87ed00
// 00875fdd  8bf0                 mov esi, eax
// 00875fdf  3bf5                 cmp esi, ebp
// 00875fe1  0f8488000000         je 0x87606f
// 00875fe7  33c0                 xor eax, eax
// 00875fe9  396c245c             cmp dword ptr [esp + 0x5c], ebp
// 00875fed  7505                 jne 0x875ff4
// 00875fef  8d4503               lea eax, [ebp + 3]
// 00875ff2  eb10                 jmp 0x876004
// 00875ff4  396c2450             cmp dword ptr [esp + 0x50], ebp
// 00875ff8  740a                 je 0x876004
// 00875ffa  33c0                 xor eax, eax
// 00875ffc  396c2454             cmp dword ptr [esp + 0x54], ebp
// 00876000  0f95c0               setne al
// 00876003  40                   inc eax
// 00876004  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 00876008  83f901               cmp ecx, 1
// 0087600b  7505                 jne 0x876012
// 0087600d  83c004               add eax, 4
// 00876010  eb08                 jmp 0x87601a
// 00876012  83f902               cmp ecx, 2
// 00876015  7503                 jne 0x87601a
// 00876017  83c008               add eax, 8
// 0087601a  6a0c                 push 0xc
// 0087601c  50                   push eax
// 0087601d  8d442428             lea eax, [esp + 0x28]
// 00876021  50                   push eax
// 00876022  8bce                 mov ecx, esi
// 00876024  33ff                 xor edi, edi
// 00876026  33db                 xor ebx, ebx
// 00876028  896c2428             mov dword ptr [esp + 0x28], ebp
// 0087602c  e88fa80600           call 0x8e08c0
// 00876031  83ec10               sub esp, 0x10
// 00876034  8bcc                 mov ecx, esp
// 00876036  8939                 mov dword ptr [ecx], edi
// 00876038  895904               mov dword ptr [ecx + 4], ebx
// 0087603b  896908               mov dword ptr [ecx + 8], ebp
// 0087603e  83ec10               sub esp, 0x10
// 00876041  8bd5                 mov edx, ebp
// 00876043  89510c               mov dword ptr [ecx + 0xc], edx
// 00876046  8b10                 mov edx, dword ptr [eax]
// 00876048  8bcc                 mov ecx, esp
// 0087604a  8911                 mov dword ptr [ecx], edx
// 0087604c  8b5004               mov edx, dword ptr [eax + 4]
// 0087604f  895104               mov dword ptr [ecx + 4], edx
// 00876052  8b5008               mov edx, dword ptr [eax + 8]
// 00876055  8b400c               mov eax, dword ptr [eax + 0xc]
// 00876058  895108               mov dword ptr [ecx + 8], edx
// 0087605b  8b542458             mov edx, dword ptr [esp + 0x58]
// 0087605f  89410c               mov dword ptr [ecx + 0xc], eax
// 00876062  8d4c245c             lea ecx, [esp + 0x5c]
// 00876066  51                   push ecx
// 00876067  52                   push edx
// 00876068  8bce                 mov ecx, esi
// 0087606a  e821a10600           call 0x8e0190
// 0087606f  8b442434             mov eax, dword ptr [esp + 0x34]
// 00876073  5f                   pop edi
// 00876074  5e                   pop esi
// 00876075  5d                   pop ebp
// 00876076  c7000d000000         mov dword ptr [eax], 0xd
// 0087607c  c740040d000000       mov dword ptr [eax + 4], 0xd
// 00876083  5b                   pop ebx
// 00876084  83c420               add esp, 0x20
// 00876087  c22c00               ret 0x2c
// library xtp-15.2.1/Source\Ribbon\XTPRibbonTheme.cpp (function ?DrawControlCheckBoxMark@CXTPRibbonTheme@@MAE?AVCSize@@PAVCDC@@VCRect@@HHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonTheme.cpp
