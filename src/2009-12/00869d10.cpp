// from server: 100% by auto
// roc 2009-12 00869d10  unit: CXTPPropertyGridView  size: 202 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00869d10
//
// 00869d10  83ec1c               sub esp, 0x1c
// 00869d13  57                   push edi
// 00869d14  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 00869d18  894c2404             mov dword ptr [esp + 4], ecx
// 00869d1c  85ff                 test edi, edi
// 00869d1e  750c                 jne 0x869d2c
// 00869d20  b857000780           mov eax, 0x80070057
// 00869d25  5f                   pop edi
// 00869d26  83c41c               add esp, 0x1c
// 00869d29  c20c00               ret 0xc
// 00869d2c  56                   push esi
// 00869d2d  33c0                 xor eax, eax
// 00869d2f  8d71ac               lea esi, [ecx - 0x54]
// 00869d32  668907               mov word ptr [edi], ax
// 00869d35  85f6                 test esi, esi
// 00869d37  7405                 je 0x869d3e
// 00869d39  394620               cmp dword ptr [esi + 0x20], eax
// 00869d3c  750d                 jne 0x869d4b
// 00869d3e  5e                   pop esi
// 00869d3f  b801000000           mov eax, 1
// 00869d44  5f                   pop edi
// 00869d45  83c41c               add esp, 0x1c
// 00869d48  c20c00               ret 0xc
// 00869d4b  53                   push ebx
// 00869d4c  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 00869d50  55                   push ebp
// 00869d51  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 00869d55  56                   push esi
// 00869d56  8d4c2420             lea ecx, [esp + 0x20]
// 00869d5a  e81115feff           call 0x84b270
// 00869d5f  55                   push ebp
// 00869d60  53                   push ebx
// 00869d61  50                   push eax
// 00869d62  ff155cca9800         call dword ptr [0x98ca5c]
// 00869d68  85c0                 test eax, eax
// 00869d6a  750f                 jne 0x869d7b
// 00869d6c  5d                   pop ebp
// 00869d6d  5b                   pop ebx
// 00869d6e  5e                   pop esi
// 00869d6f  b801000000           mov eax, 1
// 00869d74  5f                   pop edi
// 00869d75  83c41c               add esp, 0x1c
// 00869d78  c20c00               ret 0xc
// 00869d7b  8b442410             mov eax, dword ptr [esp + 0x10]
// 00869d7f  b903000000           mov ecx, 3
// 00869d84  8d542414             lea edx, [esp + 0x14]
// 00869d88  66890f               mov word ptr [edi], cx
// 00869d8b  c7470800000000       mov dword ptr [edi + 8], 0
// 00869d92  8b48cc               mov ecx, dword ptr [eax - 0x34]
// 00869d95  52                   push edx
// 00869d96  51                   push ecx
// 00869d97  895c241c             mov dword ptr [esp + 0x1c], ebx
// 00869d9b  896c2420             mov dword ptr [esp + 0x20], ebp
// 00869d9f  ff1534cc9800         call dword ptr [0x98cc34]
// 00869da5  8b542418             mov edx, dword ptr [esp + 0x18]
// 00869da9  8b442414             mov eax, dword ptr [esp + 0x14]
// 00869dad  52                   push edx
// 00869dae  50                   push eax
// 00869daf  8bce                 mov ecx, esi
// 00869db1  e8daecffff           call 0x868a90
// 00869db6  85c0                 test eax, eax
// 00869db8  7414                 je 0x869dce
// 00869dba  b909000000           mov ecx, 9
// 00869dbf  66890f               mov word ptr [edi], cx
// 00869dc2  6a01                 push 1
// 00869dc4  8bc8                 mov ecx, eax
// 00869dc6  e86bc60b00           call 0x926436
// 00869dcb  894708               mov dword ptr [edi + 8], eax
// 00869dce  5d                   pop ebp
// 00869dcf  5b                   pop ebx
// 00869dd0  5e                   pop esi
// 00869dd1  33c0                 xor eax, eax
// 00869dd3  5f                   pop edi
// 00869dd4  83c41c               add esp, 0x1c
// 00869dd7  c20c00               ret 0xc
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?AccessibleHitTest@CXTPPropertyGridView@@MAEJJJPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
