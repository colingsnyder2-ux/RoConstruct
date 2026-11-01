// from server: 100% by auto
// roc 2009-06 0078ecf0  unit: CXTPPropertyGridView  size: 202 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078ecf0
//
// 0078ecf0  83ec1c               sub esp, 0x1c
// 0078ecf3  57                   push edi
// 0078ecf4  8b7c242c             mov edi, dword ptr [esp + 0x2c]
// 0078ecf8  894c2404             mov dword ptr [esp + 4], ecx
// 0078ecfc  85ff                 test edi, edi
// 0078ecfe  750c                 jne 0x78ed0c
// 0078ed00  b857000780           mov eax, 0x80070057
// 0078ed05  5f                   pop edi
// 0078ed06  83c41c               add esp, 0x1c
// 0078ed09  c20c00               ret 0xc
// 0078ed0c  56                   push esi
// 0078ed0d  33c0                 xor eax, eax
// 0078ed0f  8d71ac               lea esi, [ecx - 0x54]
// 0078ed12  668907               mov word ptr [edi], ax
// 0078ed15  85f6                 test esi, esi
// 0078ed17  7405                 je 0x78ed1e
// 0078ed19  394620               cmp dword ptr [esi + 0x20], eax
// 0078ed1c  750d                 jne 0x78ed2b
// 0078ed1e  5e                   pop esi
// 0078ed1f  b801000000           mov eax, 1
// 0078ed24  5f                   pop edi
// 0078ed25  83c41c               add esp, 0x1c
// 0078ed28  c20c00               ret 0xc
// 0078ed2b  53                   push ebx
// 0078ed2c  8b5c242c             mov ebx, dword ptr [esp + 0x2c]
// 0078ed30  55                   push ebp
// 0078ed31  8b6c2434             mov ebp, dword ptr [esp + 0x34]
// 0078ed35  56                   push esi
// 0078ed36  8d4c2420             lea ecx, [esp + 0x20]
// 0078ed3a  e83117feff           call 0x770470
// 0078ed3f  55                   push ebp
// 0078ed40  53                   push ebx
// 0078ed41  50                   push eax
// 0078ed42  ff15c0ed8900         call dword ptr [0x89edc0]
// 0078ed48  85c0                 test eax, eax
// 0078ed4a  750f                 jne 0x78ed5b
// 0078ed4c  5d                   pop ebp
// 0078ed4d  5b                   pop ebx
// 0078ed4e  5e                   pop esi
// 0078ed4f  b801000000           mov eax, 1
// 0078ed54  5f                   pop edi
// 0078ed55  83c41c               add esp, 0x1c
// 0078ed58  c20c00               ret 0xc
// 0078ed5b  8b442410             mov eax, dword ptr [esp + 0x10]
// 0078ed5f  b903000000           mov ecx, 3
// 0078ed64  8d542414             lea edx, [esp + 0x14]
// 0078ed68  66890f               mov word ptr [edi], cx
// 0078ed6b  c7470800000000       mov dword ptr [edi + 8], 0
// 0078ed72  8b48cc               mov ecx, dword ptr [eax - 0x34]
// 0078ed75  52                   push edx
// 0078ed76  51                   push ecx
// 0078ed77  895c241c             mov dword ptr [esp + 0x1c], ebx
// 0078ed7b  896c2420             mov dword ptr [esp + 0x20], ebp
// 0078ed7f  ff1530ee8900         call dword ptr [0x89ee30]
// 0078ed85  8b542418             mov edx, dword ptr [esp + 0x18]
// 0078ed89  8b442414             mov eax, dword ptr [esp + 0x14]
// 0078ed8d  52                   push edx
// 0078ed8e  50                   push eax
// 0078ed8f  8bce                 mov ecx, esi
// 0078ed91  e8eaecffff           call 0x78da80
// 0078ed96  85c0                 test eax, eax
// 0078ed98  7414                 je 0x78edae
// 0078ed9a  b909000000           mov ecx, 9
// 0078ed9f  66890f               mov word ptr [edi], cx
// 0078eda2  6a01                 push 1
// 0078eda4  8bc8                 mov ecx, eax
// 0078eda6  e879d10b00           call 0x84bf24
// 0078edab  894708               mov dword ptr [edi + 8], eax
// 0078edae  5d                   pop ebp
// 0078edaf  5b                   pop ebx
// 0078edb0  5e                   pop esi
// 0078edb1  33c0                 xor eax, eax
// 0078edb3  5f                   pop edi
// 0078edb4  83c41c               add esp, 0x1c
// 0078edb7  c20c00               ret 0xc
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?AccessibleHitTest@CXTPPropertyGridView@@MAEJJJPAUtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
