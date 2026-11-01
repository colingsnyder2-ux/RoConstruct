// from server: 100% by auto
// roc 2009-06 0078ec50  unit: CXTPPropertyGridView  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0078ec50
//
// 0078ec50  8b442404             mov eax, dword ptr [esp + 4]
// 0078ec54  83ec10               sub esp, 0x10
// 0078ec57  53                   push ebx
// 0078ec58  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 0078ec5c  55                   push ebp
// 0078ec5d  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 0078ec61  56                   push esi
// 0078ec62  57                   push edi
// 0078ec63  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 0078ec67  c70700000000         mov dword ptr [edi], 0
// 0078ec6d  c70300000000         mov dword ptr [ebx], 0
// 0078ec73  8bf1                 mov esi, ecx
// 0078ec75  c7450000000000       mov dword ptr [ebp], 0
// 0078ec7c  c70000000000         mov dword ptr [eax], 0
// 0078ec82  8d46ac               lea eax, [esi - 0x54]
// 0078ec85  85c0                 test eax, eax
// 0078ec87  7455                 je 0x78ecde
// 0078ec89  83782000             cmp dword ptr [eax + 0x20], 0
// 0078ec8d  744f                 je 0x78ecde
// 0078ec8f  8b56cc               mov edx, dword ptr [esi - 0x34]
// 0078ec92  8d4c2410             lea ecx, [esp + 0x10]
// 0078ec96  51                   push ecx
// 0078ec97  52                   push edx
// 0078ec98  ff15f4ed8900         call dword ptr [0x89edf4]
// 0078ec9e  8d442434             lea eax, [esp + 0x34]
// 0078eca2  50                   push eax
// 0078eca3  8bce                 mov ecx, esi
// 0078eca5  e8261ffdff           call 0x760bd0
// 0078ecaa  85c0                 test eax, eax
// 0078ecac  740f                 je 0x78ecbd
// 0078ecae  5f                   pop edi
// 0078ecaf  5e                   pop esi
// 0078ecb0  5d                   pop ebp
// 0078ecb1  b857000780           mov eax, 0x80070057
// 0078ecb6  5b                   pop ebx
// 0078ecb7  83c410               add esp, 0x10
// 0078ecba  c22000               ret 0x20
// 0078ecbd  8b442410             mov eax, dword ptr [esp + 0x10]
// 0078ecc1  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 0078ecc5  8b542418             mov edx, dword ptr [esp + 0x18]
// 0078ecc9  8901                 mov dword ptr [ecx], eax
// 0078eccb  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 0078eccf  2bd0                 sub edx, eax
// 0078ecd1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0078ecd5  894d00               mov dword ptr [ebp], ecx
// 0078ecd8  2bc1                 sub eax, ecx
// 0078ecda  8913                 mov dword ptr [ebx], edx
// 0078ecdc  8907                 mov dword ptr [edi], eax
// 0078ecde  5f                   pop edi
// 0078ecdf  5e                   pop esi
// 0078ece0  5d                   pop ebp
// 0078ece1  33c0                 xor eax, eax
// 0078ece3  5b                   pop ebx
// 0078ece4  83c410               add esp, 0x10
// 0078ece7  c22000               ret 0x20
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?AccessibleLocation@CXTPPropertyGridView@@MAEJPAJ000UtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
