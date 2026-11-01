// from server: 100% by auto
// roc 2007-03 0050f2d0  unit: seg_00500000  size: 1780 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0050f2d0
//
// 0050f2d0  83ec28               sub esp, 0x28
// 0050f2d3  8b542430             mov edx, dword ptr [esp + 0x30]
// 0050f2d7  8b0a                 mov ecx, dword ptr [edx]
// 0050f2d9  8a5208               mov dl, byte ptr [edx + 8]
// 0050f2dc  33c0                 xor eax, eax
// 0050f2de  f6c202               test dl, 2
// 0050f2e1  894c2408             mov dword ptr [esp + 8], ecx
// 0050f2e5  89442404             mov dword ptr [esp + 4], eax
// 0050f2e9  0f84d1060000         je 0x50f9c0
// 0050f2ef  80fa02               cmp dl, 2
// 0050f2f2  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0050f2f6  53                   push ebx
// 0050f2f7  0fb7982e020000       movzx ebx, word ptr [eax + 0x22e]
// 0050f2fe  55                   push ebp
// 0050f2ff  56                   push esi
// 0050f300  0fb7b02c020000       movzx esi, word ptr [eax + 0x22c]
// 0050f307  57                   push edi
// 0050f308  0fb7b82a020000       movzx edi, word ptr [eax + 0x22a]
// 0050f30f  897c2430             mov dword ptr [esp + 0x30], edi
// 0050f313  8974241c             mov dword ptr [esp + 0x1c], esi
// 0050f317  895c242c             mov dword ptr [esp + 0x2c], ebx
// 0050f31b  0f851e030000         jne 0x50f63f
// 0050f321  8b542440             mov edx, dword ptr [esp + 0x40]
// 0050f325  807a0908             cmp byte ptr [edx + 9], 8
// 0050f329  0f854f010000         jne 0x50f47e
// 0050f32f  83b86801000000       cmp dword ptr [eax + 0x168], 0
// 0050f336  0f84bd000000         je 0x50f3f9
// 0050f33c  83b86c01000000       cmp dword ptr [eax + 0x16c], 0
// 0050f343  0f84b0000000         je 0x50f3f9
// 0050f349  85c9                 test ecx, ecx
// 0050f34b  8b742444             mov esi, dword ptr [esp + 0x44]
// 0050f34f  89742420             mov dword ptr [esp + 0x20], esi
// 0050f353  0f86ea020000         jbe 0x50f643
// 0050f359  894c2424             mov dword ptr [esp + 0x24], ecx
// 0050f35d  8d4900               lea ecx, [ecx]
// 0050f360  0fb60e               movzx ecx, byte ptr [esi]
// 0050f363  8ba86c010000         mov ebp, dword ptr [eax + 0x16c]
// 0050f369  0fb61429             movzx edx, byte ptr [ecx + ebp]
// 0050f36d  0fb64e01             movzx ecx, byte ptr [esi + 1]
// 0050f371  8a0c29               mov cl, byte ptr [ecx + ebp]
// 0050f374  83c601               add esi, 1
// 0050f377  83c601               add esi, 1
// 0050f37a  88542412             mov byte ptr [esp + 0x12], dl
// 0050f37e  0fb616               movzx edx, byte ptr [esi]
// 0050f381  0fb6142a             movzx edx, byte ptr [edx + ebp]
// 0050f385  88542411             mov byte ptr [esp + 0x11], dl
// 0050f389  8a542412             mov dl, byte ptr [esp + 0x12]
// 0050f38d  83c601               add esi, 1
// 0050f390  3ad1                 cmp dl, cl
// 0050f392  884c2413             mov byte ptr [esp + 0x13], cl
// 0050f396  7516                 jne 0x50f3ae
// 0050f398  3a542411             cmp dl, byte ptr [esp + 0x11]
// 0050f39c  750c                 jne 0x50f3aa
// 0050f39e  8a4eff               mov cl, byte ptr [esi - 1]
// 0050f3a1  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0050f3a5  884d00               mov byte ptr [ebp], cl
// 0050f3a8  eb38                 jmp 0x50f3e2
// 0050f3aa  8a4c2413             mov cl, byte ptr [esp + 0x13]
// 0050f3ae  0fb6542411           movzx edx, byte ptr [esp + 0x11]
// 0050f3b3  0fb6c9               movzx ecx, cl
// 0050f3b6  0fafd3               imul edx, ebx
// 0050f3b9  0faf4c241c           imul ecx, dword ptr [esp + 0x1c]
// 0050f3be  834c241401           or dword ptr [esp + 0x14], 1
// 0050f3c3  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0050f3c7  03d1                 add edx, ecx
// 0050f3c9  0fb64c2412           movzx ecx, byte ptr [esp + 0x12]
// 0050f3ce  0fafcf               imul ecx, edi
// 0050f3d1  03d1                 add edx, ecx
// 0050f3d3  8b8868010000         mov ecx, dword ptr [eax + 0x168]
// 0050f3d9  c1ea0f               shr edx, 0xf
// 0050f3dc  8a140a               mov dl, byte ptr [edx + ecx]
// 0050f3df  885500               mov byte ptr [ebp], dl
// 0050f3e2  83c501               add ebp, 1
// 0050f3e5  836c242401           sub dword ptr [esp + 0x24], 1
// 0050f3ea  896c2420             mov dword ptr [esp + 0x20], ebp
// 0050f3ee  0f856cffffff         jne 0x50f360
// 0050f3f4  e942020000           jmp 0x50f63b
// 0050f3f9  85c9                 test ecx, ecx
// 0050f3fb  8b742444             mov esi, dword ptr [esp + 0x44]
// 0050f3ff  8bee                 mov ebp, esi
// 0050f401  0f8638020000         jbe 0x50f63f
// 0050f407  894c2424             mov dword ptr [esp + 0x24], ecx
// 0050f40b  eb03                 jmp 0x50f410
// 0050f40d  8d4900               lea ecx, [ecx]
// 0050f410  0fb60e               movzx ecx, byte ptr [esi]
// 0050f413  83c601               add esi, 1
// 0050f416  0fb65601             movzx edx, byte ptr [esi + 1]
// 0050f41a  884c2411             mov byte ptr [esp + 0x11], cl
// 0050f41e  8a0e                 mov cl, byte ptr [esi]
// 0050f420  83c601               add esi, 1
// 0050f423  88542412             mov byte ptr [esp + 0x12], dl
// 0050f427  8a542411             mov dl, byte ptr [esp + 0x11]
// 0050f42b  83c601               add esi, 1
// 0050f42e  3ad1                 cmp dl, cl
// 0050f430  884c2413             mov byte ptr [esp + 0x13], cl
// 0050f434  7512                 jne 0x50f448
// 0050f436  3a542412             cmp dl, byte ptr [esp + 0x12]
// 0050f43a  7508                 jne 0x50f444
// 0050f43c  8a4eff               mov cl, byte ptr [esi - 1]
// 0050f43f  884d00               mov byte ptr [ebp], cl
// 0050f442  eb2b                 jmp 0x50f46f
// 0050f444  8a4c2413             mov cl, byte ptr [esp + 0x13]
// 0050f448  0fb6542412           movzx edx, byte ptr [esp + 0x12]
// 0050f44d  0fb6c9               movzx ecx, cl
// 0050f450  0fafd3               imul edx, ebx
// 0050f453  0faf4c241c           imul ecx, dword ptr [esp + 0x1c]
// 0050f458  834c241401           or dword ptr [esp + 0x14], 1
// 0050f45d  03d1                 add edx, ecx
// 0050f45f  0fb64c2411           movzx ecx, byte ptr [esp + 0x11]
// 0050f464  0fafcf               imul ecx, edi
// 0050f467  03d1                 add edx, ecx
// 0050f469  c1ea0f               shr edx, 0xf
// 0050f46c  885500               mov byte ptr [ebp], dl
// 0050f46f  83c501               add ebp, 1
// 0050f472  836c242401           sub dword ptr [esp + 0x24], 1
// 0050f477  7597                 jne 0x50f410
// 0050f479  e9bd010000           jmp 0x50f63b
// 0050f47e  83b87801000000       cmp dword ptr [eax + 0x178], 0
// 0050f485  0f841f010000         je 0x50f5aa
// 0050f48b  83b87401000000       cmp dword ptr [eax + 0x174], 0
// 0050f492  0f8412010000         je 0x50f5aa
// 0050f498  85c9                 test ecx, ecx
// 0050f49a  8b542444             mov edx, dword ptr [esp + 0x44]
// 0050f49e  89542420             mov dword ptr [esp + 0x20], edx
// 0050f4a2  0f8697010000         jbe 0x50f63f
// 0050f4a8  894c2428             mov dword ptr [esp + 0x28], ecx
// 0050f4ac  8d642400             lea esp, [esp]
// 0050f4b0  33c9                 xor ecx, ecx
// 0050f4b2  8a2a                 mov ch, byte ptr [edx]
// 0050f4b4  83c202               add edx, 2
// 0050f4b7  83c202               add edx, 2
// 0050f4ba  83c202               add edx, 2
// 0050f4bd  89542434             mov dword ptr [esp + 0x34], edx
// 0050f4c1  8a4afb               mov cl, byte ptr [edx - 5]
// 0050f4c4  0fb7e9               movzx ebp, cx
// 0050f4c7  33c9                 xor ecx, ecx
// 0050f4c9  8a6afc               mov ch, byte ptr [edx - 4]
// 0050f4cc  8a4afd               mov cl, byte ptr [edx - 3]
// 0050f4cf  0fb7c9               movzx ecx, cx
// 0050f4d2  894c2424             mov dword ptr [esp + 0x24], ecx
// 0050f4d6  33c9                 xor ecx, ecx
// 0050f4d8  663b6c2424           cmp bp, word ptr [esp + 0x24]
// 0050f4dd  8a6afe               mov ch, byte ptr [edx - 2]
// 0050f4e0  8a4aff               mov cl, byte ptr [edx - 1]
// 0050f4e3  0fb7f1               movzx esi, cx
// 0050f4e6  750d                 jne 0x50f4f5
// 0050f4e8  663bee               cmp bp, si
// 0050f4eb  7508                 jne 0x50f4f5
// 0050f4ed  0fb7cd               movzx ecx, bp
// 0050f4f0  e98c000000           jmp 0x50f581
// 0050f4f5  0fb75c2424           movzx ebx, word ptr [esp + 0x24]
// 0050f4fa  0fb78858010000       movzx ecx, word ptr [eax + 0x158]
// 0050f501  895c2424             mov dword ptr [esp + 0x24], ebx
// 0050f505  0fb7dd               movzx ebx, bp
// 0050f508  0fb6eb               movzx ebp, bl
// 0050f50b  d3ed                 shr ebp, cl
// 0050f50d  0fb7d6               movzx edx, si
// 0050f510  8bb078010000         mov esi, dword ptr [eax + 0x178]
// 0050f516  8b2cae               mov ebp, dword ptr [esi + ebp*4]
// 0050f519  c1eb08               shr ebx, 8
// 0050f51c  0fb76c5d00           movzx ebp, word ptr [ebp + ebx*2]
// 0050f521  8b5c2424             mov ebx, dword ptr [esp + 0x24]
// 0050f525  0fafef               imul ebp, edi
// 0050f528  0fb6fb               movzx edi, bl
// 0050f52b  d3ef                 shr edi, cl
// 0050f52d  c1eb08               shr ebx, 8
// 0050f530  8b3cbe               mov edi, dword ptr [esi + edi*4]
// 0050f533  0fb73c5f             movzx edi, word ptr [edi + ebx*2]
// 0050f537  0faf7c241c           imul edi, dword ptr [esp + 0x1c]
// 0050f53c  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 0050f540  03ef                 add ebp, edi
// 0050f542  0fb6fa               movzx edi, dl
// 0050f545  d3ef                 shr edi, cl
// 0050f547  c1ea08               shr edx, 8
// 0050f54a  8b34be               mov esi, dword ptr [esi + edi*4]
// 0050f54d  0fb71456             movzx edx, word ptr [esi + edx*2]
// 0050f551  0fafd3               imul edx, ebx
// 0050f554  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0050f558  03ea                 add ebp, edx
// 0050f55a  c1ed0f               shr ebp, 0xf
// 0050f55d  0fb7d5               movzx edx, bp
// 0050f560  0fb7d2               movzx edx, dx
// 0050f563  0fb6f2               movzx esi, dl
// 0050f566  d3ee                 shr esi, cl
// 0050f568  8b8874010000         mov ecx, dword ptr [eax + 0x174]
// 0050f56e  c1ea08               shr edx, 8
// 0050f571  834c241401           or dword ptr [esp + 0x14], 1
// 0050f576  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 0050f579  0fb70c51             movzx ecx, word ptr [ecx + edx*2]
// 0050f57d  8b542434             mov edx, dword ptr [esp + 0x34]
// 0050f581  8b742420             mov esi, dword ptr [esp + 0x20]
// 0050f585  8344242001           add dword ptr [esp + 0x20], 1
// 0050f58a  882e                 mov byte ptr [esi], ch
// 0050f58c  8b742420             mov esi, dword ptr [esp + 0x20]
// 0050f590  880e                 mov byte ptr [esi], cl
// 0050f592  b901000000           mov ecx, 1
// 0050f597  014c2420             add dword ptr [esp + 0x20], ecx
// 0050f59b  294c2428             sub dword ptr [esp + 0x28], ecx
// 0050f59f  0f850bffffff         jne 0x50f4b0
// 0050f5a5  e991000000           jmp 0x50f63b
// 0050f5aa  85c9                 test ecx, ecx
// 0050f5ac  8b542444             mov edx, dword ptr [esp + 0x44]
// 0050f5b0  8bf2                 mov esi, edx
// 0050f5b2  0f8687000000         jbe 0x50f63f
// 0050f5b8  894c2420             mov dword ptr [esp + 0x20], ecx
// 0050f5bc  8d642400             lea esp, [esp]
// 0050f5c0  33c9                 xor ecx, ecx
// 0050f5c2  8a2a                 mov ch, byte ptr [edx]
// 0050f5c4  83c202               add edx, 2
// 0050f5c7  83c202               add edx, 2
// 0050f5ca  83c202               add edx, 2
// 0050f5cd  8a4afb               mov cl, byte ptr [edx - 5]
// 0050f5d0  0fb7e9               movzx ebp, cx
// 0050f5d3  33c9                 xor ecx, ecx
// 0050f5d5  8a6afc               mov ch, byte ptr [edx - 4]
// 0050f5d8  896c2434             mov dword ptr [esp + 0x34], ebp
// 0050f5dc  8a4afd               mov cl, byte ptr [edx - 3]
// 0050f5df  0fb7c9               movzx ecx, cx
// 0050f5e2  894c2424             mov dword ptr [esp + 0x24], ecx
// 0050f5e6  33c9                 xor ecx, ecx
// 0050f5e8  663b6c2424           cmp bp, word ptr [esp + 0x24]
// 0050f5ed  8a6afe               mov ch, byte ptr [edx - 2]
// 0050f5f0  8a4aff               mov cl, byte ptr [edx - 1]
// 0050f5f3  0fb7c9               movzx ecx, cx
// 0050f5f6  894c2428             mov dword ptr [esp + 0x28], ecx
// 0050f5fa  7505                 jne 0x50f601
// 0050f5fc  663be9               cmp bp, cx
// 0050f5ff  7405                 je 0x50f606
// 0050f601  834c241401           or dword ptr [esp + 0x14], 1
// 0050f606  0fb74c2428           movzx ecx, word ptr [esp + 0x28]
// 0050f60b  0fb76c2424           movzx ebp, word ptr [esp + 0x24]
// 0050f610  0fafcb               imul ecx, ebx
// 0050f613  0faf6c241c           imul ebp, dword ptr [esp + 0x1c]
// 0050f618  03cd                 add ecx, ebp
// 0050f61a  0fb76c2434           movzx ebp, word ptr [esp + 0x34]
// 0050f61f  0fafef               imul ebp, edi
// 0050f622  03cd                 add ecx, ebp
// 0050f624  c1e90f               shr ecx, 0xf
// 0050f627  0fb7c9               movzx ecx, cx
// 0050f62a  882e                 mov byte ptr [esi], ch
// 0050f62c  83c601               add esi, 1
// 0050f62f  880e                 mov byte ptr [esi], cl
// 0050f631  83c601               add esi, 1
// 0050f634  836c242001           sub dword ptr [esp + 0x20], 1
// 0050f639  7585                 jne 0x50f5c0
// 0050f63b  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050f63f  8b742444             mov esi, dword ptr [esp + 0x44]
// 0050f643  8b542440             mov edx, dword ptr [esp + 0x40]
// 0050f647  807a0806             cmp byte ptr [edx + 8], 6
// 0050f64b  0f8528030000         jne 0x50f979
// 0050f651  807a0908             cmp byte ptr [edx + 9], 8
// 0050f655  0f853e010000         jne 0x50f799
// 0050f65b  83b86801000000       cmp dword ptr [eax + 0x168], 0
// 0050f662  0f84b8000000         je 0x50f720
// 0050f668  83b86c01000000       cmp dword ptr [eax + 0x16c], 0
// 0050f66f  0f84ab000000         je 0x50f720
// 0050f675  837c241800           cmp dword ptr [esp + 0x18], 0
// 0050f67a  8bee                 mov ebp, esi
// 0050f67c  0f86f3020000         jbe 0x50f975
// 0050f682  8b542418             mov edx, dword ptr [esp + 0x18]
// 0050f686  89542428             mov dword ptr [esp + 0x28], edx
// 0050f68a  8d9b00000000         lea ebx, [ebx]
// 0050f690  0fb616               movzx edx, byte ptr [esi]
// 0050f693  8b886c010000         mov ecx, dword ptr [eax + 0x16c]
// 0050f699  0fb6140a             movzx edx, byte ptr [edx + ecx]
// 0050f69d  83c601               add esi, 1
// 0050f6a0  88542413             mov byte ptr [esp + 0x13], dl
// 0050f6a4  0fb616               movzx edx, byte ptr [esi]
// 0050f6a7  0fb6140a             movzx edx, byte ptr [edx + ecx]
// 0050f6ab  83c601               add esi, 1
// 0050f6ae  88542411             mov byte ptr [esp + 0x11], dl
// 0050f6b2  0fb616               movzx edx, byte ptr [esi]
// 0050f6b5  0fb60c0a             movzx ecx, byte ptr [edx + ecx]
// 0050f6b9  884c2412             mov byte ptr [esp + 0x12], cl
// 0050f6bd  8a4c2413             mov cl, byte ptr [esp + 0x13]
// 0050f6c1  83c601               add esi, 1
// 0050f6c4  3a4c2411             cmp cl, byte ptr [esp + 0x11]
// 0050f6c8  7506                 jne 0x50f6d0
// 0050f6ca  3a4c2412             cmp cl, byte ptr [esp + 0x12]
// 0050f6ce  7405                 je 0x50f6d5
// 0050f6d0  834c241401           or dword ptr [esp + 0x14], 1
// 0050f6d5  0fb6542412           movzx edx, byte ptr [esp + 0x12]
// 0050f6da  0fb64c2411           movzx ecx, byte ptr [esp + 0x11]
// 0050f6df  0fafd3               imul edx, ebx
// 0050f6e2  0faf4c241c           imul ecx, dword ptr [esp + 0x1c]
// 0050f6e7  03d1                 add edx, ecx
// 0050f6e9  0fb64c2413           movzx ecx, byte ptr [esp + 0x13]
// 0050f6ee  0fafcf               imul ecx, edi
// 0050f6f1  03d1                 add edx, ecx
// 0050f6f3  8b8868010000         mov ecx, dword ptr [eax + 0x168]
// 0050f6f9  c1ea0f               shr edx, 0xf
// 0050f6fc  8a140a               mov dl, byte ptr [edx + ecx]
// 0050f6ff  885500               mov byte ptr [ebp], dl
// 0050f702  8a0e                 mov cl, byte ptr [esi]
// 0050f704  83c501               add ebp, 1
// 0050f707  884d00               mov byte ptr [ebp], cl
// 0050f70a  83c501               add ebp, 1
// 0050f70d  83c601               add esi, 1
// 0050f710  836c242801           sub dword ptr [esp + 0x28], 1
// 0050f715  0f8575ffffff         jne 0x50f690
// 0050f71b  e955020000           jmp 0x50f975
// 0050f720  85c9                 test ecx, ecx
// 0050f722  8bc6                 mov eax, esi
// 0050f724  0f864f020000         jbe 0x50f979
// 0050f72a  894c2428             mov dword ptr [esp + 0x28], ecx
// 0050f72e  8bff                 mov edi, edi
// 0050f730  8a08                 mov cl, byte ptr [eax]
// 0050f732  0fb65001             movzx edx, byte ptr [eax + 1]
// 0050f736  83c001               add eax, 1
// 0050f739  83c001               add eax, 1
// 0050f73c  88542412             mov byte ptr [esp + 0x12], dl
// 0050f740  0fb610               movzx edx, byte ptr [eax]
// 0050f743  83c001               add eax, 1
// 0050f746  3a4c2412             cmp cl, byte ptr [esp + 0x12]
// 0050f74a  884c2411             mov byte ptr [esp + 0x11], cl
// 0050f74e  88542413             mov byte ptr [esp + 0x13], dl
// 0050f752  7504                 jne 0x50f758
// 0050f754  3aca                 cmp cl, dl
// 0050f756  7405                 je 0x50f75d
// 0050f758  834c241401           or dword ptr [esp + 0x14], 1
// 0050f75d  0fb64c2413           movzx ecx, byte ptr [esp + 0x13]
// 0050f762  0fb6542412           movzx edx, byte ptr [esp + 0x12]
// 0050f767  0fafcb               imul ecx, ebx
// 0050f76a  0faf54241c           imul edx, dword ptr [esp + 0x1c]
// 0050f76f  03ca                 add ecx, edx
// 0050f771  0fb6542411           movzx edx, byte ptr [esp + 0x11]
// 0050f776  0fafd7               imul edx, edi
// 0050f779  03ca                 add ecx, edx
// 0050f77b  c1e90f               shr ecx, 0xf
// 0050f77e  880e                 mov byte ptr [esi], cl
// 0050f780  8a08                 mov cl, byte ptr [eax]
// 0050f782  83c601               add esi, 1
// 0050f785  880e                 mov byte ptr [esi], cl
// 0050f787  83c601               add esi, 1
// 0050f78a  83c001               add eax, 1
// 0050f78d  836c242801           sub dword ptr [esp + 0x28], 1
// 0050f792  759c                 jne 0x50f730
// 0050f794  e9dc010000           jmp 0x50f975
// 0050f799  83b87801000000       cmp dword ptr [eax + 0x178], 0
// 0050f7a0  0f8430010000         je 0x50f8d6
// 0050f7a6  83b87401000000       cmp dword ptr [eax + 0x174], 0
// 0050f7ad  0f8423010000         je 0x50f8d6
// 0050f7b3  837c241800           cmp dword ptr [esp + 0x18], 0
// 0050f7b8  8bce                 mov ecx, esi
// 0050f7ba  89742428             mov dword ptr [esp + 0x28], esi
// 0050f7be  0f86b1010000         jbe 0x50f975
// 0050f7c4  8b542418             mov edx, dword ptr [esp + 0x18]
// 0050f7c8  89542424             mov dword ptr [esp + 0x24], edx
// 0050f7cc  8d642400             lea esp, [esp]
// 0050f7d0  33d2                 xor edx, edx
// 0050f7d2  8a31                 mov dh, byte ptr [ecx]
// 0050f7d4  83c102               add ecx, 2
// 0050f7d7  83c102               add ecx, 2
// 0050f7da  83c102               add ecx, 2
// 0050f7dd  894c2420             mov dword ptr [esp + 0x20], ecx
// 0050f7e1  8a51fb               mov dl, byte ptr [ecx - 5]
// 0050f7e4  0fb7ea               movzx ebp, dx
// 0050f7e7  33d2                 xor edx, edx
// 0050f7e9  8a71fc               mov dh, byte ptr [ecx - 4]
// 0050f7ec  8a51fd               mov dl, byte ptr [ecx - 3]
// 0050f7ef  0fb7da               movzx ebx, dx
// 0050f7f2  33d2                 xor edx, edx
// 0050f7f4  663beb               cmp bp, bx
// 0050f7f7  8a71fe               mov dh, byte ptr [ecx - 2]
// 0050f7fa  895c2434             mov dword ptr [esp + 0x34], ebx
// 0050f7fe  8a51ff               mov dl, byte ptr [ecx - 1]
// 0050f801  0fb7d2               movzx edx, dx
// 0050f804  750d                 jne 0x50f813
// 0050f806  663bea               cmp bp, dx
// 0050f809  7508                 jne 0x50f813
// 0050f80b  0fb7d5               movzx edx, bp
// 0050f80e  e98e000000           jmp 0x50f8a1
// 0050f813  0fb75c2434           movzx ebx, word ptr [esp + 0x34]
// 0050f818  0fb78858010000       movzx ecx, word ptr [eax + 0x158]
// 0050f81f  8bb078010000         mov esi, dword ptr [eax + 0x178]
// 0050f825  895c2434             mov dword ptr [esp + 0x34], ebx
// 0050f829  0fb7dd               movzx ebx, bp
// 0050f82c  0fb6eb               movzx ebp, bl
// 0050f82f  d3ed                 shr ebp, cl
// 0050f831  c1eb08               shr ebx, 8
// 0050f834  0fb7d2               movzx edx, dx
// 0050f837  8b2cae               mov ebp, dword ptr [esi + ebp*4]
// 0050f83a  0fb76c5d00           movzx ebp, word ptr [ebp + ebx*2]
// 0050f83f  8b5c2434             mov ebx, dword ptr [esp + 0x34]
// 0050f843  0fafef               imul ebp, edi
// 0050f846  0fb6fb               movzx edi, bl
// 0050f849  d3ef                 shr edi, cl
// 0050f84b  c1eb08               shr ebx, 8
// 0050f84e  8b3cbe               mov edi, dword ptr [esi + edi*4]
// 0050f851  0fb73c5f             movzx edi, word ptr [edi + ebx*2]
// 0050f855  0faf7c241c           imul edi, dword ptr [esp + 0x1c]
// 0050f85a  03ef                 add ebp, edi
// 0050f85c  0fb6fa               movzx edi, dl
// 0050f85f  d3ef                 shr edi, cl
// 0050f861  c1ea08               shr edx, 8
// 0050f864  8b34be               mov esi, dword ptr [esi + edi*4]
// 0050f867  0fb71456             movzx edx, word ptr [esi + edx*2]
// 0050f86b  0faf54242c           imul edx, dword ptr [esp + 0x2c]
// 0050f870  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0050f874  03ea                 add ebp, edx
// 0050f876  c1ed0f               shr ebp, 0xf
// 0050f879  0fb7d5               movzx edx, bp
// 0050f87c  0fb7d2               movzx edx, dx
// 0050f87f  0fb6f2               movzx esi, dl
// 0050f882  d3ee                 shr esi, cl
// 0050f884  8b8874010000         mov ecx, dword ptr [eax + 0x174]
// 0050f88a  c1ea08               shr edx, 8
// 0050f88d  834c241401           or dword ptr [esp + 0x14], 1
// 0050f892  8b0cb1               mov ecx, dword ptr [ecx + esi*4]
// 0050f895  0fb71451             movzx edx, word ptr [ecx + edx*2]
// 0050f899  8b742428             mov esi, dword ptr [esp + 0x28]
// 0050f89d  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 0050f8a1  8836                 mov byte ptr [esi], dh
// 0050f8a3  83c601               add esi, 1
// 0050f8a6  8816                 mov byte ptr [esi], dl
// 0050f8a8  0fb611               movzx edx, byte ptr [ecx]
// 0050f8ab  83c601               add esi, 1
// 0050f8ae  8816                 mov byte ptr [esi], dl
// 0050f8b0  0fb65101             movzx edx, byte ptr [ecx + 1]
// 0050f8b4  83c101               add ecx, 1
// 0050f8b7  83c601               add esi, 1
// 0050f8ba  8816                 mov byte ptr [esi], dl
// 0050f8bc  83c601               add esi, 1
// 0050f8bf  83c101               add ecx, 1
// 0050f8c2  836c242401           sub dword ptr [esp + 0x24], 1
// 0050f8c7  89742428             mov dword ptr [esp + 0x28], esi
// 0050f8cb  0f85fffeffff         jne 0x50f7d0
// 0050f8d1  e99f000000           jmp 0x50f975
// 0050f8d6  837c241800           cmp dword ptr [esp + 0x18], 0
// 0050f8db  8bc6                 mov eax, esi
// 0050f8dd  8bce                 mov ecx, esi
// 0050f8df  0f8690000000         jbe 0x50f975
// 0050f8e5  8b542418             mov edx, dword ptr [esp + 0x18]
// 0050f8e9  89542430             mov dword ptr [esp + 0x30], edx
// 0050f8ed  8d4900               lea ecx, [ecx]
// 0050f8f0  0fb65001             movzx edx, byte ptr [eax + 1]
// 0050f8f4  8a30                 mov dh, byte ptr [eax]
// 0050f8f6  83c002               add eax, 2
// 0050f8f9  83c002               add eax, 2
// 0050f8fc  83c002               add eax, 2
// 0050f8ff  0fb7ea               movzx ebp, dx
// 0050f902  0fb650fd             movzx edx, byte ptr [eax - 3]
// 0050f906  8a70fc               mov dh, byte ptr [eax - 4]
// 0050f909  896c2434             mov dword ptr [esp + 0x34], ebp
// 0050f90d  0fb7f2               movzx esi, dx
// 0050f910  663bee               cmp bp, si
// 0050f913  0fb650ff             movzx edx, byte ptr [eax - 1]
// 0050f917  8a70fe               mov dh, byte ptr [eax - 2]
// 0050f91a  0fb7d2               movzx edx, dx
// 0050f91d  7505                 jne 0x50f924
// 0050f91f  663bea               cmp bp, dx
// 0050f922  7405                 je 0x50f929
// 0050f924  834c241401           or dword ptr [esp + 0x14], 1
// 0050f929  0fb7d2               movzx edx, dx
// 0050f92c  0fafd3               imul edx, ebx
// 0050f92f  0fb7f6               movzx esi, si
// 0050f932  0faf74241c           imul esi, dword ptr [esp + 0x1c]
// 0050f937  03d6                 add edx, esi
// 0050f939  0fb7742434           movzx esi, word ptr [esp + 0x34]
// 0050f93e  0faff7               imul esi, edi
// 0050f941  03d6                 add edx, esi
// 0050f943  c1ea0f               shr edx, 0xf
// 0050f946  0fb7d2               movzx edx, dx
// 0050f949  8831                 mov byte ptr [ecx], dh
// 0050f94b  83c101               add ecx, 1
// 0050f94e  8811                 mov byte ptr [ecx], dl
// 0050f950  0fb610               movzx edx, byte ptr [eax]
// 0050f953  83c101               add ecx, 1
// 0050f956  8811                 mov byte ptr [ecx], dl
// 0050f958  0fb65001             movzx edx, byte ptr [eax + 1]
// 0050f95c  83c001               add eax, 1
// 0050f95f  83c101               add ecx, 1
// 0050f962  8811                 mov byte ptr [ecx], dl
// 0050f964  83c101               add ecx, 1
// 0050f967  83c001               add eax, 1
// 0050f96a  836c243001           sub dword ptr [esp + 0x30], 1
// 0050f96f  0f857bffffff         jne 0x50f8f0
// 0050f975  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0050f979  8b742440             mov esi, dword ptr [esp + 0x40]
// 0050f97d  80460afe             add byte ptr [esi + 0xa], 0xfe
// 0050f981  8a4609               mov al, byte ptr [esi + 9]
// 0050f984  8a560a               mov dl, byte ptr [esi + 0xa]
// 0050f987  806608fd             and byte ptr [esi + 8], 0xfd
// 0050f98b  f6ea                 imul dl
// 0050f98d  88460b               mov byte ptr [esi + 0xb], al
// 0050f990  3c08                 cmp al, 8
// 0050f992  0fb6c0               movzx eax, al
// 0050f995  7215                 jb 0x50f9ac
// 0050f997  c1e803               shr eax, 3
// 0050f99a  0fafc1               imul eax, ecx
// 0050f99d  5f                   pop edi
// 0050f99e  894604               mov dword ptr [esi + 4], eax
// 0050f9a1  8b442410             mov eax, dword ptr [esp + 0x10]
// 0050f9a5  5e                   pop esi
// 0050f9a6  5d                   pop ebp
// 0050f9a7  5b                   pop ebx
// 0050f9a8  83c428               add esp, 0x28
// 0050f9ab  c3                   ret 
// 0050f9ac  0fafc1               imul eax, ecx
// 0050f9af  83c007               add eax, 7
// 0050f9b2  c1e803               shr eax, 3
// 0050f9b5  5f                   pop edi
// 0050f9b6  894604               mov dword ptr [esi + 4], eax
// 0050f9b9  8b442410             mov eax, dword ptr [esp + 0x10]
// 0050f9bd  5e                   pop esi
// 0050f9be  5d                   pop ebp
// 0050f9bf  5b                   pop ebx
// 0050f9c0  83c428               add esp, 0x28
// 0050f9c3  c3                   ret 
// library libpng-1.2.7/pngrtran.c (function _png_do_rgb_to_gray)

// roc-lang: c
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: libpng-1.2.7 pngrtran.c
