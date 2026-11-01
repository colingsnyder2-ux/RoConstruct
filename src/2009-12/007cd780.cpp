// from server: 100% by auto
// roc 2009-12 007cd780  unit: RBX::PartDropTool  size: 190 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007cd780
//
// 007cd780  51                   push ecx
// 007cd781  55                   push ebp
// 007cd782  57                   push edi
// 007cd783  8b7e10               mov edi, dword ptr [esi + 0x10]
// 007cd786  8b4730               mov eax, dword ptr [edi + 0x30]
// 007cd789  8b28                 mov ebp, dword ptr [eax]
// 007cd78b  3be8                 cmp ebp, eax
// 007cd78d  7509                 jne 0x7cd798
// 007cd78f  c7473000000000       mov dword ptr [edi + 0x30], 0
// 007cd796  eb05                 jmp 0x7cd79d
// 007cd798  8b4d00               mov ecx, dword ptr [ebp]
// 007cd79b  8908                 mov dword ptr [eax], ecx
// 007cd79d  8b5770               mov edx, dword ptr [edi + 0x70]
// 007cd7a0  8b02                 mov eax, dword ptr [edx]
// 007cd7a2  894500               mov dword ptr [ebp], eax
// 007cd7a5  8b4f70               mov ecx, dword ptr [edi + 0x70]
// 007cd7a8  8929                 mov dword ptr [ecx], ebp
// 007cd7aa  8a4505               mov al, byte ptr [ebp + 5]
// 007cd7ad  8a5714               mov dl, byte ptr [edi + 0x14]
// 007cd7b0  24f8                 and al, 0xf8
// 007cd7b2  80e203               and dl, 3
// 007cd7b5  0ad0                 or dl, al
// 007cd7b7  8b4508               mov eax, dword ptr [ebp + 8]
// 007cd7ba  885505               mov byte ptr [ebp + 5], dl
// 007cd7bd  85c0                 test eax, eax
// 007cd7bf  7479                 je 0x7cd83a
// 007cd7c1  f6400604             test byte ptr [eax + 6], 4
// 007cd7c5  7573                 jne 0x7cd83a
// 007cd7c7  8b4e10               mov ecx, dword ptr [esi + 0x10]
// 007cd7ca  8b91c4000000         mov edx, dword ptr [ecx + 0xc4]
// 007cd7d0  52                   push edx
// 007cd7d1  6a02                 push 2
// 007cd7d3  50                   push eax
// 007cd7d4  e877060000           call 0x7cde50
// 007cd7d9  83c40c               add esp, 0xc
// 007cd7dc  85c0                 test eax, eax
// 007cd7de  745a                 je 0x7cd83a
// 007cd7e0  8b4f40               mov ecx, dword ptr [edi + 0x40]
// 007cd7e3  53                   push ebx
// 007cd7e4  8a5e39               mov bl, byte ptr [esi + 0x39]
// 007cd7e7  c6463900             mov byte ptr [esi + 0x39], 0
// 007cd7eb  8b5744               mov edx, dword ptr [edi + 0x44]
// 007cd7ee  03d2                 add edx, edx
// 007cd7f0  895740               mov dword ptr [edi + 0x40], edx
// 007cd7f3  8b10                 mov edx, dword ptr [eax]
// 007cd7f5  894c240c             mov dword ptr [esp + 0xc], ecx
// 007cd7f9  8b4e08               mov ecx, dword ptr [esi + 8]
// 007cd7fc  8911                 mov dword ptr [ecx], edx
// 007cd7fe  8b5004               mov edx, dword ptr [eax + 4]
// 007cd801  895104               mov dword ptr [ecx + 4], edx
// 007cd804  8b4008               mov eax, dword ptr [eax + 8]
// 007cd807  894108               mov dword ptr [ecx + 8], eax
// 007cd80a  8b4608               mov eax, dword ptr [esi + 8]
// 007cd80d  83c010               add eax, 0x10
// 007cd810  8928                 mov dword ptr [eax], ebp
// 007cd812  c7400807000000       mov dword ptr [eax + 8], 7
// 007cd819  83460820             add dword ptr [esi + 8], 0x20
// 007cd81d  8b4608               mov eax, dword ptr [esi + 8]
// 007cd820  6a00                 push 0
// 007cd822  83c0e0               add eax, -0x20
// 007cd825  50                   push eax
// 007cd826  56                   push esi
// 007cd827  e8d4a2fcff           call 0x797b00
// 007cd82c  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 007cd830  83c40c               add esp, 0xc
// 007cd833  885e39               mov byte ptr [esi + 0x39], bl
// 007cd836  894f40               mov dword ptr [edi + 0x40], ecx
// 007cd839  5b                   pop ebx
// 007cd83a  5f                   pop edi
// 007cd83b  5d                   pop ebp
// 007cd83c  59                   pop ecx
// 007cd83d  c3                   ret 
// library lua-5.1.3/lgc.c (function _GCTM)

// roc-lang: c
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: lua-5.1.3 lgc.c
