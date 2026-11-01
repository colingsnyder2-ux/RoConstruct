// from server: 100% by auto
// roc 2007-03 00688e30  unit: seg_00680000  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00688e30
//
// 00688e30  8b442404             mov eax, dword ptr [esp + 4]
// 00688e34  83ec10               sub esp, 0x10
// 00688e37  53                   push ebx
// 00688e38  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00688e3c  55                   push ebp
// 00688e3d  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00688e41  56                   push esi
// 00688e42  57                   push edi
// 00688e43  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00688e47  c70700000000         mov dword ptr [edi], 0
// 00688e4d  c70300000000         mov dword ptr [ebx], 0
// 00688e53  8bf1                 mov esi, ecx
// 00688e55  c7450000000000       mov dword ptr [ebp], 0
// 00688e5c  c70000000000         mov dword ptr [eax], 0
// 00688e62  8d46ac               lea eax, [esi - 0x54]
// 00688e65  85c0                 test eax, eax
// 00688e67  7455                 je 0x688ebe
// 00688e69  83782000             cmp dword ptr [eax + 0x20], 0
// 00688e6d  744f                 je 0x688ebe
// 00688e6f  8b56cc               mov edx, dword ptr [esi - 0x34]
// 00688e72  8d4c2410             lea ecx, [esp + 0x10]
// 00688e76  51                   push ecx
// 00688e77  52                   push edx
// 00688e78  ff155ced7700         call dword ptr [0x77ed5c]
// 00688e7e  8d442434             lea eax, [esp + 0x34]
// 00688e82  50                   push eax
// 00688e83  8bce                 mov ecx, esi
// 00688e85  e826d1ffff           call 0x685fb0
// 00688e8a  85c0                 test eax, eax
// 00688e8c  740f                 je 0x688e9d
// 00688e8e  5f                   pop edi
// 00688e8f  5e                   pop esi
// 00688e90  5d                   pop ebp
// 00688e91  b857000780           mov eax, 0x80070057
// 00688e96  5b                   pop ebx
// 00688e97  83c410               add esp, 0x10
// 00688e9a  c22000               ret 0x20
// 00688e9d  8b442410             mov eax, dword ptr [esp + 0x10]
// 00688ea1  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00688ea5  8b542418             mov edx, dword ptr [esp + 0x18]
// 00688ea9  8901                 mov dword ptr [ecx], eax
// 00688eab  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00688eaf  2bd0                 sub edx, eax
// 00688eb1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00688eb5  894d00               mov dword ptr [ebp], ecx
// 00688eb8  2bc1                 sub eax, ecx
// 00688eba  8913                 mov dword ptr [ebx], edx
// 00688ebc  8907                 mov dword ptr [edi], eax
// 00688ebe  5f                   pop edi
// 00688ebf  5e                   pop esi
// 00688ec0  5d                   pop ebp
// 00688ec1  33c0                 xor eax, eax
// 00688ec3  5b                   pop ebx
// 00688ec4  83c410               add esp, 0x10
// 00688ec7  c22000               ret 0x20
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?AccessibleLocation@CXTPPropertyGridView@@MAEJPAJ000UtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
