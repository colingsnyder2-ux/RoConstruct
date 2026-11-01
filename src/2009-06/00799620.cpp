// from server: 100% by auto
// roc 2009-06 00799620  unit: CXTPRibbonTheme  size: 202 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00799620
//
// 00799620  83ec20               sub esp, 0x20
// 00799623  53                   push ebx
// 00799624  55                   push ebp
// 00799625  33ed                 xor ebp, ebp
// 00799627  56                   push esi
// 00799628  57                   push edi
// 00799629  396c244c             cmp dword ptr [esp + 0x4c], ebp
// 0079962d  0f849c000000         je 0x7996cf
// 00799633  68e00b9000           push 0x900be0
// 00799638  e883a70000           call 0x7a3dc0
// 0079963d  8bf0                 mov esi, eax
// 0079963f  3bf5                 cmp esi, ebp
// 00799641  0f8488000000         je 0x7996cf
// 00799647  33c0                 xor eax, eax
// 00799649  396c245c             cmp dword ptr [esp + 0x5c], ebp
// 0079964d  7505                 jne 0x799654
// 0079964f  8d4503               lea eax, [ebp + 3]
// 00799652  eb10                 jmp 0x799664
// 00799654  396c2450             cmp dword ptr [esp + 0x50], ebp
// 00799658  740a                 je 0x799664
// 0079965a  33c0                 xor eax, eax
// 0079965c  396c2454             cmp dword ptr [esp + 0x54], ebp
// 00799660  0f95c0               setne al
// 00799663  40                   inc eax
// 00799664  8b4c2458             mov ecx, dword ptr [esp + 0x58]
// 00799668  83f901               cmp ecx, 1
// 0079966b  7505                 jne 0x799672
// 0079966d  83c004               add eax, 4
// 00799670  eb08                 jmp 0x79967a
// 00799672  83f902               cmp ecx, 2
// 00799675  7503                 jne 0x79967a
// 00799677  83c008               add eax, 8
// 0079967a  6a0c                 push 0xc
// 0079967c  50                   push eax
// 0079967d  8d442428             lea eax, [esp + 0x28]
// 00799681  50                   push eax
// 00799682  8bce                 mov ecx, esi
// 00799684  33ff                 xor edi, edi
// 00799686  33db                 xor ebx, ebx
// 00799688  896c2428             mov dword ptr [esp + 0x28], ebp
// 0079968c  e82fc70600           call 0x805dc0
// 00799691  83ec10               sub esp, 0x10
// 00799694  8bcc                 mov ecx, esp
// 00799696  8939                 mov dword ptr [ecx], edi
// 00799698  895904               mov dword ptr [ecx + 4], ebx
// 0079969b  896908               mov dword ptr [ecx + 8], ebp
// 0079969e  83ec10               sub esp, 0x10
// 007996a1  8bd5                 mov edx, ebp
// 007996a3  89510c               mov dword ptr [ecx + 0xc], edx
// 007996a6  8b10                 mov edx, dword ptr [eax]
// 007996a8  8bcc                 mov ecx, esp
// 007996aa  8911                 mov dword ptr [ecx], edx
// 007996ac  8b5004               mov edx, dword ptr [eax + 4]
// 007996af  895104               mov dword ptr [ecx + 4], edx
// 007996b2  8b5008               mov edx, dword ptr [eax + 8]
// 007996b5  8b400c               mov eax, dword ptr [eax + 0xc]
// 007996b8  895108               mov dword ptr [ecx + 8], edx
// 007996bb  8b542458             mov edx, dword ptr [esp + 0x58]
// 007996bf  89410c               mov dword ptr [ecx + 0xc], eax
// 007996c2  8d4c245c             lea ecx, [esp + 0x5c]
// 007996c6  51                   push ecx
// 007996c7  52                   push edx
// 007996c8  8bce                 mov ecx, esi
// 007996ca  e8c1bf0600           call 0x805690
// 007996cf  8b442434             mov eax, dword ptr [esp + 0x34]
// 007996d3  5f                   pop edi
// 007996d4  5e                   pop esi
// 007996d5  5d                   pop ebp
// 007996d6  c7000d000000         mov dword ptr [eax], 0xd
// 007996dc  c740040d000000       mov dword ptr [eax + 4], 0xd
// 007996e3  5b                   pop ebx
// 007996e4  83c420               add esp, 0x20
// 007996e7  c22c00               ret 0x2c
// library xtp-15.2.1/Source\Ribbon\XTPRibbonTheme.cpp (function ?DrawControlCheckBoxMark@CXTPRibbonTheme@@MAE?AVCSize@@PAVCDC@@VCRect@@HHHHH@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/Ribbon/XTPRibbonTheme.cpp
