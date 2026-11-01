// from server: 90% by EspClaude
// from server: 100% by EspClaude
// roc 2008-06 0046c920  unit: VCWorkspace::?$CComObject  size: 416 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046c920
//
// 0046c920  55                   push ebp
// 0046c921  8bec                 mov ebp, esp
// 0046c923  6aff                 push -1
// 0046c925  68133c7c00           push 0x7c3c13
// 0046c92a  64a100000000         mov eax, dword ptr fs:[0]
// 0046c930  50                   push eax
// 0046c931  64892500000000       mov dword ptr fs:[0], esp
// 0046c938  83ec1c               sub esp, 0x1c
// 0046c93b  53                   push ebx
// 0046c93c  56                   push esi
// 0046c93d  57                   push edi
// 0046c93e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0046c941  e822402300           call 0x6a0968
// 0046c946  50                   push eax
// 0046c947  8d4dd8               lea ecx, [ebp - 0x28]
// 0046c94a  e813402300           call 0x6a0962
// 0046c94f  8b750c               mov esi, dword ptr [ebp + 0xc]
// 0046c952  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0046c959  56                   push esi
// 0046c95a  c645fc01             mov byte ptr [ebp - 4], 1
// 0046c95e  e86d13fbff           call 0x41dcd0
// 0046c963  8bf8                 mov edi, eax
// 0046c965  83c404               add esp, 4
// 0046c968  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c96b  85ff                 test edi, edi
// 0046c96d  0f8497000000         je 0x46ca0a
// 0046c973  ff15043f8000         call dword ptr [0x803f04]
// 0046c979  b302                 mov bl, 2
// 0046c97b  56                   push esi
// 0046c97c  8d4d08               lea ecx, [ebp + 8]
// 0046c97f  885dfc               mov byte ptr [ebp - 4], bl
// 0046c982  ff15d83e8000         call dword ptr [0x803ed8]
// 0046c988  8b00                 mov eax, dword ptr [eax]
// 0046c98a  50                   push eax
// 0046c98b  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c98e  6880ea8000           push 0x80ea80
// 0046c993  51                   push ecx
// 0046c994  c645fc03             mov byte ptr [ebp - 4], 3
// 0046c998  ff15dc3e8000         call dword ptr [0x803edc]
// 0046c99e  83c40c               add esp, 0xc
// 0046c9a1  8d4d08               lea ecx, [ebp + 8]
// 0046c9a4  885dfc               mov byte ptr [ebp - 4], bl
// 0046c9a7  ff15143f8000         call dword ptr [0x803f14]
// 0046c9ad  57                   push edi
// 0046c9ae  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c9b1  ff15e03e8000         call dword ptr [0x803ee0]
// 0046c9b7  50                   push eax
// 0046c9b8  68f8648100           push 0x8164f8
// 0046c9bd  e86ec9fbff           call 0x429330
// 0046c9c2  83c40c               add esp, 0xc
// 0046c9c5  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c9c8  8bf0                 mov esi, eax
// 0046c9ca  ff15143f8000         call dword ptr [0x803f14]
// 0046c9d0  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0046c9d3  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0046c9da  85c0                 test eax, eax
// 0046c9dc  7406                 je 0x46c9e4
// 0046c9de  8b55d8               mov edx, dword ptr [ebp - 0x28]
// 0046c9e1  895004               mov dword ptr [eax + 4], edx
// 0046c9e4  837de400             cmp dword ptr [ebp - 0x1c], 0
// 0046c9e8  740b                 je 0x46c9f5
// 0046c9ea  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 0046c9ed  50                   push eax
// 0046c9ee  6a00                 push 0
// 0046c9f0  e8673f2300           call 0x6a095c
// 0046c9f5  8bc6                 mov eax, esi
// 0046c9f7  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0046c9fa  64890d00000000       mov dword ptr fs:[0], ecx
// 0046ca01  5f                   pop edi
// 0046ca02  5e                   pop esi
// 0046ca03  5b                   pop ebx
// 0046ca04  8be5                 mov esp, ebp
// 0046ca06  5d                   pop ebp
// 0046ca07  c20800               ret 8
// 0046ca0a  6a00                 push 0
// 0046ca0c  56                   push esi
// 0046ca0d  ff15d83e8000         call dword ptr [0x803ed8]
// 0046ca13  8bc8                 mov ecx, eax
// 0046ca15  c645fc04             mov byte ptr [ebp - 4], 4
// 0046ca19  ff15e03e8000         call dword ptr [0x803ee0]
// 0046ca1f  83ec20               sub esp, 0x20
// 0046ca22  8bcc                 mov ecx, esp
// 0046ca24  8965ec               mov dword ptr [ebp - 0x14], esp
// 0046ca27  50                   push eax
// 0046ca28  e893adfcff           call 0x4377c0
// 0046ca2d  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0046ca30  e85bf2ffff           call 0x46bc90
// 0046ca35  8d4d0c               lea ecx, [ebp + 0xc]
// 0046ca38  ff15143f8000         call dword ptr [0x803f14]
// 0046ca3e  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0046ca41  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0046ca48  85c0                 test eax, eax
// 0046ca4a  7406                 je 0x46ca52
// 0046ca4c  8b4dd8               mov ecx, dword ptr [ebp - 0x28]
// 0046ca4f  894804               mov dword ptr [eax + 4], ecx
// 0046ca52  837de400             cmp dword ptr [ebp - 0x1c], 0
// 0046ca56  740b                 je 0x46ca63
// 0046ca58  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 0046ca5b  52                   push edx
// 0046ca5c  6a00                 push 0
// 0046ca5e  e8f93e2300           call 0x6a095c
// 0046ca63  33c0                 xor eax, eax
// 0046ca65  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0046ca68  64890d00000000       mov dword ptr fs:[0], ecx
// 0046ca6f  5f                   pop edi
// 0046ca70  5e                   pop esi
// 0046ca71  5b                   pop ebx
// 0046ca72  8be5                 mov esp, ebp
// 0046ca74  5d                   pop ebp
// 0046ca75  c20800               ret 8
// 0046ca78  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 0046ca7b  8b01                 mov eax, dword ptr [ecx]
// 0046ca7d  8b5004               mov edx, dword ptr [eax + 4]
// 0046ca80  6a00                 push 0
// 0046ca82  ffd2                 call edx
// 0046ca84  50                   push eax
// 0046ca85  68f8648100           push 0x8164f8
// 0046ca8a  e8a1c8fbff           call 0x429330
// 0046ca8f  89450c               mov dword ptr [ebp + 0xc], eax
// 0046ca92  83c40c               add esp, 0xc
// 0046ca95  b89bca4600           mov eax, 0x46ca9b
// 0046ca9a  c3                   ret 
// 0046ca9b  8d4dd8               lea ecx, [ebp - 0x28]
// 0046ca9e  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0046caa5  e84696f9ff           call 0x4060f0
// 0046caaa  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0046caad  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0046cab0  5f                   pop edi
// 0046cab1  5e                   pop esi
// 0046cab2  64890d00000000       mov dword ptr fs:[0], ecx
// 0046cab9  5b                   pop ebx
// 0046caba  8be5                 mov esp, ebp
// 0046cabc  5d                   pop ebp
// 0046cabd  c20800               ret 8

// from server: 99% by coldek
// roc 2008-06 0046c920  unit: VCWorkspace::?$CComObject  size: 416 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046c920
//
// 0046c920  55                   push ebp
// 0046c921  8bec                 mov ebp, esp
// 0046c923  6aff                 push -1
// 0046c925  68133c7c00           push 0x7c3c13
// 0046c92a  64a100000000         mov eax, dword ptr fs:[0]
// 0046c930  50                   push eax
// 0046c931  64892500000000       mov dword ptr fs:[0], esp
// 0046c938  83ec1c               sub esp, 0x1c
// 0046c93b  53                   push ebx
// 0046c93c  56                   push esi
// 0046c93d  57                   push edi
// 0046c93e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0046c941  e822402300           call 0x6a0968
// 0046c946  50                   push eax
// 0046c947  8d4dd8               lea ecx, [ebp - 0x28]
// 0046c94a  e813402300           call 0x6a0962
// 0046c94f  8b750c               mov esi, dword ptr [ebp + 0xc]
// 0046c952  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0046c959  56                   push esi
// 0046c95a  c645fc01             mov byte ptr [ebp - 4], 1
// 0046c95e  e86d13fbff           call 0x41dcd0
// 0046c963  8bf8                 mov edi, eax
// 0046c965  83c404               add esp, 4
// 0046c968  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c96b  85ff                 test edi, edi
// 0046c96d  0f8497000000         je 0x46ca0a
// 0046c973  ff15043f8000         call dword ptr [0x803f04]
// 0046c979  b302                 mov bl, 2
// 0046c97b  56                   push esi
// 0046c97c  8d4d08               lea ecx, [ebp + 8]
// 0046c97f  885dfc               mov byte ptr [ebp - 4], bl
// 0046c982  ff15d83e8000         call dword ptr [0x803ed8]
// 0046c988  8b00                 mov eax, dword ptr [eax]
// 0046c98a  50                   push eax
// 0046c98b  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c98e  6880ea8000           push 0x80ea80
// 0046c993  51                   push ecx
// 0046c994  c645fc03             mov byte ptr [ebp - 4], 3
// 0046c998  ff15dc3e8000         call dword ptr [0x803edc]
// 0046c99e  83c40c               add esp, 0xc
// 0046c9a1  8d4d08               lea ecx, [ebp + 8]
// 0046c9a4  885dfc               mov byte ptr [ebp - 4], bl
// 0046c9a7  ff15143f8000         call dword ptr [0x803f14]
// 0046c9ad  57                   push edi
// 0046c9ae  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c9b1  ff15e03e8000         call dword ptr [0x803ee0]
// 0046c9b7  50                   push eax
// 0046c9b8  68f8648100           push 0x8164f8
// 0046c9bd  e86ec9fbff           call 0x429330
// 0046c9c2  83c40c               add esp, 0xc
// 0046c9c5  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c9c8  8bf0                 mov esi, eax
// 0046c9ca  ff15143f8000         call dword ptr [0x803f14]
// 0046c9d0  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0046c9d3  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0046c9da  85c0                 test eax, eax
// 0046c9dc  7406                 je 0x46c9e4
// 0046c9de  8b55d8               mov edx, dword ptr [ebp - 0x28]
// 0046c9e1  895004               mov dword ptr [eax + 4], edx
// 0046c9e4  837de400             cmp dword ptr [ebp - 0x1c], 0
// 0046c9e8  740b                 je 0x46c9f5
// 0046c9ea  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 0046c9ed  50                   push eax
// 0046c9ee  6a00                 push 0
// 0046c9f0  e8673f2300           call 0x6a095c
// 0046c9f5  8bc6                 mov eax, esi
// 0046c9f7  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0046c9fa  64890d00000000       mov dword ptr fs:[0], ecx
// 0046ca01  5f                   pop edi
// 0046ca02  5e                   pop esi
// 0046ca03  5b                   pop ebx
// 0046ca04  8be5                 mov esp, ebp
// 0046ca06  5d                   pop ebp
// 0046ca07  c20800               ret 8
// 0046ca0a  6a00                 push 0
// 0046ca0c  56                   push esi
// 0046ca0d  ff15d83e8000         call dword ptr [0x803ed8]
// 0046ca13  8bc8                 mov ecx, eax
// 0046ca15  c645fc04             mov byte ptr [ebp - 4], 4
// 0046ca19  ff15e03e8000         call dword ptr [0x803ee0]
// 0046ca1f  83ec20               sub esp, 0x20
// 0046ca22  8bcc                 mov ecx, esp
// 0046ca24  8965ec               mov dword ptr [ebp - 0x14], esp
// 0046ca27  50                   push eax
// 0046ca28  e893adfcff           call 0x4377c0
// 0046ca2d  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0046ca30  e85bf2ffff           call 0x46bc90
// 0046ca35  8d4d0c               lea ecx, [ebp + 0xc]
// 0046ca38  ff15143f8000         call dword ptr [0x803f14]
// 0046ca3e  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0046ca41  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0046ca48  85c0                 test eax, eax
// 0046ca4a  7406                 je 0x46ca52
// 0046ca4c  8b4dd8               mov ecx, dword ptr [ebp - 0x28]
// 0046ca4f  894804               mov dword ptr [eax + 4], ecx
// 0046ca52  837de400             cmp dword ptr [ebp - 0x1c], 0
// 0046ca56  740b                 je 0x46ca63
// 0046ca58  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 0046ca5b  52                   push edx
// 0046ca5c  6a00                 push 0
// 0046ca5e  e8f93e2300           call 0x6a095c
// 0046ca63  33c0                 xor eax, eax
// 0046ca65  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0046ca68  64890d00000000       mov dword ptr fs:[0], ecx
// 0046ca6f  5f                   pop edi
// 0046ca70  5e                   pop esi
// 0046ca71  5b                   pop ebx
// 0046ca72  8be5                 mov esp, ebp
// 0046ca74  5d                   pop ebp
// 0046ca75  c20800               ret 8
// 0046ca78  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 0046ca7b  8b01                 mov eax, dword ptr [ecx]
// 0046ca7d  8b5004               mov edx, dword ptr [eax + 4]
// 0046ca80  6a00                 push 0
// 0046ca82  ffd2                 call edx
// 0046ca84  50                   push eax
// 0046ca85  68f8648100           push 0x8164f8
// 0046ca8a  e8a1c8fbff           call 0x429330
// 0046ca8f  89450c               mov dword ptr [ebp + 0xc], eax
// 0046ca92  83c40c               add esp, 0xc
// 0046ca95  b89bca4600           mov eax, 0x46ca9b
// 0046ca9a  c3                   ret 
// 0046ca9b  8d4dd8               lea ecx, [ebp - 0x28]
// 0046ca9e  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0046caa5  e84696f9ff           call 0x4060f0
// 0046caaa  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0046caad  8b450c               mov eax, dword ptr [ebp + 0xc]
// 0046cab0  5f                   pop edi
// 0046cab1  5e                   pop esi
// 0046cab2  64890d00000000       mov dword ptr fs:[0], ecx
// 0046cab9  5b                   pop ebx
// 0046caba  8be5                 mov esp, ebp
// 0046cabc  5d                   pop ebp
// 0046cabd  c20800               ret 8

// from server: 89% by nuck16
// roc 2008-06 0046c920  unit: VCWorkspace::?$CComObject  size: 344 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046c920
//
// 0046c920  55                   push ebp
// 0046c921  8bec                 mov ebp, esp
// 0046c923  6aff                 push -1
// 0046c925  68133c7c00           push 0x7c3c13
// 0046c92a  64a100000000         mov eax, dword ptr fs:[0]
// 0046c930  50                   push eax
// 0046c931  64892500000000       mov dword ptr fs:[0], esp
// 0046c938  83ec1c               sub esp, 0x1c
// 0046c93b  53                   push ebx
// 0046c93c  56                   push esi
// 0046c93d  57                   push edi
// 0046c93e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0046c941  e822402300           call 0x6a0968
// 0046c946  50                   push eax
// 0046c947  8d4dd8               lea ecx, [ebp - 0x28]
// 0046c94a  e813402300           call 0x6a0962
// 0046c94f  8b750c               mov esi, dword ptr [ebp + 0xc]
// 0046c952  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0046c959  56                   push esi
// 0046c95a  c645fc01             mov byte ptr [ebp - 4], 1
// 0046c95e  e86d13fbff           call 0x41dcd0
// 0046c963  8bf8                 mov edi, eax
// 0046c965  83c404               add esp, 4
// 0046c968  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c96b  85ff                 test edi, edi
// 0046c96d  0f8497000000         je 0x46ca0a
// 0046c973  ff15043f8000         call dword ptr [0x803f04]
// 0046c979  b302                 mov bl, 2
// 0046c97b  56                   push esi
// 0046c97c  8d4d08               lea ecx, [ebp + 8]
// 0046c97f  885dfc               mov byte ptr [ebp - 4], bl
// 0046c982  ff15d83e8000         call dword ptr [0x803ed8]
// 0046c988  8b00                 mov eax, dword ptr [eax]
// 0046c98a  50                   push eax
// 0046c98b  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c98e  6880ea8000           push 0x80ea80
// 0046c993  51                   push ecx
// 0046c994  c645fc03             mov byte ptr [ebp - 4], 3
// 0046c998  ff15dc3e8000         call dword ptr [0x803edc]
// 0046c99e  83c40c               add esp, 0xc
// 0046c9a1  8d4d08               lea ecx, [ebp + 8]
// 0046c9a4  885dfc               mov byte ptr [ebp - 4], bl
// 0046c9a7  ff15143f8000         call dword ptr [0x803f14]
// 0046c9ad  57                   push edi
// 0046c9ae  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c9b1  ff15e03e8000         call dword ptr [0x803ee0]
// 0046c9b7  50                   push eax
// 0046c9b8  68f8648100           push 0x8164f8
// 0046c9bd  e86ec9fbff           call 0x429330
// 0046c9c2  83c40c               add esp, 0xc
// 0046c9c5  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c9c8  8bf0                 mov esi, eax
// 0046c9ca  ff15143f8000         call dword ptr [0x803f14]
// 0046c9d0  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0046c9d3  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0046c9da  85c0                 test eax, eax
// 0046c9dc  7406                 je 0x46c9e4
// 0046c9de  8b55d8               mov edx, dword ptr [ebp - 0x28]
// 0046c9e1  895004               mov dword ptr [eax + 4], edx
// 0046c9e4  837de400             cmp dword ptr [ebp - 0x1c], 0
// 0046c9e8  740b                 je 0x46c9f5
// 0046c9ea  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 0046c9ed  50                   push eax
// 0046c9ee  6a00                 push 0
// 0046c9f0  e8673f2300           call 0x6a095c
// 0046c9f5  8bc6                 mov eax, esi
// 0046c9f7  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0046c9fa  64890d00000000       mov dword ptr fs:[0], ecx
// 0046ca01  5f                   pop edi
// 0046ca02  5e                   pop esi
// 0046ca03  5b                   pop ebx
// 0046ca04  8be5                 mov esp, ebp
// 0046ca06  5d                   pop ebp
// 0046ca07  c20800               ret 8
// 0046ca0a  6a00                 push 0
// 0046ca0c  56                   push esi
// 0046ca0d  ff15d83e8000         call dword ptr [0x803ed8]
// 0046ca13  8bc8                 mov ecx, eax
// 0046ca15  c645fc04             mov byte ptr [ebp - 4], 4
// 0046ca19  ff15e03e8000         call dword ptr [0x803ee0]
// 0046ca1f  83ec20               sub esp, 0x20
// 0046ca22  8bcc                 mov ecx, esp
// 0046ca24  8965ec               mov dword ptr [ebp - 0x14], esp
// 0046ca27  50                   push eax
// 0046ca28  e893adfcff           call 0x4377c0
// 0046ca2d  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0046ca30  e85bf2ffff           call 0x46bc90
// 0046ca35  8d4d0c               lea ecx, [ebp + 0xc]
// 0046ca38  ff15143f8000         call dword ptr [0x803f14]
// 0046ca3e  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0046ca41  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0046ca48  85c0                 test eax, eax
// 0046ca4a  7406                 je 0x46ca52
// 0046ca4c  8b4dd8               mov ecx, dword ptr [ebp - 0x28]
// 0046ca4f  894804               mov dword ptr [eax + 4], ecx
// 0046ca52  837de400             cmp dword ptr [ebp - 0x1c], 0
// 0046ca56  740b                 je 0x46ca63
// 0046ca58  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 0046ca5b  52                   push edx
// 0046ca5c  6a00                 push 0
// 0046ca5e  e8f93e2300           call 0x6a095c
// 0046ca63  33c0                 xor eax, eax
// 0046ca65  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0046ca68  64890d00000000       mov dword ptr fs:[0], ecx
// 0046ca6f  5f                   pop edi
// 0046ca70  5e                   pop esi
// 0046ca71  5b                   pop ebx
// 0046ca72  8be5                 mov esp, ebp
// 0046ca74  5d                   pop ebp
// 0046ca75  c20800               ret 8

// from server: 85% by Espeon
// from server: 82% by colin
// roc 2008-06 0046c920  unit: VCWorkspace::?$CComObject  size: 344 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046c920
//
// 0046c920  55                   push ebp
// 0046c921  8bec                 mov ebp, esp
// 0046c923  6aff                 push -1
// 0046c925  68133c7c00           push 0x7c3c13
// 0046c92a  64a100000000         mov eax, dword ptr fs:[0]
// 0046c930  50                   push eax
// 0046c931  64892500000000       mov dword ptr fs:[0], esp
// 0046c938  83ec1c               sub esp, 0x1c
// 0046c93b  53                   push ebx
// 0046c93c  56                   push esi
// 0046c93d  57                   push edi
// 0046c93e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0046c941  e822402300           call 0x6a0968
// 0046c946  50                   push eax
// 0046c947  8d4dd8               lea ecx, [ebp - 0x28]
// 0046c94a  e813402300           call 0x6a0962
// 0046c94f  8b750c               mov esi, dword ptr [ebp + 0xc]
// 0046c952  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0046c959  56                   push esi
// 0046c95a  c645fc01             mov byte ptr [ebp - 4], 1
// 0046c95e  e86d13fbff           call 0x41dcd0
// 0046c963  8bf8                 mov edi, eax
// 0046c965  83c404               add esp, 4
// 0046c968  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c96b  85ff                 test edi, edi
// 0046c96d  0f8497000000         je 0x46ca0a
// 0046c973  ff15043f8000         call dword ptr [0x803f04]
// 0046c979  b302                 mov bl, 2
// 0046c97b  56                   push esi
// 0046c97c  8d4d08               lea ecx, [ebp + 8]
// 0046c97f  885dfc               mov byte ptr [ebp - 4], bl
// 0046c982  ff15d83e8000         call dword ptr [0x803ed8]
// 0046c988  8b00                 mov eax, dword ptr [eax]
// 0046c98a  50                   push eax
// 0046c98b  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c98e  6880ea8000           push 0x80ea80
// 0046c993  51                   push ecx
// 0046c994  c645fc03             mov byte ptr [ebp - 4], 3
// 0046c998  ff15dc3e8000         call dword ptr [0x803edc]
// 0046c99e  83c40c               add esp, 0xc
// 0046c9a1  8d4d08               lea ecx, [ebp + 8]
// 0046c9a4  885dfc               mov byte ptr [ebp - 4], bl
// 0046c9a7  ff15143f8000         call dword ptr [0x803f14]
// 0046c9ad  57                   push edi
// 0046c9ae  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c9b1  ff15e03e8000         call dword ptr [0x803ee0]
// 0046c9b7  50                   push eax
// 0046c9b8  68f8648100           push 0x8164f8
// 0046c9bd  e86ec9fbff           call 0x429330
// 0046c9c2  83c40c               add esp, 0xc
// 0046c9c5  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c9c8  8bf0                 mov esi, eax
// 0046c9ca  ff15143f8000         call dword ptr [0x803f14]
// 0046c9d0  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0046c9d3  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0046c9da  85c0                 test eax, eax
// 0046c9dc  7406                 je 0x46c9e4
// 0046c9de  8b55d8               mov edx, dword ptr [ebp - 0x28]
// 0046c9e1  895004               mov dword ptr [eax + 4], edx
// 0046c9e4  837de400             cmp dword ptr [ebp - 0x1c], 0
// 0046c9e8  740b                 je 0x46c9f5
// 0046c9ea  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 0046c9ed  50                   push eax
// 0046c9ee  6a00                 push 0
// 0046c9f0  e8673f2300           call 0x6a095c
// 0046c9f5  8bc6                 mov eax, esi
// 0046c9f7  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0046c9fa  64890d00000000       mov dword ptr fs:[0], ecx
// 0046ca01  5f                   pop edi
// 0046ca02  5e                   pop esi
// 0046ca03  5b                   pop ebx
// 0046ca04  8be5                 mov esp, ebp
// 0046ca06  5d                   pop ebp
// 0046ca07  c20800               ret 8
// 0046ca0a  6a00                 push 0
// 0046ca0c  56                   push esi
// 0046ca0d  ff15d83e8000         call dword ptr [0x803ed8]
// 0046ca13  8bc8                 mov ecx, eax
// 0046ca15  c645fc04             mov byte ptr [ebp - 4], 4
// 0046ca19  ff15e03e8000         call dword ptr [0x803ee0]
// 0046ca1f  83ec20               sub esp, 0x20
// 0046ca22  8bcc                 mov ecx, esp
// 0046ca24  8965ec               mov dword ptr [ebp - 0x14], esp
// 0046ca27  50                   push eax
// 0046ca28  e893adfcff           call 0x4377c0
// 0046ca2d  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0046ca30  e85bf2ffff           call 0x46bc90
// 0046ca35  8d4d0c               lea ecx, [ebp + 0xc]
// 0046ca38  ff15143f8000         call dword ptr [0x803f14]
// 0046ca3e  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0046ca41  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0046ca48  85c0                 test eax, eax
// 0046ca4a  7406                 je 0x46ca52
// 0046ca4c  8b4dd8               mov ecx, dword ptr [ebp - 0x28]
// 0046ca4f  894804               mov dword ptr [eax + 4], ecx
// 0046ca52  837de400             cmp dword ptr [ebp - 0x1c], 0
// 0046ca56  740b                 je 0x46ca63
// 0046ca58  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 0046ca5b  52                   push edx
// 0046ca5c  6a00                 push 0
// 0046ca5e  e8f93e2300           call 0x6a095c
// 0046ca63  33c0                 xor eax, eax
// 0046ca65  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0046ca68  64890d00000000       mov dword ptr fs:[0], ecx
// 0046ca6f  5f                   pop edi
// 0046ca70  5e                   pop esi
// 0046ca71  5b                   pop ebx
// 0046ca72  8be5                 mov esp, ebp
// 0046ca74  5d                   pop ebp
// 0046ca75  c20800               ret 8

// from server: 80% by king_originala
// roc 2008-06 0046c920  unit: VCWorkspace::?$CComObject  size: 344 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046c920
//
// 0046c920  55                   push ebp
// 0046c921  8bec                 mov ebp, esp
// 0046c923  6aff                 push -1
// 0046c925  68133c7c00           push 0x7c3c13
// 0046c92a  64a100000000         mov eax, dword ptr fs:[0]
// 0046c930  50                   push eax
// 0046c931  64892500000000       mov dword ptr fs:[0], esp
// 0046c938  83ec1c               sub esp, 0x1c
// 0046c93b  53                   push ebx
// 0046c93c  56                   push esi
// 0046c93d  57                   push edi
// 0046c93e  8965f0               mov dword ptr [ebp - 0x10], esp
// 0046c941  e822402300           call 0x6a0968
// 0046c946  50                   push eax
// 0046c947  8d4dd8               lea ecx, [ebp - 0x28]
// 0046c94a  e813402300           call 0x6a0962
// 0046c94f  8b750c               mov esi, dword ptr [ebp + 0xc]
// 0046c952  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0046c959  56                   push esi
// 0046c95a  c645fc01             mov byte ptr [ebp - 4], 1
// 0046c95e  e86d13fbff           call 0x41dcd0
// 0046c963  8bf8                 mov edi, eax
// 0046c965  83c404               add esp, 4
// 0046c968  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c96b  85ff                 test edi, edi
// 0046c96d  0f8497000000         je 0x46ca0a
// 0046c973  ff15043f8000         call dword ptr [0x803f04]
// 0046c979  b302                 mov bl, 2
// 0046c97b  56                   push esi
// 0046c97c  8d4d08               lea ecx, [ebp + 8]
// 0046c97f  885dfc               mov byte ptr [ebp - 4], bl
// 0046c982  ff15d83e8000         call dword ptr [0x803ed8]
// 0046c988  8b00                 mov eax, dword ptr [eax]
// 0046c98a  50                   push eax
// 0046c98b  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c98e  6880ea8000           push 0x80ea80
// 0046c993  51                   push ecx
// 0046c994  c645fc03             mov byte ptr [ebp - 4], 3
// 0046c998  ff15dc3e8000         call dword ptr [0x803edc]
// 0046c99e  83c40c               add esp, 0xc
// 0046c9a1  8d4d08               lea ecx, [ebp + 8]
// 0046c9a4  885dfc               mov byte ptr [ebp - 4], bl
// 0046c9a7  ff15143f8000         call dword ptr [0x803f14]
// 0046c9ad  57                   push edi
// 0046c9ae  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c9b1  ff15e03e8000         call dword ptr [0x803ee0]
// 0046c9b7  50                   push eax
// 0046c9b8  68f8648100           push 0x8164f8
// 0046c9bd  e86ec9fbff           call 0x429330
// 0046c9c2  83c40c               add esp, 0xc
// 0046c9c5  8d4d0c               lea ecx, [ebp + 0xc]
// 0046c9c8  8bf0                 mov esi, eax
// 0046c9ca  ff15143f8000         call dword ptr [0x803f14]
// 0046c9d0  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0046c9d3  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0046c9da  85c0                 test eax, eax
// 0046c9dc  7406                 je 0x46c9e4
// 0046c9de  8b55d8               mov edx, dword ptr [ebp - 0x28]
// 0046c9e1  895004               mov dword ptr [eax + 4], edx
// 0046c9e4  837de400             cmp dword ptr [ebp - 0x1c], 0
// 0046c9e8  740b                 je 0x46c9f5
// 0046c9ea  8b45e0               mov eax, dword ptr [ebp - 0x20]
// 0046c9ed  50                   push eax
// 0046c9ee  6a00                 push 0
// 0046c9f0  e8673f2300           call 0x6a095c
// 0046c9f5  8bc6                 mov eax, esi
// 0046c9f7  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0046c9fa  64890d00000000       mov dword ptr fs:[0], ecx
// 0046ca01  5f                   pop edi
// 0046ca02  5e                   pop esi
// 0046ca03  5b                   pop ebx
// 0046ca04  8be5                 mov esp, ebp
// 0046ca06  5d                   pop ebp
// 0046ca07  c20800               ret 8
// 0046ca0a  6a00                 push 0
// 0046ca0c  56                   push esi
// 0046ca0d  ff15d83e8000         call dword ptr [0x803ed8]
// 0046ca13  8bc8                 mov ecx, eax
// 0046ca15  c645fc04             mov byte ptr [ebp - 4], 4
// 0046ca19  ff15e03e8000         call dword ptr [0x803ee0]
// 0046ca1f  83ec20               sub esp, 0x20
// 0046ca22  8bcc                 mov ecx, esp
// 0046ca24  8965ec               mov dword ptr [ebp - 0x14], esp
// 0046ca27  50                   push eax
// 0046ca28  e893adfcff           call 0x4377c0
// 0046ca2d  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0046ca30  e85bf2ffff           call 0x46bc90
// 0046ca35  8d4d0c               lea ecx, [ebp + 0xc]
// 0046ca38  ff15143f8000         call dword ptr [0x803f14]
// 0046ca3e  8b45dc               mov eax, dword ptr [ebp - 0x24]
// 0046ca41  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 0046ca48  85c0                 test eax, eax
// 0046ca4a  7406                 je 0x46ca52
// 0046ca4c  8b4dd8               mov ecx, dword ptr [ebp - 0x28]
// 0046ca4f  894804               mov dword ptr [eax + 4], ecx
// 0046ca52  837de400             cmp dword ptr [ebp - 0x1c], 0
// 0046ca56  740b                 je 0x46ca63
// 0046ca58  8b55e0               mov edx, dword ptr [ebp - 0x20]
// 0046ca5b  52                   push edx
// 0046ca5c  6a00                 push 0
// 0046ca5e  e8f93e2300           call 0x6a095c
// 0046ca63  33c0                 xor eax, eax
// 0046ca65  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0046ca68  64890d00000000       mov dword ptr fs:[0], ecx
// 0046ca6f  5f                   pop edi
// 0046ca70  5e                   pop esi
// 0046ca71  5b                   pop ebx
// 0046ca72  8be5                 mov esp, ebp
// 0046ca74  5d                   pop ebp
// 0046ca75  c20800               ret 8

extern "C" void* __cdecl getState();
void __stdcall releaseState(int, void*);
extern "C" int __cdecl checkUrl(const wchar_t*);
#include <exception>
struct Guid { unsigned long a; unsigned short b, c; unsigned char d[8]; };
extern const Guid logGuid;
int __cdecl logError(const Guid&, const char*, long);

template<class T> class CStrT
{
public:
    T* m_psz;
    CStrT();
    CStrT(const wchar_t*);
    __declspec(noinline) ~CStrT() throw() { m_psz = 0; }
    operator const T*() const throw();
    void __cdecl Format(const T*, ...);
};
extern template class __declspec(dllimport) CStrT<char>;
typedef CStrT<char> CStr;

struct State
{
    void* previous;
    State* owner;
    void* resource;
    int active;
    State(void*);
    ~State();
};
inline State::~State()
{
    if (owner)
        owner->owner = static_cast<State*>(previous);
    if (active)
        releaseState(0, resource);
}
struct String
{
    unsigned char storage[32];
    String(const char*);
    String(const String&);
    ~String();
};
struct S
{
    void navigate(String, int);
    static int __stdcall f(S*, const wchar_t*);
};
int __stdcall S::f(S* object, const wchar_t* url)
{
    State state(getState());
    try
    {
        int result = checkUrl(url);
        if (result)
        {
            CStr message;
            message.Format("Untrusted Url: %s", CStr(url));
            return logError(logGuid, message, result);
        }
        object->navigate(String(CStr(url)), 0);
        return 0;
    }
    catch (const std::exception& e)
    {
        return logError(logGuid, e.what(), 0);
    }
}
