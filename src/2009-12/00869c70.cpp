// from server: 100% by auto
// roc 2009-12 00869c70  unit: CXTPPropertyGridView  size: 154 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00869c70
//
// 00869c70  8b442404             mov eax, dword ptr [esp + 4]
// 00869c74  83ec10               sub esp, 0x10
// 00869c77  53                   push ebx
// 00869c78  8b5c2420             mov ebx, dword ptr [esp + 0x20]
// 00869c7c  55                   push ebp
// 00869c7d  8b6c2420             mov ebp, dword ptr [esp + 0x20]
// 00869c81  56                   push esi
// 00869c82  57                   push edi
// 00869c83  8b7c2430             mov edi, dword ptr [esp + 0x30]
// 00869c87  c70700000000         mov dword ptr [edi], 0
// 00869c8d  c70300000000         mov dword ptr [ebx], 0
// 00869c93  8bf1                 mov esi, ecx
// 00869c95  c7450000000000       mov dword ptr [ebp], 0
// 00869c9c  c70000000000         mov dword ptr [eax], 0
// 00869ca2  8d46ac               lea eax, [esi - 0x54]
// 00869ca5  85c0                 test eax, eax
// 00869ca7  7455                 je 0x869cfe
// 00869ca9  83782000             cmp dword ptr [eax + 0x20], 0
// 00869cad  744f                 je 0x869cfe
// 00869caf  8b56cc               mov edx, dword ptr [esi - 0x34]
// 00869cb2  8d4c2410             lea ecx, [esp + 0x10]
// 00869cb6  51                   push ecx
// 00869cb7  52                   push edx
// 00869cb8  ff1570cc9800         call dword ptr [0x98cc70]
// 00869cbe  8d442434             lea eax, [esp + 0x34]
// 00869cc2  50                   push eax
// 00869cc3  8bce                 mov ecx, esi
// 00869cc5  e8d61cfdff           call 0x83b9a0
// 00869cca  85c0                 test eax, eax
// 00869ccc  740f                 je 0x869cdd
// 00869cce  5f                   pop edi
// 00869ccf  5e                   pop esi
// 00869cd0  5d                   pop ebp
// 00869cd1  b857000780           mov eax, 0x80070057
// 00869cd6  5b                   pop ebx
// 00869cd7  83c410               add esp, 0x10
// 00869cda  c22000               ret 0x20
// 00869cdd  8b442410             mov eax, dword ptr [esp + 0x10]
// 00869ce1  8b4c2424             mov ecx, dword ptr [esp + 0x24]
// 00869ce5  8b542418             mov edx, dword ptr [esp + 0x18]
// 00869ce9  8901                 mov dword ptr [ecx], eax
// 00869ceb  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 00869cef  2bd0                 sub edx, eax
// 00869cf1  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 00869cf5  894d00               mov dword ptr [ebp], ecx
// 00869cf8  2bc1                 sub eax, ecx
// 00869cfa  8913                 mov dword ptr [ebx], edx
// 00869cfc  8907                 mov dword ptr [edi], eax
// 00869cfe  5f                   pop edi
// 00869cff  5e                   pop esi
// 00869d00  5d                   pop ebp
// 00869d01  33c0                 xor eax, eax
// 00869d03  5b                   pop ebx
// 00869d04  83c410               add esp, 0x10
// 00869d07  c22000               ret 0x20
// library xtp-15.2.1/Source\PropertyGrid\XTPPropertyGridView.cpp (function ?AccessibleLocation@CXTPPropertyGridView@@MAEJPAJ000UtagVARIANT@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/PropertyGrid/XTPPropertyGridView.cpp
